#include "audiolist.h"

AudioList::AudioList(QWidget *parent) : QWidget(parent)
{

    /****************************************************************/
    //添加歌曲两按钮的框架布局
    addLocateFrame = new QFrame;

    addLocateLayout = new QVBoxLayout(addLocateFrame);
    addLocateMusic = new QPushButton;
    addLocateMusic->setFlat(true);
    addLocateMusic->setText(tr("添加本地歌曲"));
    addLocateMusicFile = new QPushButton;
    addLocateMusicFile->setFlat(true);
    addLocateMusicFile->setText(tr("添加本地歌曲文件夹"));
    addLocateLayout->addWidget(addLocateMusic);
    addLocateLayout->addWidget(addLocateMusicFile);


    /*****************************************************************/
    //这个窗体的整体布局
    AudioLayout = new QVBoxLayout(this);
    AudioLayout->setMargin(0);
    AudioLayout->setSpacing(0);

    /*****************************************************************/
    createList();

    connect(addLocateMusic, SIGNAL(clicked()), this, SLOT(addMusic()));
}

//新建一条列表，这个列表还要包括一个框架，只是当还没有歌曲文件时，暂时隐藏
//当有歌曲文件时，便添加到这个框架中，并显示出来
void AudioList::createList()
{
    SimplifiedMusic *newList = new SimplifiedMusic();
    //通过监视SimplifiedMusic对象的鼠标按下事件，来显示豁隐藏歌曲列表
    connect(newList, SIGNAL(isPressed(bool)), this, SLOT(AudioFrameHideOrShow(bool)));
    AudioLayout->addWidget(newList);
    AudioLayout->addWidget(addLocateFrame);

    //定义成静态的类型，即使函数结束也还保存其值
    newAudioFrame = new QFrame(this);
    newAudioLayout = new QVBoxLayout(newAudioFrame);
    //先暂时隐藏这个框架，添加了歌曲文件之后再显示出来
    newAudioFrame->hide();
    AudioLayout->addWidget(newAudioFrame);
}

//向窗体中添加歌曲
/*这个函数所要完成的功能有：打开文件对话框，选择歌曲文件后，保存歌曲路径等信息，并创建
 * 歌曲列表，也就是多个SingleMusic类，还要讲这些类对象放到窗体中显示出来,每一个SingleMusic类
 * 各自保存一首歌曲。添加完歌曲后，还要隐藏addLocateLayout框架。
 */
void AudioList::addMusic()
{
    //打开文件选择对话框，并将选择的歌曲路径名存储在musicPathS中
    musicPathS = QFileDialog::getOpenFileNames(this, tr("Add Music"), "/",
                                               tr("Music files(*.mp3)"));
    foreach(QString s, musicPathS)
    {
        //将单首歌曲的路径名先暂时存储在musicPath变量中
        musicPath = s;
        //将歌曲名存储在musicNameS变量中
        musicName = QFileInfo(s).baseName();
        //将所有歌曲名添加到musicNameS变量中
        musicNameS.append(musicName);

        //之后需将歌曲路劲、歌曲名称等传递给最里层的窗体SingleMusic，
        //由它来控制歌曲的播放等
        SingleMusic *music = new SingleMusic;
        music->SingleMusicPath = musicPath;
        music->SingleMusicName = musicName;
        music->active();

        //如果某个音乐对象被选中，则会发送音乐名称信号出来
        connect(music, SIGNAL(OkToPlay(SingleMusic *)),
                this, SLOT(OkToPlayMusic(SingleMusic *)));

        newAudioLayout->addWidget(music);

        musicObjectList.insert(musicObjectList.end(), music);
    }

    //此列表默认维护着第一首歌曲
    temp = musicObjectList.at(0);

    //添加歌曲文件后，就隐藏之前的“添加本地歌曲”那块区域，而现实歌曲列表
    newAudioFrame->show();
    addLocateFrame->hide();
}

//通过监视SimplifiedMusic对象的鼠标按下事件，来显示或隐藏歌曲列表
void AudioList::AudioFrameHideOrShow(bool)
{
    if(newAudioFrame->isHidden())
        newAudioFrame->show();
    else
        newAudioFrame->hide();
}


//将从信号接收来的SingleMusic对象作为实参进行操作，如果两者指向相同的歌曲
//则可以进行播放，否则，就要重置其他所有歌曲的状态
void AudioList::OkToPlayMusic(SingleMusic *m)
{
    //说明是这首歌曲被选中，所以此时歌曲列表要记住是这首歌曲要播放
    temp = m;
    //遍历歌曲列表中的歌曲，找到了这首歌曲，则可以进行播放，如果不是，则恢复成初始界面状态
    foreach(SingleMusic *s, musicObjectList)
    {
        //如果选中的是这首歌，则可以对其进行播放暂停等操作
        if(s == m)
        {
            m->playAndPause();
        }
        else
        {
            s->resetGUI();
        }
    }
}










