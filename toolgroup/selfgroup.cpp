#include "selfgroup.h"
#include <QSizePolicy>

SelfGroup::SelfGroup(QWidget *parent) : QWidget(parent)
{
    //设置整个窗体的背景颜色
    QPalette sGPalette;
    sGPalette.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(sGPalette);

    //开头那横杠的元素及布局
//    arrow = new QPushButton;
//    arrow->setFlat(true);
//    arrow->setText(tr("> "));
    groupName = new QPushButton;
    groupName->setFlat(true);
    //分组名在之后要用%1.arg()这样的形式进行重新设置
    groupName->setText(tr("%1新建列表").arg(arrowString));
    //设置这个按钮的最小宽度
    //groupName->setMinimumWidth(250);

    //点击上面两个按钮中的任何一个，都会触发arrowChange()槽事件
    //connect(arrow, SIGNAL(clicked()), this, SLOT(arrowChange()));
    connect(groupName, SIGNAL(clicked()), this, SLOT(arrowChange()));

    threeLine = new QPushButton;
    threeLine->setFlat(true);
    //这个按钮的图标在之后也要重新设置
    threeLine->setIcon(QPixmap(":/images/playQueueIcon.png"));
    //threeLine->setIconSize(QPixmap(":/images/playQueueIcon.png").size());

    startLayout = new QHBoxLayout;
    startLayout->setMargin(0);
    startLayout->setSpacing(0);
    //startLayout->addWidget(arrow);
    startLayout->addWidget(groupName);
    //startLayout->addStretch();
    startLayout->addWidget(threeLine);

    //初始的窗体及其中元素布局
    initWidget = new QWidget;

    newMusic = new QPushButton;
    newMusic->setFlat(true);
    newMusic->setText(tr("+ 添加本地歌曲"));
    newMusicFile = new QPushButton;
    newMusicFile->setFlat(true);
    newMusicFile->setText(tr("+ 添加本地歌曲文件夹"));

    //为了使得按钮显示在中央，故多加了一层布局
    QHBoxLayout *initLayout1 = new QHBoxLayout();
    initLayout1->addStretch();
    initLayout1->addWidget(newMusic);
    initLayout1->addStretch();
    QHBoxLayout *initLayout2 = new QHBoxLayout();
    initLayout2->addStretch();
    initLayout2->addWidget(newMusicFile);
    initLayout2->addStretch();

    initLayout = new QVBoxLayout(initWidget);
    initLayout->addLayout(initLayout1);
    initLayout->addLayout(initLayout2);

    //果然还是可以隐藏的
    initWidget->hide();

    //整体窗体的布局
    selfGroupLayout = new QVBoxLayout(this);
    selfGroupLayout->setSpacing(0);
    selfGroupLayout->setMargin(0);
    selfGroupLayout->addLayout(startLayout);
    selfGroupLayout->addWidget(initWidget);
    //selfGroupLayout->addStretch();

};

//定义槽函数arrowChange(),这里之后还需添加隐藏/显示歌曲列表的功能
//所以后面害的继续补充这个函数！！！！
void SelfGroup::arrowChange()
{
    if(arrowString == "> ")
    {
        arrowString = "v ";
        groupName->setText(tr("%1新建列表").arg(arrowString));
    }
    else
    {
        arrowString = "> ";
        groupName->setText(tr("%1新建列表").arg(arrowString));
    }


//    if(arrow->text() == "> ")
//        arrow->setText(tr("v "));
//    else
//        arrow->setText(tr("> "));

    //测试用，之后得删除！
    if(initWidget->isHidden())
        initWidget->show();
    else
        initWidget->hide();
}

