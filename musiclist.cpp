#include "musiclist.h"
#include <QPalette>

MusicList::MusicList(QWidget *parent) : QWidget(parent)
{
    //设置边框？？？
    setContentsMargins(0, 0, 0, 0);

    //设置固定的宽度
    setFixedWidth(300);

    //设置窗体的背景颜色
    QPalette p;
    p.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    //setWindowOpacity(0.3);
    this->setPalette(p);




}

