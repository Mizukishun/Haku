#include "secframe.h"

SecFrame::SecFrame(QWidget *parent)
    : QFrame(parent)
{
    //主布局
    secMainLayout = new QHBoxLayout(this);

    /******************************************************************************/
    //第一个小布局上的按钮实现
    musicListBtn = new QPushButton;
    musicListBtn->setFlat(true);
    musicListBtn->setFixedSize(50, 50);
    musicListBtn->setIcon(QPixmap(":/images/musicListIcon.png"));
    musicListBtn->setIconSize(QPixmap(":/images/musicListIcon.png").size());
    musicListBtn->setToolTip(tr("音乐列表"));

    favoriteBtn = new QPushButton;
    favoriteBtn->setFlat(true);
    favoriteBtn->setFixedSize(50, 50);
    favoriteBtn->setIcon(QPixmap(":/images/favoriteIcon.png"));
    favoriteBtn->setIconSize(QPixmap(":/images/favoriteIcon.png").size());
    favoriteBtn->setToolTip(tr("我的收藏"));

//    fmBtn = new QPushButton;
//    fmBtn->setFlat(true);
//    //fmBtn->setFixedSize(50, 50);
//    fmBtn->setIcon(QPixmap(":/images/fmBtn.png"));
//    fmBtn->setIconSize(QPixmap(":/images/fmBtn.png").size());
//    //fmBtn->setContentsMargins(0, 0, 0, 0);

    mobileBtn = new QPushButton;
    mobileBtn->setFlat(true);
    mobileBtn->setFixedSize(50, 50);
    mobileBtn->setIcon(QPixmap(":/images/mobileIcon.png"));
    mobileBtn->setIconSize(QPixmap(":/images/mobileIcon.png").size());
    mobileBtn->setToolTip(tr("手机管理"));

    downloadBtn2 = new QPushButton;
    downloadBtn2->setFlat(true);
    downloadBtn2->setIcon(QPixmap(":/images/downloadIcon.png"));
    downloadBtn2->setIconSize(QPixmap(":/images/downloadIcon.png").size());
    downloadBtn2->setFixedSize(50, 50);
    downloadBtn2->setToolTip(tr("下载"));

    moreBtn = new QPushButton;
    moreBtn->setFlat(true);
    moreBtn->setFixedSize(50, 50);
    moreBtn->setIcon(QPixmap(":/images/moreIcon.png"));
    moreBtn->setIconSize(QPixmap(":/images/moreIcon.png").size());
    moreBtn->setToolTip(tr("更多"));

    //添加上面这些按钮的事件关联，是的当点击按钮时，能够切换到相应的窗体
    //音乐列表按钮与堆栈窗体的第一个窗体管理
    connect(musicListBtn, SIGNAL(clicked()), this, SLOT(on_musicListBtn_clicked()));
    connect(favoriteBtn, SIGNAL(clicked()), this, SLOT(on_favoriteBtn_clicked()));
    connect(mobileBtn, SIGNAL(clicked()), this, SLOT(on_mobileBtn_clicked()));
    connect(downloadBtn2, SIGNAL(clicked()), this, SLOT(on_downloadBtn_clicked()));
    connect(moreBtn, SIGNAL(clicked()), this, SLOT(on_moreBtn_clicked()));


    /***************************************************************************/
    //第一个小布局的布局QVBoxLayout
    secVLayout = new QVBoxLayout;
    //secVLayout->addWidget(secList);
    secVLayout->setSpacing(0);
    secVLayout->setMargin(0);
    //secVLayout->setSizeConstraint(QLayout::SetFixedSize);
    secVLayout->addWidget(musicListBtn);
    secVLayout->addWidget(favoriteBtn);
    //secVLayout->addWidget(fmBtn);
    secVLayout->addWidget(mobileBtn);
    secVLayout->addWidget(downloadBtn2);
    secVLayout->addWidget(moreBtn);
    secVLayout->addStretch();

    /****************************************************************************/
    //创建第二个小布局的QStackedWidget
    secStack = new QStackedWidget;
    //设置固定宽度
    secStack->setFixedWidth(300);
    //设置堆栈窗口的风格
    //secStacke->setFrameStyle(QFrame::Panel);

    //创建第二个小布局的元素并添加上去
    muList = new MusicList();
    faList = new FavoriteList();
    mobileWidget = new MobileManage();
    downloadWidget = new Download();
    moreWidget = new More();
    secStack->addWidget(muList);
    secStack->addWidget(faList);
    secStack->addWidget(mobileWidget);
    secStack->addWidget(downloadWidget);
    secStack->addWidget(moreWidget);

    /******************************************************************************/
    //创建第三个小布局，也即歌词窗口那部分
    lyf = new lyFrame();

    /*****************************************************************************/
    //对主布局的完成
    secMainLayout->setMargin(0);
    secMainLayout->setSpacing(0);
    //添加第一个小布局
    secMainLayout->addLayout(secVLayout);
    //添加第二个小布局
    secMainLayout->addWidget(secStack);
    //添加第三个小布局
    secMainLayout->addWidget(lyf);


}

/*对于播放列表与收藏列表之间的切换是这样实现的：
 * 自定义了槽函数，当鼠标单击第一列中的按钮时，按钮的clicked()信号会连接上自定义的槽函数，
 * 而这个槽函数的实现内容就是令堆栈窗口重新设置当前索引，使得切换到按钮对应的那个窗口上
 */

void SecFrame::on_favoriteBtn_clicked()
{
    emit secStack->setCurrentIndex(1);
}

void SecFrame::on_musicListBtn_clicked()
{
    emit secStack->setCurrentIndex(0);
}

void SecFrame::on_mobileBtn_clicked()
{
    emit secStack->setCurrentIndex(2);
}

void SecFrame::on_downloadBtn_clicked()
{
    emit secStack->setCurrentIndex(3);
}

void SecFrame::on_moreBtn_clicked()
{
    emit secStack->setCurrentIndex(4);
}
