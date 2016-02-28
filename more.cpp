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
    Mop.setColor(QPalette::Background, Qt::black);
    setAutoFillBackground(true);
    setPalette(Mop);

}

