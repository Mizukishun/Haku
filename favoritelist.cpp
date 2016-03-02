#include "favoritelist.h"
#include <QPalette>
#include "toolgroup/audiolist.h"

FavoriteList::FavoriteList(QWidget *parent) : QWidget(parent)
{
    //设置边框
    setContentsMargins(0, 0, 0, 0);
    //设置固定宽度
    setFixedWidth(300);

    //设置窗体的背景颜色
    QPalette Fp;
    Fp.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(Fp);

    QVBoxLayout *favoriteLayout = new QVBoxLayout(this);
    favoriteLayout->setMargin(0);
    favoriteLayout->setSpacing(0);

    AudioList *newList = new AudioList();
    favoriteLayout->addWidget(newList);
    AudioList *secondList = new AudioList();
    favoriteLayout->addWidget(secondList);
    favoriteLayout->addStretch();

}


