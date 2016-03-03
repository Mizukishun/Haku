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

    /**************************************************************************/
    //以下仍旧是测试用，之后可能需要通过右键点击，并关联槽函数来创建新窗体
    AudioList *firstList = new AudioList();
    //接收下层窗体发送来的可以播放歌曲的信号OkToPlayAudio，并执行槽函数OkToPlayMusicOver
    //在槽函数中又进一步通知最顶层窗体，让顶层窗体可以控制歌曲的播放
//    connect(firstList, SIGNAL(OkToPlayAudio(SingleMusic *)),
//            this, SLOT(OkToPlayMusicOver(SingleMusic*)));

//    mulistLayout->addWidget(firstList);
//    mulistLayout->addStretch();

    //下面两个测试用，看是否能只播放一个列表中的歌曲
    createAudioList();
    createAudioList();

    mulistLayout->addStretch();
}

//创建新建列表栏
void MusicList::createAudioList()
{
    AudioList *tempList = new AudioList;
    mulistLayout->addWidget(tempList);
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

