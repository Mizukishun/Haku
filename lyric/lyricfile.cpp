#include "lyricfile.h"

LyricFile::LyricFile(QObject *parent)
    : QObject(parent)
{
    //添加中文支持???(在最外面的窗体中设置不更好吗？？？
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    //QTextCodec::setCodecForCStrings(QTextCodec::codeForLocale);
    QTextCodec::setCodecForLocale(codec);

    //我勒个去，测试了一晚上，结果是下面这句没写上……真是哔了doge
    loadLyricFile();

//    //测试用，新建一个QTimer对象，使得歌词随其滚动
//    testTimer = new QTimer(this);
//    //连接计时器与滚动歌词的函数
//    connect(testTimer, SIGNAL(timeout()), SLOT(scrollShow()));
//    testTimer->start();

}

//搜索歌词文件所在的路径,暂时用绝对路径代替，之后得修改
QString LyricFile::searchLyricFile()
{
    //播放的歌曲名
    //QString lyMusicName;

    /* 如果是本地歌曲的播放，该歌曲的歌词应该也是存放在同一文件夹中
     * 如果是下载的歌曲，将下载的歌词存放在存放下载歌曲的子文件夹中
     * 如果是试听歌曲，则从网络上缓存歌词到本地，从缓存文件夹中寻找歌词
     * */

}

//载入歌词文件，使其成为程序中能够处理的一个对象
void LyricFile::loadLyricFile()
{
    //暂时只用绝对路径，之后得修改为能够自动寻找到歌词文件的函数来
    //lyricFileDir  = "F:\\Music\\杀阵.lrc";

    //以所在路径的歌词文件新建一个对象？？？？(
    //QFile lyric(lyricFileDir);
    QFile lyric("F:\\Music\\杀阵.lrc");

    lyric.open(QIODevice::ReadOnly);


    //注意，这里缺少错误处理，也即如果打不开或没有歌词文件时的应对，之后得补上！！！！
//    if(!lyric.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//            //这里应该要有错误处理，之后补上！！！
//    }

    //处理.lyc歌词文件时二进制文件吗？？？
   // QDataStream lyricStream(&lyric);

    //直接将歌词文件读取到QString类型对象中，
    QString lyricStream = QString(lyric.readAll());
    //openTest = lyricStream;
    //openTest = lyricStream;

    lyricFileList = lyricStream.split("\n");

    //测试用，看二进制是否是这样转换为QString格式
//    QString testLrcStr;
//    lyricStream >> testLrcStr;

    //歌词文件不是文本文件？？暂时注释掉，用二进制的处理方式尝试下，看能不能处理歌词类型的文件
    //QTextStream lyricStream(&lyric);
    //将歌词文件的每一行（包含时间与歌词）保存都QStringList中，方便之后处理
//    while(!lyricStream.atEnd())
//    {
//        //读取歌词对象的每一行，并添加到lyricFileList中
//        QString temp = lyricStream.readLine();
//        lyricFileList.append(temp);
//    }

    /* 经过以上的处理，歌词文件就按行（包括时间与歌词）保存到lyricFileList中了，
     * 之后就对其再进行更加精细的处理，分别提取出时间与歌词，同时时间与歌词还要对应起来
     * 但这里有一个问题：那就是原来歌词文件每行都应该是只有一句歌词及其时间，不能有多句歌词
     * 在一行中！！！
     * 针对有多句歌词在同一行的歌词文件，之后再补充对其的处理
     * */

    //因为采用二进制转QString,所以暂时注释掉下面这句，换做QString做参数
    splitLyricFile(lyricFileList);
    //splitLyricFile(testLrcStr);
}


//要对每一行进行处理
void LyricFile::splitLyricFile(QStringList singleLineList)
{
    //针对每一行都分割成两部分
    //for(int i = 0; i < singleLineList.size(); ++i)

    //在歌词文件totalLyric前面和后面度添加四条空字符串，以方便显示
    for(int d = 0; d < 4; ++d)
    {
        totalLyric.append({"测试上", "测试上面"});
    }



    foreach(QString timeAndLyricString, singleLineList)
    {
        //每一行字符串（包含时间与歌词）
        //QString timeAndLyricString = singleLineList.value(i);

        //如果一行不是以[开头，就跳过这行，继续下一行的处理
//        if(timeAndLyricString.at(0) != '[')
//        {
//            continue;
//        }

        //如果一行是以[开头的，则这里可以利用QString::split()函数去掉第一个[，
        //同时之后可能还可以处理一行有多句歌词的情况
        QStringList strList = timeAndLyricString.split("[",QString::SkipEmptyParts);

        //可以处理一行有多句歌词的情况
        //for(int k = 0; k < strList.size(); ++k)
        foreach(QString lyStr, strList)
        {

            //下面这个是具体进行分割的函数,可以处理分割开来的每一句歌词及其相应的时间
            //下面的这个firstStr的格式应该是这样的“02:02.25] 后续歌词"形式，也即没有前导的[
            //QString lyStr = strList.value(k);
            twoParts(lyStr);

            //openTest += lyStr + "\n";
        }
    }

    //在歌词文件totalLyric最后面添加4条空字符串记录，以方便显示
    for(int s = 0; s < 4; ++s)
    {
        totalLyric.append({"测试下", "测试下面"});
    }
}


//将每一句歌词（包含时间与歌词）分割成两部分，并分别赋予lyricList和timeList
void LyricFile::twoParts(QString str)
{
    //对已经去掉头[的每一句歌词再以“]”为分割点，分割成{“时间”， “歌词”}的形式
    twoPartsList = str.split("]");
    //通过上面这样，twoPartsList就保存了一句歌词的两部分，分别在at(0)和at(1)中

    openTest += "\n" + twoPartsList.value(0);

    //将已经被分割的每一句歌词再次保存到另外一个QList中
    totalLyric.append(twoPartsList);
    //这样，就将整个歌词按一句一句歌词进行了分割，同时一句歌词及其时间保存在一个QStringList中，
    //而所有这些歌词又按顺序保存在了QList中,之后要处理的话，就是针对totalLyric及其中的子项QStringList

}

////随着计时器而滚动显示歌词
//void LyricFile::scrollShow()
//{

//}
