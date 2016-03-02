#include "musiclist.h"
#include <QPalette>
//下面是测试用
#include <QVBoxLayout>
#include "toolgroup/audiolist.h"

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

    //音乐列表中的总体布局
    QVBoxLayout *mulistLayout = new QVBoxLayout(this);
    mulistLayout->setMargin(0);
    mulistLayout->setSpacing(0);

    /**************************************************************************/
    //以下仍旧是测试用，之后可能需要通过右键点击，并关联槽函数来创建新窗体
    AudioList *firstList = new AudioList();
    mulistLayout->addWidget(firstList);
    mulistLayout->addStretch();

}

