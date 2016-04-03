#ifndef LYRICFILE_H
#define LYRICFILE_H

/* 这个类是用来处理具体歌词文件的，所起的作用是：
 * 载入歌词文件，使得程序能够对歌词文件进行处理；
 * 能够提取出每一句歌词；
 */


#include <QFile>
#include <QTextStream>



class LyricFile
{
    Q_OBJECT
public:
    LyricFile();


};

#endif // LYRICFILE_H
