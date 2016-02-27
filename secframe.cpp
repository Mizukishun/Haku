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

    favoriteBtn = new QPushButton;
    favoriteBtn->setFlat(true);
    favoriteBtn->setFixedSize(50, 50);
    favoriteBtn->setIcon(QPixmap(":/images/miku.jpg"));
    favoriteBtn->setIconSize(QPixmap(":/images/miku.jpg").size());

    fmBtn = new QPushButton;
    fmBtn->setFlat(true);
    //fmBtn->setFixedSize(50, 50);
    fmBtn->setIcon(QPixmap(":/images/fmBtn.png"));
    //fmBtn->setIconSize(QPixmap(":/images/fmBtn.png").size());
    //fmBtn->setContentsMargins(0, 0, 0, 0);

    mobileBtn = new QPushButton;
    mobileBtn->setFlat(true);

    downloadBtn2 = new QPushButton;
    downloadBtn2->setFlat(true);
    downloadBtn2->setIcon(QPixmap(":/images/downloadIcon.png"));
    downloadBtn2->setIconSize(QPixmap(":/images/downloadIcon.png").size());
    downloadBtn2->setFixedSize(50, 50);

    moreBtn = new QPushButton;
    moreBtn->setFlat(true);

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
    secVLayout->addWidget(fmBtn);
    secVLayout->addWidget(mobileBtn);
    secVLayout->addWidget(downloadBtn2);
    secVLayout->addWidget(moreBtn);
    secVLayout->addStretch();

    //创建第二个小布局的QStackedWidget
    secStack = new QStackedWidget;
    //设置堆栈窗口的风格
    //secStacke->setFrameStyle(QFrame::Panel);

    //以下是第二小布局上的待删除元素
    delText = new QTextEdit;
    delSecBtn = new QPushButton;
    delSecBtn2 = new QPushButton;
    delLabel = new QLabel;
    delSpinBox = new QSpinBox;
    //将上面的元素添加到第二小布局上
    secStack->addWidget(delText);
    secStack->addWidget(delSecBtn);
    secStack->addWidget(delSecBtn2);
    secStack->addWidget(delLabel);
    secStack->addWidget(delSpinBox);



    /**********************************************************************/
    //对主布局的完成
    //添加第一个小布局
    secMainLayout->addLayout(secVLayout);
    //添加第二个小布局
    secMainLayout->addWidget(secStack);
    secMainLayout->addSpacing(650);






}

