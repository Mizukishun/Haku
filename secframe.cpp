#include "secframe.h"

SecFrame::SecFrame(QWidget *parent)
    : QFrame(parent)
{
    //第一个小布局上的按钮实现
    musicListBtn = new QPushButton;
    musicListBtn->setFlat(true);
    favoriteBtn = new QPushButton;
    favoriteBtn->setFlat(true);
    fmBtn = new QPushButton;
    favoriteBtn->setFlat(true);
    mobileBtn = new QPushButton;
    mobileBtn->setFlat(true);
    downloadBtn2 = new QPushButton;
    downloadBtn2->setFlat(true);
    moreBtn = new QPushButton;
    moreBtn->setFlat(true);

    //创建一个QListWidget对象
    secList = new QListWidget;
    //将六个按钮添加到其上,但这里用了类型转换
    secList->addItem(QListWidgetItem(musicListBtn));
    secList->addItem



}

