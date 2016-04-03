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
}

//搜索歌词文件所在的路径,暂时用绝对路径代替，之后得修改
QString LyricFile::searchLyricFile()
{
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
}

////把上面以QStringList为参数的注释掉，看以QString为参数的是否可以
////此时参数QString就是整个歌词文件
//void LyricFile::splitLyricFile(QString Tstr)
//{
////    //针对每一行都分割成两部分
////    for(int i = 0; i < singleLineList.size(); ++i)
////    {
////        //每一行字符串（包含时间与歌词）
////        QString timeAndLyricString = singleLineList.value(i);

////        //如果一行不是以[开头，就跳过这行，继续下一行的处理
////        if(timeAndLyricString.at(0) != '[')
////        {
////            continue;
////        }

//        //如果一行是以[开头的，则这里可以利用QString::split()函数去掉第一个[，
//        //同时之后可能还可以处理一行有多句歌词的情况

//        //整个歌词文件就是一QString,所以直接以[进行分割
//        QStringList strList = Tstr.split("[",QString::SkipEmptyParts);

//        //可以处理一行有多句歌词的情况,忽略掉第一个[前面开头的空
//        for(int k = 1; k < strList.size(); ++k)
//        {

//            //下面这个是具体进行分割的函数,可以处理分割开来的每一句歌词及其相应的时间
//            //下面的这个firstStr的格式应该是这样的“02:02.25] 后续歌词"形式，也即没有前导的[
//            QString lyStr = strList.value(k);
//            twoParts(lyStr);
//        }
////    }
//}

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
