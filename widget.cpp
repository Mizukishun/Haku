#include "widget.h"



Widget::Widget(QWidget *parent, Qt::WindowFlags flags)
    : QWidget(parent, flags)
{
    //设置窗体最小的尺寸
    setMinimumSize(1000, 650);
    //设置窗体图标
    setWindowIcon(QPixmap(":/images/winIcon_100.png"));

    //设置窗体标题
    setWindowTitle(tr("Haku"));

    //设置鼠标跟踪
    //setMouseTracking(true);

    //设置窗体标题栏，自定义，此时可以缩放，但不能移动，所以可能需要重新实现鼠标移动事件
    flags = Qt::CustomizeWindowHint;
    flags |= Qt::FramelessWindowHint; //无边框，会无法移动以及缩放
    //flags |= Qt::WindowStaysOnTopHint;
    setWindowFlags(flags);
    //setAttribute(Qt::WA_TranslucentBackground,true);

    //设置透明
    //setWindowOpacity(0);

    //设置皮肤
    setSkin(skinPic);

    //设置窗体的字体
    font = QFont("ZYSong18030", 14);
    setFont(font);

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
    userImagePix = new QPixmap(":/images/haku_icon_40.png");
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
    searchBtn->setToolTip(tr("搜索歌曲"));
    //输入完毕或点击搜索按钮则搜索歌曲
    connect(searchEdit, SIGNAL(editingFinished()), this, SLOT(searchMusic()));
    connect(searchBtn, SIGNAL(clicked()), this, SLOT(searchMusic()));

    skinBtn = new QPushButton;
    skinBtn->setFlat(true);
    skinBtn->setIcon(QPixmap(":/images/skinIcon.png"));
    skinBtn->setToolTip(tr("更换皮肤"));
    //连接更换皮肤的槽函数
    connect(skinBtn, SIGNAL(clicked()), this, SLOT(changeSkin()));

    preferenceBtn = new QPushButton;
    preferenceBtn->setFlat(true);
    preferenceBtn->setIcon(QPixmap(":/images/preferenceIcon.png"));
    preferenceBtn->setToolTip(tr("设置"));

    controlBtn = new QPushButton;
    controlBtn->setFlat(true);
    controlBtn->setIcon(QPixmap(":/images/controlIcon.png"));
    controlBtn->setToolTip(tr("遥控器"));

    hideBtn = new QPushButton;
    hideBtn->setFlat(true);
    hideBtn->setIcon(QPixmap(":/images/hideIcon.png"));
    hideBtn->setToolTip(tr("隐藏音乐库"));

    minimumBtn = new QPushButton;
    minimumBtn->setFlat(true);
    minimumBtn->setIcon(QPixmap(":/images/minimumIcon.png"));
    minimumBtn->setToolTip(tr("最小化窗口"));

    closeBtn = new QPushButton;
    closeBtn->setFlat(true);
    closeBtn->setIcon(QPixmap(":/images/closeIcon.png"));
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
    connect(minimumBtn, SIGNAL(clicked()), this, SLOT(minWidget()));


    /***********************************************************************/
    //创建第二个子布局
    secFrameLayout = new SecFrame;
    secondLayout->addWidget(secFrameLayout);

    //接收从第二个子布局发送过来的可以播放的信号，对传递过来的这首歌曲进行播放控制
    connect(secFrameLayout, SIGNAL(SendToTop(SingleMusic *)),
            this, SLOT(PreplayOrpauseMusic(SingleMusic*)));

    //接收从主界面传递过来的搜索音乐的信号，让downloadDisplay窗体直接进行实际的搜索
    connect(this, SIGNAL(searchMusicString(QString)),
            secFrameLayout->downloadDisplay,
            SLOT(search(QString)));
    //试听音乐时，能够及时反映出播放按钮及进度条的显示
    //connect(secFrameLayout, SIGNAL(changeBtnIcon(bool)), this, SLOT(currentIsPlaying(bool)));

    connect(secFrameLayout, SIGNAL(closePrevMusic()), this, SLOT(closePreMusic()));

    /***********************************************************************/
    //创建第三个子布局
    playerBtn = new QPushButton;
    playerBtn->setFlat(true);
    playerBtn->setIcon(QPixmap(":/images/playerIcon.png"));
    playerBtn->setIconSize(QPixmap(":/images/playerIcon.png").size());
    //关联上歌曲的播放控制事件
    playBool = true;
    connect(playerBtn, SIGNAL(clicked()), this, SLOT(player()));

    preMusicBtn = new QPushButton;
    preMusicBtn->setFlat(true);
    preMusicBtn->setIcon(QPixmap(":/images/preMusicIcon.png"));
    preMusicBtn->setIconSize(QPixmap(":/images/preMusicIcon.png").size());
    //下面是测试用，之后用其正统的功能（即播放上一首歌曲）替换掉
    connect(preMusicBtn, SIGNAL(clicked()), this, SLOT(prevMusic()));

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
    playQueueBtn->setIconSize(QPixmap(":/images/playQueueIcon.png").size());
    playQueueBtn->setToolTip(tr("播放队列"));

    /*********************************进度条的定义**********************************/


    /********************************以上是进度条的定义*****************************/

    //将相关元素添加到第三个子布局上
    threeLayout->addSpacing(60);
    threeLayout->setMargin(0);
    threeLayout->addWidget(preMusicBtn);
    threeLayout->addWidget(playerBtn);
    threeLayout->addWidget(nextMusicBtn);
    threeLayout->addSpacing(3);

    //添加进度条
    createSlider();
    threeLayout->addWidget(sliderFrame);

    threeLayout->addSpacing(3);
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

//最小化窗体
void Widget::minWidget()
{
    setWindowState(Qt::WindowMinimized);
}

void Widget::setSkin(QPixmap pic)
{
    this->setAutoFillBackground(true);
    QPalette mainPalette;
    mainPalette.setBrush(QPalette::Background, QBrush(pic));
    this->setPalette(mainPalette);
}

//重载鼠标按下事件
void Widget::mousePressEvent(QMouseEvent *event)
{
    startPos = this->pos();
    mousePos = event->globalPos();
    disPos = mousePos - startPos;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - disPos);
}

