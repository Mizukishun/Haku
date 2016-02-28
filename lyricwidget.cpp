#include "lyricwidget.h"
#include <QPalette>


LyricWidget::LyricWidget(QWidget *parent) : QWidget(parent)
{
    //先暂时设置下填充颜色，之后可能得删除
    QPalette Lyp;
    Lyp.setColor(QPalette::Background, Qt::cyan);
    setAutoFillBackground(true);
    setPalette(Lyp);
    //设置边框
    //setContentsMargins(0, 0, 0, 0);


}

