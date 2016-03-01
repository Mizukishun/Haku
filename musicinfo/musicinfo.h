#ifndef MUSICINFO_H
#define MUSICINFO_H

/*这个MusicInfo类用于创建一首歌曲的显示信息，以及歌曲的播放功能。
 * 歌曲的播放需要重载鼠标双击事件，同时通过重载鼠标单击事件，使得
 * 在歌曲播放与未播放状态之间显示不同的视图状态：播放时，会显示歌手图片、
 * 音乐名、播放总时长，已播放时长、是否下载标识、喜爱标识、删除标识；
 * 而未播放时，则只显示音乐名、喜爱标识和删除标识。加号标识用于添加到播放列表。
 * 在这里为了暂时性地测试代码的效果，会多添加一个按钮，将歌曲添加到这个窗体中，
 * 之后得删除。
 *
 * 同时，先在这里尝试实现播放时间进度条，实现播放歌曲所需的所有功能
 */

//一首歌曲的播放需要歌曲的那些信息呢？？？（之后逐步添加吧~

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>


class MusicInfo : public QWidget
{
    Q_OBJECT
public:
    explicit MusicInfo(QWidget *parent = 0);

protected:
    //重载这个窗体的鼠标双击事件，使得其播放指定的音乐
    void mouseDoubleClickEvent(QMouseEvent *event);
    //其余鼠标事件暂时还想不到需要什么功能，暂时没有实现具体功能，但也需写出函数框架？？
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);


signals:


//下面这些槽函数该定义成private还是public呢？？？？（先暂时定义成private吧，之后再看看是否要修改
private slots:
    /*****************音乐播放相关的功能**************************/
    //播放音乐
    void playMusic();
    //暂停音乐
    void pauseMusic();
    //快进
    void fastForward();
    //后退
    void backForward();
    //直接鼠标点击控制播放的进度？？？？
    void mouseControld();



    /************************************************************/
    //添加一首歌曲
    void addMusic();
    //添加多首歌曲
    void addMusics();
    //添加歌曲文件夹
    void addMusicFile();


private:
    //加号标识
    QPushButton *AdditionBtn;





    //歌曲播放所需的信息，之后逐步添加吧！
    //一首的歌曲名
    QString musicName;
    //一首的歌曲路径
    QString musicPath;


};

#endif // MUSICINFO_H