//接收从secFrame窗体传递过来的信号，控制歌曲的暂停播放功能之前，增添一个
//关闭之前播放歌曲的功能，使得即使从其他窗体传递过来了歌曲也只有一首歌曲播放
void Widget::PreplayOrpauseMusic(SingleMusic *mu)
{
    //在控制歌曲播放与暂停功能之前，先关闭之前播放的歌曲
    if(mainMusic != nullptr)
        closePreMusic();

    //再将传递过来的歌曲传递给playOrpauseMusic()函数进行播放
    playOrpauseMusic(mu);

    //测试用，看能够解决播放试听音乐开始没有进度条进行
    connect(mainMusic->player, SIGNAL(positionChanged(qint64)),
            this, SLOT(setSliderValue(qint64)));
    connect(mainMusic, SIGNAL(isPlaying(bool)), this, SLOT(currentIsPlaying(bool)));
    //player();
    //currentIsPlaying(true);
}

//单纯控制歌曲的播放与暂停
void Widget::playOrpauseMusic(SingleMusic *para)
{


    //这就是要播放或暂停的歌曲
    mainMusic = para;
    mainMusicName = mainMusic->SingleMusicName;
    mainMusicTotalTime = mainMusic->musicTotalTime;
    mainMusicPlayedTime = mainMusic->musicPlayedTime;

    connect(mainMusic->player, SIGNAL(positionChanged(qint64)),
            this, SLOT(setSliderValue(qint64)));

    //暂停或播放这首歌曲

    mainMusic->playAndPause();

    connect(mainMusic, SIGNAL(isPlaying(bool)), this, SLOT(currentIsPlaying(bool)));
}

//由于Qt信号槽机制的类型安全，所以由下面这个函数中介一下对音乐的播放控制
void Widget::player()
{
    //判断是否有歌曲被选中
    if(mainMusic->player->state() == QMediaPlayer::InvalidMedia)
    {
        return;
    }
    this->playOrpauseMusic(mainMusic);

//    if(playBool)
//    {
//        playerBtn->setIcon(QPixmap(":/images/playerIcon2.png"));
//        playBool = false;
//    }
//    else
//    {
//        playerBtn->setIcon(QPixmap(":/images/playerIcon.png"));
//        playBool = true;
//    }


}

void Widget::createSlider()
{
    playSlider = new QSlider(Qt::Horizontal);
    //设置进度条的样式(注意其参数是QString类型的，所以都要加双引号！）
    playSlider->setStyleSheet(
                "QSlider::groove:horizontal{     "
                "   height: 4px;                 "
                "   border: 1px;                 "
                "}                               "
                "QSlider::handle:horizontal{     "
                "   background: white;           "
                "   width: 10px;                 "
                "   border:1px;                 "
                "   border-radius: 5px;          "
                "   margin: -3px, -3px, -3px, -3px;"
                "}                               "
                "QSlider::sub-page:horizontal{   "
                "   background: qlineargradient(x1:0, y1:0, x2:1, y2:0,stop:0 cyan, stop:1 yellow);  "
                "}                               "
                "QSlider::add-page:horizontal{   "
                "   background: lightgray;       "
                "}                               "
                );




    musicNameSlider = new QLabel;
    playedTimeSlider = new QLabel;
    totalTimeSlider = new QLabel;



    upSliderLayout = new QHBoxLayout;
    upSliderLayout->setMargin(0);
    upSliderLayout->setSpacing(0);
    upSliderLayout->addWidget(musicNameSlider);
    upSliderLayout->addStretch();
    upSliderLayout->addWidget(playedTimeSlider);
    upSliderLayout->addWidget(totalTimeSlider);

    sliderFrame = new QFrame;
    sliderFrame->setMaximumHeight(40);
    sliderLayout = new QVBoxLayout(sliderFrame);
    sliderLayout->setSpacing(0);
    sliderLayout->setMargin(0);
    sliderLayout->addLayout(upSliderLayout);
    sliderLayout->addWidget(playSlider);
}

