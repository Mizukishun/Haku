#ifndef DOWNLOAD_H
#define DOWNLOAD_H

/**定义这个类纯粹是为了下载歌曲，
 * 之后让displaywidget类继承这个类，从而能够使用这个类中的方法，
 * 从而进行歌曲文件的下载，当要注意对一些变量进行析构，防止内存泄漏。
 * 这个类要做到的目标有：
 * 给定一个URL，就能直接将其中的文件下载到本地某个文件中。
 * 要给出下载进度相关的值，方便制作下载进度条。
 * 先将文件下载到一个临时文件中，之后将其移动到指定文件中。
 * */


class Download
{
    Q_OBJECT
public:
    Download();
    ~Download();

public:
    //定义成公有的变量和函数，其子类可以直接继承使用？？


private:
    //注意如果是私有的话，则继承这个类的子类就不能直接这些私有的变量和函数了
};

#endif // DOWNLOAD_H
