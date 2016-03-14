#ifndef MUSICLIST_H
#define MUSICLIST_H

#include <QWidget>
#include "toolgroup/singlemusic.h"
#include "toolgroup/audiolist.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QPoint>


class MusicList : public QWidget
{
    Q_OBJECT
public:
    explicit MusicList(QWidget *parent = 0);

    //关闭所有的音乐了列表
    void closeAllMusicList();

private:
    //创建新建列表，并将其添加到窗体中，但也要维护播放的唯一性
    void createAudioList();

    //下面是尝试在音乐列表窗口创建右键菜单，但对是否应该是private有疑惑？？？？
    //创建菜单命令
    void createActions();


protected:
//    //重载上下文菜单函数
//    void contextMenuEvent(QContextMenuEvent *);

signals:
    //同时发送信号OkToPlayFinally，通知最顶层的窗体可以播放这首歌曲了
    void fromMusicListToSecFrame(SingleMusic *, bool);

public slots:
    //接收从内层窗体发送过来的OkToPlayAudio信号，说明可以播放这首歌曲了
    void OkToPlayMusicOver(SingleMusic *, bool);

    //显示右键菜单
    void showRightMenu(QPoint);

    //右键菜单的具体功能实现
    //新建列表
    void newList();
    //添加本地歌曲文件？？？
    void addLocateMusic();
    //添加本地歌曲文件夹
    void addLocateMusicFile();
    //清空列表
    void clearList();
    //删除列表
    void deleteList();
    //重命名列表
    void renameList();


private:
    //维护一个新建列表的列表
    QList<AudioList *> newlistList;
    //音乐列表中的总体布局
    QVBoxLayout *mulistLayout;
    //增添一个中介的框架，使得能够使添加的新建列表后面总是有一个addStretch()
    QFrame *mulistFrame;
    //框架的布局
    QVBoxLayout *mulistFrameLayout;

    /***********************右键菜单*****************************************/
    //音乐列表的右键菜单，定义成私有的，只能在这里窗体里被调用
    QMenu *rightMenu;
    //右键菜单中命令项
    //新建列表命令
    QAction *newListAction;
    //添加本地歌曲命令
    QAction *addLocateMusicAction;
    //添加本地歌曲文件夹命令
    QAction *addLocateMusicFileAction;
    //清空列表命令
    QAction *clearListAction;
    //删除列表命令
    QAction *deleteListAction;
    //重命名命令
    QAction *renameAction;

public:
    //在这个窗体中也要维护一个唯一能够播放的音乐
    SingleMusic *tempMusicList;
    //唯一被选中的新建列表
    AudioList *onlyNewList;

    //唯一性标识，说明是由这个窗体发起的信号
    bool musicListNetID;
};

#endif // MUSICLIST_H
