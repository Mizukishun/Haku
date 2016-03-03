#ifndef MUSICLIST_H
#define MUSICLIST_H

#include <QWidget>
#include "toolgroup/singlemusic.h"
#include "toolgroup/audiolist.h"


class MusicList : public QWidget
{
    Q_OBJECT
public:
    explicit MusicList(QWidget *parent = 0);

private:
    //创建新建列表，并将其添加到窗体中，但也要维护播放的唯一性
    void createAudioList();

signals:
    //同时发送信号OkToPlayFinally，通知最顶层的窗体可以播放这首歌曲了
    void fromMusicListToSecFrame(SingleMusic *, bool);

public slots:
    //接收从内层窗体发送过来的OkToPlayAudio信号，说明可以播放这首歌曲了
    void OkToPlayMusicOver(SingleMusic *, bool);

private:
    //维护一个新建列表的列表
    QList<AudioList *> newlistList;
    //音乐列表中的总体布局
    QVBoxLayout *mulistLayout;
public:
    //在这个窗体中也要维护一个唯一能够播放的音乐
    SingleMusic *tempMusicList;
    //唯一被选中的新建列表
    AudioList *onlyNewList;

    //唯一性标识，说明是由这个窗体发起的信号
    bool musicListNetID;
};

#endif // MUSICLIST_H
