#ifndef FAVORITELIST_H
#define FAVORITELIST_H

#include <QWidget>
#include "toolgroup/audiolist.h"
#include "toolgroup/singlemusic.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include "download/displaywidget.h"
#include "download/singledisplay.h"



class FavoriteList : public QWidget
{
    Q_OBJECT
public:
    explicit FavoriteList(QWidget *parent = 0);

    //用于关闭本窗体的所有列表
    void closeAllFavoriteList();
    //将DisplayWidget传递过来的试听音乐添加到试听列表中
    void addMusicToList(SingleMusic*);

signals:
    //发送给上层窗体的信号，通知是哪首歌曲可以播放了
    void fromFavoriteToSecFrame(SingleMusic *, bool);



public slots:
    //新建一个最喜爱歌曲列表
    void createFavoriteList();

    //接受下层传递过来的信号，并将其中的歌曲传递给上层窗体
    void OkToFavoriteOver(SingleMusic*, bool);



private:
    //总体布局
    QVBoxLayout *favoriteLayout;
    //新建列表的框架
    QFrame *favoriteListFrame;
    //新建列表框架的布局
    QVBoxLayout *favoriteListFrameLayout;


public:
    //这个窗体的唯一性标志
    bool favoriteNetID;
    //这个窗体所接受的能够播放的唯一歌曲
    SingleMusic *favoriteOnlyMusic;
    //这个窗体所接受的能够播放的唯一列表
    AudioList *favoriteOnlyList;
    //维护这个窗体所持有的歌曲列表
    QList<AudioList *> favoriteLists;
    //在favoriatelist列表中创建一个displaywidget对象，使得能够将试听的
    //音乐添加到试听列表中
    DisplayWidget *disWidget;

};

#endif // FAVORITELIST_H
