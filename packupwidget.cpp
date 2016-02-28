#include "packupwidget.h"

packUpWidget::packUpWidget(QWidget *parent) : QWidget(parent)
{
    //设置边框
    setContentsMargins(0, 0, 0, 0);
    //设置固定的宽度
    setFixedWidth(300);
}

