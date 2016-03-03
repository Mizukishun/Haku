#ifndef AUDIOLIST_H
#define AUDIOLIST_H

#include <QWidget>
#include "singlemusic.h"
#include "simplifiedmusic.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QFileDialog>
#include <QFileInfo>
#include <QMediaPlayer>
#include <QDebug>


class AudioList : public QWidget
{
    Q_OBJECT
public:
    explicit AudioList(QWidget *parent = 0);

    //关闭这个列表中的所有歌曲的播放
    void closeAllMusicInList();

    //单纯的关闭列表的功能
    void hideList();




signals:
    //发送信号，通知再上一层的窗体，可以播放这首音乐了
    void OkToPlayAudio(SingleMusic *, bool);

public slots:
    //创建一条新的“新建列表"
    void createList();
    //向窗体中添加歌曲
    void addMusic();

    //通过监视simplifiedmusic对象的鼠标按下事件，来显示或隐藏歌曲列表
    void AudioFrameHideOrShow(bool);

    //由这里控制音乐的播放与暂停
    //void playAudio();

    //监视音乐对象，如果有某首歌曲的名字发送过来，就说明该可以播放该首歌，其他的则要暂停恢复初始状态
    void OkToPlayMusic(SingleMusic *);

private:
    /************************添加歌曲按钮的框架部分*******************/
    //”添加本地歌曲“按钮
    QPushButton *addLocateMusic;
    //”添加本地歌曲文件夹"按钮
    QPushButton *addLocateMusicFile;
    //上面两按钮组合成布局
    QVBoxLayout *addLocateLayout;
    //上面所构成的框架
    QFrame *addLocateFrame;

    //装载下部分歌曲所需的框架
    QFrame *newAudioFrame;
    QVBoxLayout *newAudioLayout;

    /*************************************************************/

    //这一窗体的总体布局
    QVBoxLayout *AudioLayout;


    /************************对歌曲的处理************************************/
    //用于保存多首歌曲的路径
    QStringList musicPathS;
    //用于保存多首歌曲的名称
    QStringList musicNameS;
    //用于保存单首歌曲的路径
    QString musicPath;
    //用于保存单首歌曲的名称
    QString musicName;

    //维护一个歌曲对象列表
    QList<SingleMusic *> musicObjectList;

public:
    //维护一首选中的歌曲，若没有歌曲选中，则默认是列表中的第一首歌曲
    //如果有歌曲被选中，也是被存在这个变量中，向上层窗体继续传递，
    //以便进行歌曲的播放控制,所以也需定义成public
    SingleMusic *temp;

    //判断这个列表是展开了，还是关闭了，如果展开了，则它可以选择音乐进行播放，
    //如果没有展开，则它里面的所有歌曲都不能播放
    bool isShow;

    //唯一性值,便于上层窗体判断是哪个AudioList被激活了
    bool NetID;



};

#endif // AUDIOLIST_H
