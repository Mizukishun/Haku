#include "more.h"
#include <QPalette>

More::More(QWidget *parent) : QWidget(parent)
{
    //设置边框
    setContentsMargins(0, 0, 0, 0);
    //设置固定的宽度
    setFixedWidth(300);
    //设置背景颜色
    QPalette Mop;
    Mop.setColor(QPalette::Background, Qt::green);
    setAutoFillBackground(true);
    setPalette(Mop);

    createInterface();

}

//创建这个小窗体的布局界面
void More::createInterface()
{
    //主布局
    mainLayout = new QVBoxLayout(this);

    //启动酷狗音乐的按钮
    openKugouBtn = new QPushButton;
    openKugouBtn->setText(tr("酷狗音乐"));
    //关联启动酷狗音乐的函数
    connect(openKugouBtn, SIGNAL(clicked()), this, SLOT(openKugou()));


    //将按钮添加到布局中
    mainLayout->addWidget(openKugouBtn);
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
