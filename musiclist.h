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

signals:
    //同时发送信号OkToPlayFinally，通知最顶层的窗体可以播放这首歌曲了
    void fromMusicListToSecFrame(SingleMusic *);

public slots:
    //接收从内层窗体发送过来的OkToPlayAudio信号，说明可以播放这首歌曲了
    void OkToPlayMusicOver(SingleMusic *);

public:
    //在这个窗体中也要维护一个唯一能够播放的音乐
    SingleMusic *tempMusicList;
};

#endif // MUSICLIST_H
