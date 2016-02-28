#include "download.h"
#include <QPalette>

Download::Download(QWidget *parent) : QWidget(parent)
{
    //设置边框
    setContentsMargins(0, 0, 0, 0);
    //设置固定的宽度
    setFixedWidth(300);
    //设置背景颜色
    QPalette Dp;
    Dp.setColor(QPalette::Background, Qt::red);
    setAutoFillBackground(true);
    setPalette(Dp);

}

