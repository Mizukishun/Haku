#ifndef SECFRAME_H
#define SECFRAME_H

/* 这个类用于完成第二个子布局的创建，之后只要在主窗体Widget中加入#include "secframe.h"以及
 * secondLayout->addWidget(secFrame)这样的语句应该就能够完成第二个子布局的添加。
 * 这个子布局整体上是一个QHBoxLayou,分为三个小布局，其中第一个小布局用QListWidget填充，
 * 第二个小布局用QStackWidget填充，而第三个小布局暂时用addSpacing(650)填充，之后得根据
 * 歌词那部分的设置进行补充。
 */

#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QSpinBox>
#include "musiclist.h"
#include "favoritelist.h"
#include "mobilemanage.h"
#include "download.h"
#include "more.h"
#include "lyframe.h"
#include "packupwidget.h"
#include "toolgroup/singlemusic.h"
#include "toolgroup/singlemusic.h"
#include "download/displaywidget.h"


class SecFrame : public QFrame
{
    Q_OBJECT
public:
    SecFrame(QWidget *parent = 0);

    //整体布局
    QHBoxLayout *secMainLayout;
    //第一个小布局上的布局
    QVBoxLayout *secVLayout;
    //第二个小布局上的窗体
    QStackedWidget *secStack;
    //第三个小布局上的布局及窗体
    //QHBoxLayout *lyLayout;
    //LyricWidget *lyWidget;
    //lyFrame *lyf;



    //第一个小布局上的六个按钮
    //音乐列表按钮
    QPushButton *musicListBtn;
    //收藏按钮
    QPushButton *favoriteBtn;
    //音乐电台按钮
    //QPushButton *fmBtn;
    //手机管理按钮
    QPushButton *mobileBtn;
    //下载按钮2（区别主窗体中第三个子布局上的下载按钮)
    QPushButton *downloadBtn2;
    //更多按钮
    QPushButton *moreBtn;
    //收起按钮
    QPushButton *packUpBtn;


    /**************************************************************/
    //第二个小布局上的各个列表窗体
    MusicList *muList;
    FavoriteList *faList;
    MobileManage *mobileWidget;
    Download *downloadWidget;
    More *moreWidget;
    packUpWidget *puWidget;
    /**************************************************************/
    //第三个小布局上的元素
    DisplayWidget *downloadDisplay;

signals:
    //通知最顶层窗体，可以对这首歌曲进行播放控制了
    void SendToTop(SingleMusic *);
    //通知顶层窗体，关闭此前正在播放的音乐
    void closePrevMusic();

    //通知顶层窗体，使得播放试听音乐时，一开始就能让播放按钮和进度条反映出歌曲正在播放
    //void changeBtnIcon(bool);

    //以下是尝试对按钮点击事件的重载，希望能够实现切换不同的窗体(待删除
private slots:
    void on_favoriteBtn_clicked();
    void on_musicListBtn_clicked();
    void on_mobileBtn_clicked();
    void on_downloadBtn_clicked();
    void on_moreBtn_clicked();
    void on_packUpBtn_clicked();

    //接收从六个小窗体中传递过来的可以播放的信号Ok()，通知最顶层窗体可以播放这首歌曲了
    //但要注意：要在这里控制每次只能播放一首歌曲，每个不同小窗体传递过来的Ok信号都会触发
    //一首歌曲可以播放，所以要在这里控制住，使得每传递过来一个信号，就只播放这一首歌曲，而
    //完全关闭其它歌曲的播放
    void OkSendToTop(SingleMusic *, bool);

    //专门用来接收搜索结果显示时的信号，此时要讲搜索结果显示出来
    void okToShowDownload(bool);

    //将displaywidget中被单击添加按钮的歌曲添加到favoritelist中的“试听音乐”列表中
    void addToFavoriteList(SingleMusic*);
private:
    //判断是从试听界面传递过来的歌曲，还是从本地音乐列表中传递过来的音乐
    void whichInterface();

public:
    //显示或隐藏空窗体及搜索结果显示窗体
    void closeDisplayWidget();
public:
    //只能播放这首歌曲
    SingleMusic *OnlyMusic;
    //用来确定是否要显示搜索结果,默认是不显示，只有当有搜索了才显示
    bool okToShowDownloadBool = false;
    //用来确定是否显示空窗体，默认是显示的
    bool okToShowEmptyWidget = true;
    //一个空的窗体，主要是为了在隐藏第三个小布局时不会使得第一、二个小布局跑到中间去
    QWidget *emptyWidget;
    //空窗体的布局
    QHBoxLayout *emptyLayout;


};

#endif // SECFRAME_H
