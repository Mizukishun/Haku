#include "download.h"
#include <QPalette>

//测试用
#include "toolgroup/singlemusic.h"
#include "toolgroup/simplifiedmusic.h"

Download::Download(QWidget *parent) : QWidget(parent)
{
    //设置边框
    setContentsMargins(0, 0, 0, 0);
    //设置固定的宽度
    setFixedWidth(300);
    //设置背景颜色
    QPalette Dp;
    Dp.setColor(QPalette::Background, Qt::white);
    setWindowOpacity(1);
    setAutoFillBackground(true);
    setPalette(Dp);

    SimplifiedMusic *defaultList = new SimplifiedMusic();

    SingleMusic *singleWidget = new SingleMusic();

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(defaultList);
    mainLayout->addWidget(singleWidget);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);


}

