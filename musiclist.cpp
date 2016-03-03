#include "musiclist.h"
#include <QPalette>
//下面是测试用
#include <QVBoxLayout>


MusicList::MusicList(QWidget *parent) : QWidget(parent)
{
    musicListNetID = false;

    //设置边框？？？
    setContentsMargins(0, 0, 0, 0);

    //设置固定的宽度
    setFixedWidth(300);

    //设置窗体的背景颜色
    QPalette p;
    p.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    this->setPalette(p);

    //音乐列表中的总体布局
    mulistLayout = new QVBoxLayout(this);
    mulistLayout->setMargin(0);
    mulistLayout->setSpacing(0);

    //添加列表的框架
    mulistFrame = new QFrame;
    mulistFrameLayout = new QVBoxLayout(mulistFrame);
    mulistFrameLayout->setSpacing(0);
    mulistFrameLayout->setMargin(0);
    mulistLayout->addWidget(mulistFrame);
    mulistLayout->addStretch();

    /**************************************************************************/
    //下面两个测试用，看是否能只播放一个列表中的歌曲
    createAudioList();
    createAudioList();
}

//创建新建列表栏
void MusicList::createAudioList()
{
    AudioList *tempList = new AudioList;
    mulistFrameLayout->addWidget(tempList);

    //要怎样才能在最后一个新建的列表中添加下面这一句
    //使得整个窗体更加有序？？？
    //mulistLayout->addStretch();

    newlistList.insert(newlistList.end(), tempList);

    onlyNewList = tempList;
    connect(onlyNewList, SIGNAL(OkToPlayAudio(SingleMusic*, bool)),
            this, SLOT(OkToPlayMusicOver(SingleMusic*, bool)));
}


void MusicList::OkToPlayMusicOver(SingleMusic *okmusic, bool b)
{
    tempMusicList = okmusic;
    musicListNetID = b;

    //控制只播放一个列表中的歌曲
    foreach(AudioList *A, newlistList)
    {
        //
        if(A->NetID)
        {
            //如果是选中的那个列表的话，就将信号向上传递，并展开列表
            emit fromMusicListToSecFrame(tempMusicList, musicListNetID);
            onlyNewList->show();
            //向上传递了信号过后，要把这个列表恢复成与其他列表一样，等待接收下一次的选择点击
            A->NetID = false;
        }
        else
        {
            //否则，就关闭其它列表中的其它所有歌曲的播放
            A->closeAllMusicInList();
            A->hideList();

        }
    }
}

//关闭这个窗体的所有音乐了列表
void MusicList::closeAllMusicList()
{
    foreach(AudioList *d, newlistList)
    {
        d->closeAllMusicInList();
        d->hideList();
    }
    musicListNetID = false;
}
