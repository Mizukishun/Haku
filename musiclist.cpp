#include "musiclist.h"
#include <QPalette>
//下面是测试用
#include <QVBoxLayout>
#include "toolgroup/selfgroup.h"
//#include "toolgroup/toolgroup.h"

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

    /**************************************************************************/
    //以下仍旧是测试用，之后可能需要通过右键点击，并关联槽函数来创建新窗体

    //创建并添加selfgroup这个窗体
    SelfGroup *mLSelfWidget = new SelfGroup();
    SelfGroup *mLSelfWidget2 = new SelfGroup();
    //音乐列表中的总体布局
    QVBoxLayout *mulistLayout = new QVBoxLayout(this);
    mulistLayout->setMargin(0);
    mulistLayout->setSpacing(0);
    //将两个自建窗体添加到音乐列表中
    mulistLayout->addWidget(mLSelfWidget);
    mulistLayout->addWidget(mLSelfWidget2);
    mulistLayout->addStretch();

//    //下面是测试用
//    ToolGroup *test1 = new ToolGroup();
//    QVBoxLayout *testly = new QVBoxLayout(this);
//    testly->setMargin(0);
//    testly->setSpacing(0);
//    testly->addWidget(test1);




}

