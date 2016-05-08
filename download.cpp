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
    Dp.setColor(QPalette::Background, QColor(218, 230, 241, 100));
    setWindowOpacity(1);
    setAutoFillBackground(true);
    setPalette(Dp);

    //创建界面布局
    createInterface();

}

//创建下载窗体的界面布局
void Download::createInterface()
{



}

