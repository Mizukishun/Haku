#include "singlemusic.h"
#include <QFont>
#include <QTimer>


SingleMusic::SingleMusic(QWidget *parent) : QWidget(parent)
{
    //首先便是创建主界面
    createInterface();

    //设置当鼠标移动到这个窗体上时，窗体颜色加深，表示移动到了这首歌曲上
    //首先设置鼠标捕捉
    setMouseTracking(true);
    //当鼠标移动到窗体时修改其颜色
    //changeColor();

    //设置窗体颜色
    //p.setColor(QPalette::Background, QColor(218, 230, 241, 255));
    p.setColor(QPalette::Background, QColor(218, 230, 241, 0));
    setAutoFillBackground(true);
    this->setPalette(p);

}

//创建主界面的任务放到这一个函数中来
void SingleMusic::createInterface()
{
    /***********************按钮标签的定义********************/
    AdditionBtn = new QPushButton;
    AdditionBtn->setFlat(true);
    AdditionBtn->setText(tr("+"));
    //AdditionBtn->setIcon(QPixmap(":/images/AdditionIcon.png"));
    AdditionBtn->setMaximumSize(20,20);

    musicianBtn = new QPushButton;
    musicianBtn->setFlat(true);
    musicianBtn->setIcon(QPixmap(":/images/musicianIcon.png"));
    musicianBtn->setIconSize(QPixmap(":/images/musicianIcon.png").size());
    musicianBtn->setMaximumSize(40,40);

    //注意：歌曲名按钮不是QPushButton类型，而是QLabel,以方便设置文本的对齐方式！
    musicNameBtn = new QLabel;
    musicNameBtn->setMaximumWidth(200);     //设置歌曲名的最大宽度
    musicNameBtn->setAlignment(Qt::AlignLeft);
    //对歌曲名按钮的文字进行设置
    QFont Bf;
    Bf.setPointSize(12);
    musicNameBtn->setFont(Bf);


    //歌曲名右侧的歌曲总时长标签,00::00只是测试用，之后得删除！！
    musicNameLengthLabel = new QLabel;
    musicNameLengthLabel->setFont(Bf);

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

    //对时长标签的文字进行大小设置
    QFont f;
    f.setPointSize(10);
    playedLengthLabel->setFont(f);
    musicLengthLabel->setFont(f);


    /******************布局***************************************/
    rightBottomFrame = new QFrame;
    rightBottomLayout = new QHBoxLayout(rightBottomFrame);
    rightBottomLayout->setMargin(0);
    rightBottomLayout->setSpacing(0);
    rightBottomLayout->addWidget(playedLengthLabel);
    rightBottomLayout->addWidget(musicLengthLabel);
    rightBottomLayout->addStretch();
    rightBottomLayout->addWidget(downloadedBtn);
    rightBottomLayout->addWidget(loveBtn);
    rightBottomLayout->addWidget(deleteBtn);
    rightBottomLayout->addWidget(detailBtn);

    rightBottomFrame->hide();                       //初始要隐藏这一部分的组件
    musicianBtn->hide();                            //歌手图片也要先隐藏

    //歌曲名及歌曲总时长部分的布局
    musicNameLayout = new QHBoxLayout;
    musicNameLayout->setMargin(0);
    musicNameLayout->setSpacing(0);
    musicNameLayout->addWidget(musicNameBtn);
    musicNameLayout->addStretch();
    musicNameLayout->addWidget(musicNameLengthLabel);
    musicNameLayout->addSpacing(3);

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
    mainLayout->addSpacing(5);
    mainLayout->addLayout(rightLayout);
}

//创建QMediaPlayer对象，并修改歌曲名按钮的显示文字，以及显示歌曲总时长
void SingleMusic::createObject()
{
    player = new QMediaPlayer;
    //为了能够播网络上的音乐，所以暂时下面这句注释掉，而补充下下句
    //player->setMedia(QUrl::fromLocalFile(SingleMusicPath));
    player->setMedia(QUrl(SingleMusicPath));
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
    //获取歌曲总时长，供其它部件使用
    musicTotalTime = mT;

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
    //先获取歌曲已播放时长，供其它部件使用
    musicPlayedTime = mT;

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

    //已播放时长的字符串表
    QString playeddLength = minString + ":" + secString + "/";

    //修正已播放时长标签的文本
    playedLengthLabel->setText(playeddLength);
}

