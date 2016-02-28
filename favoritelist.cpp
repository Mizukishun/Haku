#include "favoritelist.h"
#include <QPalette>
#include "toolgroup/selfgroup.h"

FavoriteList::FavoriteList(QWidget *parent) : QWidget(parent)
{
    //设置边框
    setContentsMargins(0, 0, 0, 0);
    //设置固定宽度
    setFixedWidth(300);

    //设置窗体的背景颜色
    QPalette Fp;
    Fp.setColor(QPalette::Background, Qt::green);
    setAutoFillBackground(true);
    setPalette(Fp);

    QVBoxLayout *favoriteLayout = new QVBoxLayout(this);
    favoriteLayout->setMargin(0);
    favoriteLayout->setSpacing(0);

    SelfGroup *faTestWidget = new SelfGroup();
    SelfGroup *faTestWidget2 = new SelfGroup();
    favoriteLayout->addWidget(faTestWidget);
    favoriteLayout->addWidget(faTestWidget2);
    favoriteLayout->addStretch();

}


