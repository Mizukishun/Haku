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

        newAudioLayout->addWidget(music);

        musicObjectList.insert(musicObjectList.end(), music);
    }
    //添加歌曲文件后，就隐藏之前的“添加本地歌曲”那块区域，而现实歌曲列表
    newAudioFrame->show();
    addLocateFrame->hide();
}












