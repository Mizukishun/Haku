#include "secframe.h"

SecFrame::SecFrame(QWidget *parent)
    : QFrame(parent)
{
    //主布局
    secMainLayout = new QHBoxLayout(this);

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
    moreBtn->setIcon(QPixmap(":/images/moreIcon.png"));
    moreBtn->setIconSize(QPixmap(":/images/moreIcon.png").size());
    moreBtn->setToolTip(tr("更多"));

    //添加上面这些按钮的事件关联，是的当点击按钮时，能够切换到相应的窗体
    //音乐列表按钮与堆栈窗体的第一个窗体管理
//    connect(musicListBtn, SIGNAL(clicked()), secStack, SLOT(setCurrentIndex(int)));
//    connect(favoriteBtn, SIGNAL(clicked()), secStack, SLOT(setCurrentIndex(int)));

//    //创建一个QListWidget对象
//    secList = new QListWidget;
//    //将六个按钮添加到其上,但这里用了类型转换
//    secList->addItem(QListWidgetItem(*musicListBtn));
//    secList->addItem(QListWidgetItem(*favoriteBtn));
//    secList->addItem(QListWidgetItem(*fmBtn));
//    secList->addItem(QListWidgetItem(*mobileBtn));
//    secList->addItem(QListWidgetItem(*downloadBtn2));
//    secList->addItem(QListWidgetItem(*moreBtn));

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

    //创建第二个小布局的QStackedWidget
    secStack = new QStackedWidget;
    //设置堆栈窗口的风格
    //secStacke->setFrameStyle(QFrame::Panel);

    muList = new MusicList();
    faList = new FavoriteList();
    secStack->addWidget(muList);
    secStack->addWidget(faList);

//    //以下是第二小布局上的待删除元素
//    delText = new QTextEdit;
//    delSecBtn = new QPushButton;
//    delSecBtn2 = new QPushButton;
//    delLabel = new QLabel;
//    delSpinBox = new QSpinBox;
//    //将上面的元素添加到第二小布局上
//    secStack->addWidget(delText);
//    secStack->addWidget(delSecBtn);
//    secStack->addWidget(delSecBtn2);
//    secStack->addWidget(delLabel);
//    secStack->addWidget(delSpinBox);



    /**********************************************************************/
    //对主布局的完成
    //添加第一个小布局
    secMainLayout->addLayout(secVLayout);
    //添加第二个小布局
    secMainLayout->addWidget(secStack);
    secMainLayout->addSpacing(650);
    //secMainLayout->setSizeConstraint(QLayout::SetFixedSize);







}

