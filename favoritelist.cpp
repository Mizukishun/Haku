#include "favoritelist.h"
#include <QPalette>

FavoriteList::FavoriteList(QWidget *parent) : QWidget(parent)
{
    //设置边框
    setContentsMargins(0, 0, 0, 0);
    //设置固定宽度
    setFixedWidth(300);

    //设置窗体的背景颜色
    QPalette Fp;
    Fp.setColor(QPalette::Background, Qt::red);
    setAutoFillBackground(true);
    setPalette(Fp);

}


