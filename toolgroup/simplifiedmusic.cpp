#include "simplifiedmusic.h"

SimplifiedMusic::SimplifiedMusic(QWidget *parent) : QWidget(parent)
{

    createInterface();

}

void SimplifiedMusic::createInterface()
{
    openAndCloseBtn = new QPushButton;
    openAndCloseBtn->setFlat(true);
    openAndCloseBtn->setIcon(QPixmap(":/images/openListIcon.png"));


    listNameBtn = new QPushButton;
    listNameBtn->setFlat(true);
    listNameBtn->setText(tr("新建列表"));

    connect(openAndCloseBtn, SIGNAL(clicked()), this, SLOT(transformIcon()));
    connect(listNameBtn, SIGNAL(clicked()), this, SLOT(transformIcon()));

    listMenuBtn = new QPushButton;
    listMenuBtn->setFlat(true);
    listMenuBtn->setIcon(QPixmap(":/images/threeLineIcon.png"));

    listLayout = new QHBoxLayout(this);
    listLayout->setSpacing(0);
    listLayout->setMargin(0);
    listLayout->addWidget(openAndCloseBtn);
    listLayout->addWidget(listNameBtn);
    listLayout->addStretch();
    listLayout->addWidget(listMenuBtn);
}

//重载鼠标按下事件，使得当数遍按下时，箭头按钮方向发生改变，也即替换了图片显示
void SimplifiedMusic::mousePressEvent(QMouseEvent *)
{
    if(closeBtn)
    {
        openAndCloseBtn->setIcon(QPixmap(":/images/closeListIcon.png"));
        closeBtn = false;
    }
    else
    {
        openAndCloseBtn->setIcon(QPixmap(":/images/openListIcon.png"));
        closeBtn = true;
    }
    emit isPressed(true);
    //transformIcon();
}

//以下三个鼠标没事实现具体功能，但仍写出函数体框架
void SimplifiedMusic::mouseMoveEvent(QMouseEvent *)
{
}

void SimplifiedMusic::mouseReleaseEvent(QMouseEvent *)
{
}

void SimplifiedMusic::mouseDoubleClickEvent(QMouseEvent *)
{
}

//切换图标操作，也整个窗体的鼠标按下操作一样
void SimplifiedMusic::transformIcon()
{
    if(!closeBtn)
    {
        openAndCloseBtn->setIcon(QPixmap(":/images/closeListIcon.png"));
        closeBtn = true;
    }
    else
    {
        openAndCloseBtn->setIcon(QPixmap(":/images/openListIcon.png"));
        closeBtn = false;
    }
    emit isPressed(true);
}


