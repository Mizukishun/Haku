#include "widget.h"


Widget::Widget(QWidget *parent, Qt::WindowFlags flags)
    : QWidget(parent, flags)
{
    //设置窗体最小的尺寸
    setMinimumSize(1000, 650);
    //(还未实现）设置窗体图标Icon  ????
    //setWindowIcon(QIcon(":images/haku_icon_50.png"));

    //设置窗体标题
    setWindowTitle(tr("Haku"));

    //设置窗体标题栏，自定义，此时可以缩放，但不能移动，所以可能需要重新实现鼠标移动事件
    //flags = Qt::CustomizeWindowHint;
    //flags |= Qt::FramelessWindowHint; //无边框，会无法移动以及缩放
    //setWindowFlags(flags);

    /***************************************************************************/
    //创建主布局及三个子布局，并设置布局
    mainLayout = new QVBoxLayout(this);
    firstLayout = new QHBoxLayout;
    secondLayout = new QHBoxLayout;
    threeLayout = new QHBoxLayout;
    mainLayout->addLayout(firstLayout);
    mainLayout->addLayout(secondLayout);
    mainLayout->addLayout(threeLayout);


    /***************************************************************************/
    //创建第一个子布局
    userImage = new QPushButton;
    userImage->setFlat(true);
    userImagePix = new QPixmap(":/images/userImage.png");
    userImage->setIcon(*userImagePix);
    userImage->setIconSize((*userImagePix).size());

    userName = new QLabel;
    userName->setText(tr("Haku520"));

    searchEdit = new QLineEdit;
    searchBtn = new QPushButton;
    searchBtn->setFlat(true);
    searchBtn->setIcon(QPixmap(":/images/searchIcon.png"));

    skinBtn = new QPushButton;
    skinBtn->setFlat(true);
    skinBtn->setIcon(QPixmap(":/images/skinIcon.png"));

    preferenceBtn = new QPushButton;
    preferenceBtn->setFlat(true);
    preferenceBtn->setIcon(QPixmap(":/images/preferenceIcon.png"));

    controlBtn = new QPushButton;
    controlBtn->setFlat(true);
    controlBtn->setIcon(QPixmap(":/images/controlIcon.png"));

    hideBtn = new QPushButton;
    hideBtn->setFlat(true);
    hideBtn->setIcon(QPixmap(":/images/hideIcon.png"));

    minimumBtn = new QPushButton;
    minimumBtn->setFlat(true);
    minimumBtn->setIcon(QPixmap(":/images/minimumIcon.png"));

    closeBtn = new QPushButton;
    closeBtn->setFlat(true);
    closeBtn->setIcon(QPixmap(":/images/closeIcon.png"));

    //将各个按钮添加到第一个子布局上
    firstLayout->addWidget(userImage);
    firstLayout->addWidget(userName);
    firstLayout->addStretch();
    firstLayout->addWidget(searchEdit);
    firstLayout->addWidget(searchBtn);
    firstLayout->addStretch();
    firstLayout->addWidget(skinBtn);
    firstLayout->addWidget(preferenceBtn);
    firstLayout->addWidget(controlBtn);
    firstLayout->addWidget(hideBtn);
    firstLayout->addWidget(minimumBtn);
    firstLayout->addWidget(closeBtn);
    firstLayout->setSpacing(0);
    firstLayout->setMargin(0);





    //测试，待会删除
    testText = new QPushButton;
    testText->setText("SecondButton");
    secondLayout->addWidget(testText);

    testBtn = new QPushButton;
    testBtn->setText(tr("TestDelete"));
    threeLayout->addWidget(testBtn);
    threeLayout->setSizeConstraint(QLayout::SetFixedSize);


}

Widget::~Widget()
{

}

