#include "mobilemanage.h"
#include <QPalette>

MobileManage::MobileManage(QWidget *parent) : QWidget(parent)
{
    //设置边框
    setContentsMargins(0, 0, 0, 0);
    //设置固定的匡杜
    setFixedWidth(300);
    //设置背景颜色
    QPalette Mp;
    Mp.setColor(QPalette::Background, Qt::green);
    setAutoFillBackground(true);
    setPalette(Mp);



}

