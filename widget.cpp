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
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
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
    userImage->setToolTip(tr("更换头像"));

    userName = new QPushButton;
    userName->setFlat(true);
    userName->setText(tr("Haku520"));
    userName->setToolTip(tr("更改用户名"));

    searchEdit = new QLineEdit;
    searchBtn = new QPushButton;
    searchBtn->setFlat(true);
    searchBtn->setIcon(QPixmap(":/images/searchIcon.png"));
    //searchBtn->setIconSize(QPixmap(":/images/searchIcon.png").size());
    searchBtn->setToolTip(tr("搜索歌曲"));

    skinBtn = new QPushButton;
    skinBtn->setFlat(true);
    skinBtn->setIcon(QPixmap(":/images/skinIcon.png"));
    //skinBtn->setIconSize(QPixmap(":/images/skinIcon.png").size());
    skinBtn->setToolTip(tr("更换皮肤"));

    preferenceBtn = new QPushButton;
    preferenceBtn->setFlat(true);
    preferenceBtn->setIcon(QPixmap(":/images/preferenceIcon.png"));
    //preferenceBtn->setIconSize(QPixmap(":/images/preferenceIcon.png").size());
    preferenceBtn->setToolTip(tr("设置"));

    controlBtn = new QPushButton;
    controlBtn->setFlat(true);
    controlBtn->setIcon(QPixmap(":/images/controlIcon.png"));
    //controlBtn->setIconSize(QPixmap(":/images/controlIcon.png").size());
    controlBtn->setToolTip(tr("遥控器"));

    hideBtn = new QPushButton;
    hideBtn->setFlat(true);
    hideBtn->setIcon(QPixmap(":/images/hideIcon.png"));
    //hideBtn->setIconSize(QPixmap(":/images/hideIcon.png").size());
    hideBtn->setToolTip(tr("隐藏音乐库"));

    minimumBtn = new QPushButton;
    minimumBtn->setFlat(true);
    minimumBtn->setIcon(QPixmap(":/images/minimumIcon.png"));
    //minimumBtn->setIconSize(QPixmap(":/images/minimumIcon.png").size());
    minimumBtn->setToolTip(tr("最小化窗口"));

    closeBtn = new QPushButton;
    closeBtn->setFlat(true);
    closeBtn->setIcon(QPixmap(":/images/closeIcon.png"));
    //closeBtn->setIconSize(QPixmap(":/images/closeIcon.png").size());
    closeBtn->setToolTip(tr("关闭"));

    //将各个按钮添加到第一个子布局上
    firstLayout->setMargin(0);
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

    //添加信号槽，暂时只实现退出按钮，其余的之后得补上！
    connect(closeBtn, SIGNAL(clicked()), this, SLOT(quitEmit()));


    /***********************************************************************/
    //创建第二个子布局,之后得补上！！！
    secFrameLayout = new SecFrame;
    secondLayout->addWidget(secFrameLayout);



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
    loveMusicBtn->setToolTip(tr("收藏"));

    downloadBtn = new QPushButton;
    downloadBtn->setFlat(true);
    downloadBtn->setIcon(QPixmap(":/images/downloadIcon.png"));
    downloadBtn->setIconSize(QPixmap(":/images/downloadIcon.png").size());
    downloadBtn->setToolTip(tr("下载"));

    similarBtn = new QPushButton;
    similarBtn->setFlat(true);
    similarBtn->setIcon(QPixmap(":/images/similarIcon.png"));
    similarBtn->setIconSize(QPixmap(":/images/similarIcon.png").size());
    similarBtn->setToolTip(tr("相似歌曲"));

    orderBtn = new QPushButton;
    orderBtn->setFlat(true);
    orderBtn->setIcon(QPixmap(":/images/orderIcon.png"));
    orderBtn->setIconSize(QPixmap(":/images/orderIcon.png").size());
    orderBtn->setToolTip(tr("播放顺序"));

    volumeBtn = new QPushButton;
    volumeBtn->setFlat(true);
    volumeBtn->setIcon(QPixmap(":/images/volumeIcon.png"));
    volumeBtn->setIconSize(QPixmap(":/images/volumeIcon.png").size());
    volumeBtn->setToolTip(tr("音量"));

    soundEffectsBtn = new QPushButton;
    soundEffectsBtn->setFlat(true);
    soundEffectsBtn->setIcon(QPixmap(":/images/soundEffectsIcon.png"));
    soundEffectsBtn->setIconSize(QPixmap(":/images/soundEffectsIcon.png").size());
    soundEffectsBtn->setToolTip(tr("音效"));

    lyricBtn = new QPushButton;
    lyricBtn->setFlat(true);
    lyricBtn->setIcon(QPixmap(":/images/lyricIcon.png"));
    lyricBtn->setIconSize(QPixmap(":/images/lyricIcon.png").size());
    lyricBtn->setToolTip(tr("歌词"));

    playQueueBtn = new QPushButton;
    playQueueBtn->setFlat(true);
    playQueueBtn->setIcon(QPixmap(":/images/playQueueIcon.png"));
    playQueueBtn->setIconSize(QPixmap(":/imagee/playQueueIcon.png").size());
    playQueueBtn->setToolTip(tr("播放队列"));

    //将相关元素添加到第三个子布局上
    threeLayout->addSpacing(60);
    threeLayout->setMargin(0);
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


}

Widget::~Widget()
{

}

//实现quitEmit()槽函数，使得当点击关闭按钮时，连接上这个函数，
//而这个函数继而能够发送窗体的quit()信号，再进而关联上整个程序的退出函数
void Widget::quitEmit()
{
    emit quit();
}

