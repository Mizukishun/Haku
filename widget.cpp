#include "widget.h"


Widget::Widget(QWidget *parent, Qt::WindowFlags flags)
    : QWidget(parent, flags)
{
    //设置窗体最小的尺寸
    setMinimumSize(1000, 650);
    //设置窗体图标
    setWindowIcon(QPixmap(":/images/MAKI.jpg"));

    //设置窗体标题
    setWindowTitle(tr("Haku"));

    //设置窗体标题栏，自定义，此时可以缩放，但不能移动，所以可能需要重新实现鼠标移动事件
    flags = Qt::CustomizeWindowHint;
    //flags |= Qt::FramelessWindowHint; //无边框，会无法移动以及缩放
    setWindowFlags(flags);

    /***************************************************************************/
    //创建主布局及三个子布局，并设置布局
    mainLayout = new QGridLayout(this);
    firstLayout = new QHBoxLayout;
    secondLayout = new QHBoxLayout;
    threeLayout = new QHBoxLayout;
    mainLayout->addLayout(firstLayout, 0, 0, 1, 1);
    mainLayout->addLayout(secondLayout, 1, 0, 5, 1);
    mainLayout->addLayout(threeLayout, 6, 0, 1, 1);


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
    //searchBtn->setIconSize(QPixmap(":/images/searchIcon.png").size());

    skinBtn = new QPushButton;
    skinBtn->setFlat(true);
    skinBtn->setIcon(QPixmap(":/images/skinIcon.png"));
    //skinBtn->setIconSize(QPixmap(":/images/skinIcon.png").size());

    preferenceBtn = new QPushButton;
    preferenceBtn->setFlat(true);
    preferenceBtn->setIcon(QPixmap(":/images/preferenceIcon.png"));
    //preferenceBtn->setIconSize(QPixmap(":/images/preferenceIcon.png").size());

    controlBtn = new QPushButton;
    controlBtn->setFlat(true);
    controlBtn->setIcon(QPixmap(":/images/controlIcon.png"));
    //controlBtn->setIconSize(QPixmap(":/images/controlIcon.png").size());

    hideBtn = new QPushButton;
    hideBtn->setFlat(true);
    hideBtn->setIcon(QPixmap(":/images/hideIcon.png"));
    //hideBtn->setIconSize(QPixmap(":/images/hideIcon.png").size());

    minimumBtn = new QPushButton;
    minimumBtn->setFlat(true);
    minimumBtn->setIcon(QPixmap(":/images/minimumIcon.png"));
    //minimumBtn->setIconSize(QPixmap(":/images/minimumIcon.png").size());

    closeBtn = new QPushButton;
    closeBtn->setFlat(true);
    closeBtn->setIcon(QPixmap(":/images/closeIcon.png"));
    //closeBtn->setIconSize(QPixmap(":/images/closeIcon.png").size());

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
    firstLayout->setMargin(0);

    /***********************************************************************/
    //创建第二个子布局,之后得补上！！！




    /***********************************************************************/
    //创建第三个子布局
    playerBtn = new QPushButton;
    playerBtn->setFlat(true);
    playerBtn->setIcon(QPixmap(":/images/playerIcon.png"));
    playerBtn->setIconSize(QPixmap(":/images/playerIcon.png").size());

    preMusicBtn = new QPushButton;
    preMusicBtn->setFlat(true);
    preMusicBtn->setIcon(QPixmap(":/images/preMusicIcon.png"));
    preMusicBtn->setIconSize(QPixmap(":/images/preMusicIcon.png").size());

    nextMusicBtn = new QPushButton;
    nextMusicBtn->setFlat(true);
    nextMusicBtn->setIcon(QPixmap(":/images/nextMusicIcon.png"));
    nextMusicBtn->setIconSize(QPixmap(":/images/nextMusicIcon.png").size());

    loveMusicBtn = new QPushButton;
    loveMusicBtn->setFlat(true);
    loveMusicBtn->setIcon(QPixmap(":/images/loveIcon.png"));
    loveMusicBtn->setIconSize(QPixmap(":/images/loveIcon.png").size());

    downloadBtn = new QPushButton;
    downloadBtn->setFlat(true);
    downloadBtn->setIcon(QPixmap(":/images/downloadIcon.png"));
    downloadBtn->setIconSize(QPixmap(":/images/downloadIcon.png").size());

    similarBtn = new QPushButton;
    similarBtn->setFlat(true);
    similarBtn->setIcon(QPixmap(":/images/similarIcon.png"));
    similarBtn->setIconSize(QPixmap(":/images/similarIcon.png").size());

    orderBtn = new QPushButton;
    orderBtn->setFlat(true);
    orderBtn->setIcon(QPixmap(":/images/orderIcon.png"));
    orderBtn->setIconSize(QPixmap(":/images/orderIcon.png").size());

    volumeBtn = new QPushButton;
    volumeBtn->setFlat(true);
    volumeBtn->setIcon(QPixmap(":/images/volumeIcon.png"));
    volumeBtn->setIconSize(QPixmap(":/images/volumeIcon.png").size());

    soundEffectsBtn = new QPushButton;
    soundEffectsBtn->setFlat(true);
    soundEffectsBtn->setIcon(QPixmap(":/images/soundEffectsIcon.png"));
    soundEffectsBtn->setIconSize(QPixmap(":/images/soundEffectsIcon.png").size());

    lyricBtn = new QPushButton;
    lyricBtn->setFlat(true);
    lyricBtn->setIcon(QPixmap(":/images/lyricIcon.png"));
    lyricBtn->setIconSize(QPixmap(":/images/lyricIcon.png").size());

    playQueueBtn = new QPushButton;
    playQueueBtn->setFlat(true);
    playQueueBtn->setIcon(QPixmap(":/images/playQueueIcon.png"));
    playQueueBtn->setIconSize(QPixmap(":/imagee/playQueueIcon.png").size());

    //将相关元素添加到第三个子布局上
    threeLayout->addSpacing(50);
    threeLayout->addWidget(preMusicBtn);
    threeLayout->addWidget(playerBtn);
    threeLayout->addWidget(nextMusicBtn);
    threeLayout->addStretch();
    threeLayout->addWidget(loveMusicBtn);
    threeLayout->addWidget(downloadBtn);
    threeLayout->addWidget(similarBtn);
    threeLayout->addWidget(orderBtn);
    threeLayout->addWidget(volumeBtn);
    threeLayout->addWidget(soundEffectsBtn);
    threeLayout->addWidget(lyricBtn);
    threeLayout->addWidget(playQueueBtn);




    //测试，待会删除
    testText = new QPushButton;
    testText->setText("SecondButton");
    secondLayout->addWidget(testText);


}

Widget::~Widget()
{

}

