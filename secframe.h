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
    lyFrame *lyf;



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

signals:
    //通知最顶层窗体，可以对这首歌曲进行播放控制了
    void SendToTop(SingleMusic *);

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
    void OkSendToTop(SingleMusic *);
public:
    //只能播放这首歌曲
    SingleMusic *OnlyMusic;


};

#endif // SECFRAME_H
