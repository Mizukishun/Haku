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


class SecFrame : public QFrame
{
    Q_OBJECT
public:
    SecFrame(QWidget *parent = 0);

    //整体布局
    QHBoxLayout *secMainLayout;
    //第一个小布局上的窗体
    QListWidget *secList;
    //第二个小布局上的窗体
    QStackedWidget *secStack;

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

    //第一个小布局上布局
    QVBoxLayout *secVLayout;

    /**************************************************************/
    //第二个小布局上的各个列表窗体
    MusicList *muList;
    FavoriteList *faList;


    //以下是尝试对按钮点击事件的重载，希望能够实现切换不同的窗体(待删除


//    //以下只是对第二个小布局上的部件的模拟，之后得用相应的“*****.h"这样的补上(之后得删！！！）
//    QTextEdit *delText;
//    QPushButton *delSecBtn;
//    QPushButton *delSecBtn2;
//    QLabel *delLabel;
//    QSpinBox *delSpinBox;

};

#endif // SECFRAME_H
