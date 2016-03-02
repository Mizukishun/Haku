#include "singlemusic.h"

SingleMusic::SingleMusic(QWidget *parent) : QWidget(parent)
{
    //首先便是创建主界面
    createInterface();

}

//创建主界面的任务放到这一个函数中来
void SingleMusic::createInterface()
{
    /***********************按钮标签的定义********************/
    AdditionBtn = new QPushButton;
    AdditionBtn->setFlat(true);
    AdditionBtn->setIcon(QPixmap(":/images/AdditionIcon.png"));

    musicianBtn = new QPushButton;
    musicianBtn->setFlat(true);
    musicianBtn->setIcon(QPixmap(":/images/winIcon_40.png"));
    musicianBtn->setIconSize(QPixmap(":/images/winIcon_50.png").size());

    musicNameBtn = new QPushButton;
    musicNameBtn->setFlat(true);
    musicNameBtn->setText(tr("待添加的音乐名"));               //之后得修改

    //歌曲名右侧的歌曲总时长标签,00::00只是测试用，之后得删除！！
    musicNameLengthLabel = new QLabel;

    downloadedBtn = new QPushButton;
    downloadedBtn->setFlat(true);
    downloadedBtn->setIcon(QPixmap(":/images/downloadIcon.png"));

    loveBtn = new QPushButton;
    loveBtn->setFlat(true);
    loveBtn->setIcon(QPixmap(":/images/loveIcon.png"));

    deleteBtn = new QPushButton;
    deleteBtn->setFlat(true);
    deleteBtn->setIcon(QPixmap(":/images/controlIcon.png"));    //之后得换图片!

    detailBtn = new QPushButton;
    detailBtn->setFlat(true);
    detailBtn->setIcon(QPixmap(":/images/skinIcon.png"));       //以后也得换图片

    playedLengthLabel = new QLabel(tr("00:00/"));               //00::00测试用
    musicLengthLabel = new QLabel;                 //之后得删除

    /******************布局***************************************/
    rightBottomFrame = new QFrame;
    rightBottomLayout = new QHBoxLayout(rightBottomFrame);
    rightBottomLayout->setMargin(0);
    rightBottomLayout->setSpacing(0);
    rightBottomLayout->addWidget(playedLengthLabel);
    rightBottomLayout->addWidget(musicLengthLabel);
    rightBottomLayout->addWidget(downloadedBtn);
    rightBottomLayout->addStretch();
    rightBottomLayout->addWidget(loveBtn);
    rightBottomLayout->addWidget(deleteBtn);
    rightBottomLayout->addWidget(detailBtn);
    rightBottomFrame->hide();                       //初始要隐藏这一部分的组件

    //歌曲名及歌曲总时长部分的布局
    musicNameLayout = new QHBoxLayout;
    musicNameLayout->addWidget(musicNameBtn);
    musicNameLayout->addStretch();
    musicNameLayout->addWidget(musicNameLengthLabel);

    //右侧部分的总布局
    rightLayout = new QVBoxLayout;
    rightLayout->setMargin(0);
    rightLayout->setSpacing(0);
    rightLayout->addLayout(musicNameLayout);
    rightLayout->addWidget(rightBottomFrame);

    //整个窗体的布局
    mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(AdditionBtn);
    mainLayout->addWidget(musicianBtn);
    mainLayout->addLayout(rightLayout);
}

//创建QMediaPlayer对象，并修改歌曲名按钮的显示文字，以及显示歌曲总时长
void SingleMusic::createObject()
{
    player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(SingleMusicPath));
    player->setVolume(100);

    musicNameBtn->setText(SingleMusicName);
    //关联上歌曲的总时长
    connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(musicLength(qint64)));
    //同时连接上已播放时长的事件
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(musicPlayed(qint64)));
}

//获得歌曲总时长
void SingleMusic::musicLength(qint64 mT)
{
    //将时间单位转换成秒
    qint64 T = mT / 1000;
    //获得分钟
    QVariant minuteT = T / 60;
    //获得秒钟
    QVariant secondT = T % 60;
    //获得分钟和秒钟的字符串表示
    QString minuteString = minuteT.toString();
    QString secondString = secondT.toString();
    //修正上面的表示，使其能够表示成00:00的形式
    if(minuteT < 10)
        minuteString = "0" + minuteString;
    if(secondT < 10)
        secondString = "0" + secondString;

    //歌曲总时长的字符串表示
    QString musicLengthString = minuteString + ":" + secondString;

    //将表示歌曲总时长的按钮及标签的文字修正
    musicNameLengthLabel->setText(musicLengthString);
    musicLengthLabel->setText(musicLengthString);
}

//获得歌曲已播放时长
void SingleMusic::musicPlayed(qint64 mT)
{
    //与上面相似的转换
    qint64 T = mT / 1000;
    QVariant minT = T / 60;
    QVariant secT = T % 60;
    QString minString = minT.toString();
    QString secString = secT.toString();

    if(minT < 10)
        minString = "0" + minString;
    if(secT < 10)
        secString = "0" + secString;

    //已播放时长的字符串表示
    QString playedLength = minString + ":" + secString + "/";

    //修正已播放时长标签的文本
    playedLengthLabel->setText(playedLength);
}

//控制音乐的播放与暂停
void SingleMusic::playAndPause()
{
    if(player->state() == QMediaPlayer::PlayingState)
    {
        //如果歌曲正在播放，则暂停音乐的播放
        player->pause();
    }
    else
    {
        //如果歌曲不在播放，则播放歌曲
        player->play();

        //播放该首歌曲的同时，也要显示出隐藏的框架,并隐藏歌曲名旁边的标签
        rightBottomFrame->show();
        musicNameLengthLabel->hide();

    }
}

//重载鼠标双击事件，使得其重头开始播放这首音乐
void SingleMusic::mouseDoubleClickEvent(QMouseEvent *)
{
    playAndPause();
    //先暂时直接关联播放/暂停事件，之后在修改成下面这个从头开始播放的功能
//    player->setPosition(0);
//    player->play();
//    rightBottomFrame->show();
//    musicNameLengthLabel->hide();
}

void SingleMusic::active()
{
    createObject();
}