//控制音乐的播放与暂停
void SingleMusic::playAndPause()
{
    if(player->state() == QMediaPlayer::PlayingState)
    {
        //如果歌曲正在播放，则暂停音乐的播放
        player->pause();
        emit isPlaying(false);
    }
    else
    {
        //如果歌曲不在播放，则播放歌曲
        player->play();

        //播放该首歌曲的同时，也要显示出隐藏的框架,并隐藏歌曲名旁边的标签
        musicianBtn->show();
        rightBottomFrame->show();
        musicNameLengthLabel->hide();

        emit isPlaying(true);

    }
}

//重载鼠标双击事件，使得其重头开始播放这首音乐
void SingleMusic::mouseDoubleClickEvent(QMouseEvent *)
{
    //playAndPause();
    //先暂时直接关联播放/暂停事件，之后在修改成下面这个从头开始播放的功能
    player->setPosition(0);
    player->play();
    emit isPlaying(true);

    musicianBtn->show();
    rightBottomFrame->show();
    musicNameLengthLabel->hide();

}

void SingleMusic::active()
{
    createObject();
}

//重载鼠标单击事件，如果单击了，则说明这首可以进行播放了，其他的歌就不能播放
void SingleMusic::mousePressEvent(QMouseEvent *event)
{
    //如果是鼠标左键的按下事件
    if(event->button() == Qt::LeftButton)
    {
        //这首歌选中可以播放了
        ok = true;
        emit OkToPlay(this);
    }

}

//恢复成初始的界面状态，也即只含有歌曲名与歌曲总时长，而隐藏其他按钮
void SingleMusic::resetGUI()
{
    //完全停止播放
    player->stop();
    //隐藏右下侧的按钮框架
    rightBottomFrame->hide();
    musicianBtn->hide();
    //显示歌曲名后面的总时长标签
    musicNameLengthLabel->show();
}

//只是单纯地关闭音乐
void SingleMusic::stopMusic()
{
    player->stop();
}

//当鼠标移动到此窗体上时，就改变窗体的颜色
void SingleMusic::changeColor()
{
//    //获取鼠标的全局位置
//    int curX = QCursor::pos().x();
//    int curY = QCursor::pos().y();
//    //判断鼠标是否在窗体上,如果在窗体上，则将其透明度加深
//    //如果不在窗体上，则按其原来的颜色
//    if(curX >= x() && curX <= x() + width() && curY >= y() && curY <= y() + height())
//    {
//        QPalette p;
//        p.setColor(QPalette::Background, QColor(218, 230, 241, 255));
//        setAutoFillBackground(true);
//        this->setPalette(p);
//    }
//    else
//    {
//        setWindowOpacity(1);
//    }

    //计时器，每个50ms自动调用该函数，从而实时更新窗体颜色
//    QTimer::singleShot(50, this, SLOT(visible()));
}


//重载鼠标移动事件，使得当鼠标移动到窗体内部时改变窗体的颜色
void SingleMusic::mouseMoveEvent(QMouseEvent *event)
{
//    if(event->globalX() >= x() && event->globalX() <= (x() + width())
//            && event->globalY() >= y() && event->globalY() <= (y() + height()))
//    {
//        p.setColor(QPalette::Background, QColor(218, 230, 241, 255));
//        this->setPalette(p);
//    }
//    else
//    {
//        p.setColor(QPalette::Background, QColor(0, 0, 241, 50));
//        this->setPalette(p);
//    }


}

//重新实现进入窗体事件，使得进入窗体后颜色加深
void SingleMusic::enterEvent(QEvent* )
{
    p.setColor(QPalette::Background, QColor(218, 230, 241, 255));
    this->setPalette(p);
}

//重新啊实现离开窗体事件，使得离开窗体后颜色还原
void SingleMusic::leaveEvent(QEvent *)
{
    p.setColor(QPalette::Background, QColor(218, 230, 241, 0));
    this->setPalette(p);
}




////更新窗体透明度
//void SingleMusic::visible()
//{
//    changeColor();
//}
//重载鼠标释放事件，但暂时不具体实现其
void SingleMusic::mouseReleaseEvent(QMouseEvent *)
{
}

SingleMusic::~SingleMusic()
{
}
