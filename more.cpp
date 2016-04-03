#include "more.h"
#include <QPalette>

More::More(QWidget *parent) : QWidget(parent)
{
    //设置边框
    setContentsMargins(0, 0, 0, 0);
    //设置固定的宽度
    setFixedWidth(300);
    //设置背景颜色为半透明的
    QPalette Mop;
    Mop.setColor(QPalette::Background, QColor(218, 230, 241, 100));
    setAutoFillBackground(true);
    setPalette(Mop);

    createInterface();

}

//创建这个小窗体的布局界面
void More::createInterface()
{
    //主布局
    mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(20);
    mainLayout->setMargin(20);

    //启动酷狗音乐的按钮
    openKugouBtn = new QPushButton;
    //openKugouBtn->setText(tr("酷狗音乐"));
    openKugouBtn->setFlat(true);
    openKugouBtn->setIcon(QPixmap(":/images/kugou2.png"));
    openKugouBtn->setIconSize(QPixmap(":/images/kugou2.png").size());
    openKugouBtn->setToolTip(tr("打开酷狗音乐"));
    //关联启动酷狗音乐的函数
    connect(openKugouBtn, SIGNAL(clicked()), this, SLOT(openKugou()));

    //用默认浏览器打开这个项目的GitHub页面
    openMyGitHubBtn = new QPushButton;
    //openMyGitHubBtn->setText(tr("源代码"));
    openMyGitHubBtn->setFlat(true);
    openMyGitHubBtn->setIcon(QPixmap(":/images/github2.png"));
    openMyGitHubBtn->setIconSize(QPixmap(":/images/github2.png").size());
    openMyGitHubBtn->setToolTip(tr("打开GitHub上的Haku源代码"));
    connect(openMyGitHubBtn, SIGNAL(clicked()), this, SLOT(openMyGitHub()));

    //将上面两个按钮添加到第一行小布局中
    firstLineLayout = new QHBoxLayout;
    firstLineLayout->setMargin(0);
    firstLineLayout->setSpacing(0);
    firstLineLayout->addStretch();
    firstLineLayout->addWidget(openKugouBtn);
    firstLineLayout->addStretch();
    firstLineLayout->addWidget(openMyGitHubBtn);
    firstLineLayout->addStretch();

    //将小布局添加到主布局中
    mainLayout->addLayout(firstLineLayout);
    mainLayout->addStretch();
}

//启动酷狗音乐程序
void More::openKugou()
{
    //注意这里只针对现在我自己的电脑，因为不同人的酷狗安装在不同的路径下
    //所以之后得补充一个能够自动寻找KuGou.exe路径的函数

    //新建一个进程
    kugouProcess = new QProcess();

    //这里直接用自己电脑的KuGou.exe的路径，之后得修改
    kugouProcess->start("D:\\Programs\\KuGou2012\\KuGou.exe");
    //因为我的电脑是windows的，所以是\\

    //注意，这里还没有错误处理，所以之后得补充一个错误处理的东东
}

//启动默认浏览器打开Haku项目的GitHub页面
void More::openMyGitHub()
{
    QDesktopServices::openUrl(QUrl("https://github.com/DchunWang/Haku"));
}
