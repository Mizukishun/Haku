#include "musiclist.h"
#include <QPalette>
//下面是测试用
#include <QVBoxLayout>
#include "toolgroup/toolgroup.h"

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
    this->setPalette(p);

    //下面是测试用
    ToolGroup *test1 = new ToolGroup();
    QVBoxLayout *testly = new QVBoxLayout(this);
    testly->setMargin(0);
    testly->setSpacing(0);
    testly->addWidget(test1);




}

