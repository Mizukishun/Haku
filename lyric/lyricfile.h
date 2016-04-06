#ifndef LYRICFILE_H
#define LYRICFILE_H

/* 这个类是用来处理具体歌词文件的，所起的作用是：
 * 载入歌词文件，使其成为程序中的一个可处理对象；
 * 能够提取出每一句歌词；
 */

//尽量将每一项功能都写成一个函数，方便后面程序的调用

//问题1：没有自动寻找到歌词文件的函数，暂时只是用绝对路径做测试用，之后得补上相应的功能函数！！！！
//问题2：针对一行有多句歌词的文件，暂时还没有处理，所以之后得补上！！！

#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QTextCodec>

//测试用的计时器
#include <QTimer>



class LyricFile : public QObject
{
    Q_OBJECT
public:
    LyricFile(QObject *parent = 0);

    //搜索歌词文件所在的路径
    QString searchLyricFile();
    //载入歌词文件，使歌词文件成为程序中的一个可处理对象
    void loadLyricFile();
    //将歌词文件的每一行（包含时间与歌词）提取出来后，将时间与歌词分离
    //也即将lyricFileList的每一QString拆分开来
    void splitLyricFile(QStringList);
    //void splitLyricFile(QString);

    //将一行字符串分割成两个子字符串（分别为时间与歌词的字符串),并分别赋予lyricList和timeList
    void twoParts(QString);

    //将字符串形式的时间，转换为数值形式的时间值，方便比较
    qint64 QStringToqint64(QString);

    //判断QString中的是否为纯数字型
    bool IsD(QString);

//public slots:
//    //测试用，随着计时器而滚动歌词的显示
//    void scrollShow();

public:
    //歌词文件(这里有很大疑问，是不是该指针？还是不要*
    //QFile *lyric;

    //歌词文件所在的路径名（QString形式）
    QString lyricFileDir;

    //歌词文件中的每一行（包括时间与歌词）
    QStringList lyricFileList;

    //{"02:01.30", "歌词"}形式的QStringList
    QStringList twoPartsList;

    //将每一句已经分割成两部分的歌词保存到QList中,也即totalLyric的每一index都是一句歌词及其时间的QStringList
    QList<QStringList> totalLyric;

    //测试用，观察是哪部分出问题了
    QString openTest /*= "The First"*/;

    //单纯保存时间那部分，以方便转换为具体的时间值
    QList<QString> timePartList;
    //保存数值形式的时间值
    QList<qint64> lyricTimeList;

//private:
//    //测试用的计时器，看是否能够实现每隔一定时间滚动显示歌词
//    QTimer *testTimer;

//    //具体歌词的每一行（只含歌词）
//    QStringList lyricList;
//    //每一行歌词所对应的时间列表（字符串形式
//    QStringList timeList;




};

#endif // LYRICFILE_H