void Widget::setSliderValue(qint64 val)
{

    playSlider->setRange(0, mainMusicTotalTime);
    playSlider->setEnabled(true);
    playSlider->setPageStep(mainMusicTotalTime / 10);

    //直接使用singlemusic.h中的public变量SingleMusicName，方便统一显示歌名
    musicNameSlider->setText(mainMusic->SingleMusicName);

    playedTimeSlider->setText(mainMusic->playedLengthLabel->text());
    totalTimeSlider->setText(mainMusic->musicLengthLabel->text());

    playSlider->setValue(val);
}


//搜索歌曲
void Widget::searchMusic()
{
    //如果搜索框为空，则什么都不做
    if(searchEdit->text().isEmpty())
    {
        return;
    }

    searchMusicName = searchEdit->text();

    //发送搜索音乐的信号，让其下层窗体接收并最终让downloadDisplay窗体进行实际的搜索查询
    emit searchMusicString(searchMusicName);
    //如果搜索框不为空，则将搜索框中的文本传递给下载窗体，进行搜索
//    searchMusicName = searchEdit->text();
//    connect(this->secFrameLayout->downloadDisplay,
//            SIGNAL(secFrameLayout->downloadDisplay->searchMusic(searchMusicName)),
//            this->secFrameLayout->downloadDisplay,
//            SLOT(this->secFrameLayout->downloadDisplay->search(searchMusicName)));


}


//知道了现在是在播放音乐，所以要修改相应的按钮图标
void Widget::currentIsPlaying(bool playingBool)
{
    playBool = playingBool;
    if(playBool)
    {
        playerBtn->setIcon(QPixmap(":/images/playerIcon2.png"));
        //playBool = false;
    }
    else
    {
        playerBtn->setIcon(QPixmap(":/images/playerIcon.png"));
        //playBool = true;
    }

    //测试用，看在这里能够修改间隔时间
    mainMusic->player->setNotifyInterval(10);

    //是时间条的滑块也相应地变化
    connect(mainMusic->player, SIGNAL(positionChanged(qint64)),
            this, SLOT(setSliderValue(qint64)));

    //还得关联上歌词的滚动显示
    connect(mainMusic->player, SIGNAL(positionChanged(qint64)),
            secFrameLayout->lyricWidget, SLOT(lyricScroll(qint64)));
}

//接收下层窗体的信号closePrevMusic，关闭之前的音乐播放
void Widget::closePreMusic()
{
    if(mainMusic->player->state() == QMediaPlayer::InvalidMedia)
    {
        return;
    }
    mainMusic->stopMusic();
}

//播放上一首歌曲，但暂时做测试用，之后用真正的功能替换回来
void Widget::prevMusic()
{
    mainMusic->stopMusic();
}

//更换皮肤
void Widget::changeSkin()
{
    /*暂时只是实现将选中的图片保存到一个专门的皮肤文件夹内，
     * 将所选择的图片设置为窗体的皮肤,所以暂时能想到的操作主要有：
     * 打开文件选择对话框；将所选中的文件复制到专门的文件夹内，将该文件
     * 设置为窗体皮肤
     * 之后要补充的是：弹出一个皮肤选择对话框，能够让用户选择在skin文件夹下之前设置过的
     * 皮肤，也可以重新选择新的图片作为皮肤
     * */

    //注意：之后要完善这个换肤的功能，使得像酷狗一样能够弹出一个专门的换肤窗体。
    //先在当前路径下创建一个文件夹（目录）skin用于保存要设置的皮肤图片
    QString path = QDir::currentPath();
    QString skinPathStr = path + "\\skin";

    QDir dir(path);
    QDir skinDir(skinPathStr);
    if(!skinDir.exists())
    {
        dir.mkdir("skin");
    }
    //bool subdir = dir.mkdir(skin);

//    //测试用
//    searchEdit->setText(skinPathStr);

    //然后在打开文件选择对话框，选择图片文件
    //获取选择的文件的路径名
    QString skinFilePathStr = QFileDialog::getOpenFileName(this, tr("Change Skin"), "/",
                                            tr("Skin Picture(*.jpg; *.png;*.jpeg;*.bmp"));
    //获取选择的图片基本信息
    QString picBaseName = QFileInfo(skinFilePathStr).baseName();
    QString picName = QFileInfo(skinFilePathStr).fileName();

    //在文件夹skin中新建文件
    QFile picFile;
    QDir::setCurrent(skinPathStr);
    picFile.setFileName(picName);
    if(!picFile.open(QIODevice::ReadOnly))
    {
    }

    //判断图片的信息是否满足一定的宽高值，若不满足，则提示出错，重新选择



    //如果满足，则将选择的文件复制到skip文件夹下，并将其设置为播放器的当前皮肤


}

////歌曲已播放时长关联还是那个歌词的滚动显示，通知歌词窗口已经播放了多少时间
//void Widget::lyricScroll(qint64 lyPlayedTime)
//{
//    //发送信号，通知歌词窗口已经播放了多少时间
//    emit playedTimeLyric(lyPlayedTime);
//}
