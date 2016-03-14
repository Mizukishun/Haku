#include "favoritelist.h"
#include <QPalette>
#include "toolgroup/audiolist.h"

FavoriteList::FavoriteList(QWidget *parent) : QWidget(parent)
{
    //唯一性标识初始设置为false
    favoriteNetID = false;
    //设置边框
    setContentsMargins(0, 0, 0, 0);
    //设置固定宽度
    setFixedWidth(300);

    //设置窗体的背景颜色
    QPalette Fp;
    Fp.setColor(QPalette::Background, QColor(218, 230, 241, 100));
    setAutoFillBackground(true);
    setPalette(Fp);

    //总体布局
    favoriteLayout = new QVBoxLayout(this);
    favoriteLayout->setMargin(0);
    favoriteLayout->setSpacing(0);

    //列表框架及其布局
    favoriteListFrame = new QFrame;
    favoriteListFrameLayout = new QVBoxLayout(favoriteListFrame);
    favoriteListFrameLayout->setMargin(0);
    favoriteListFrameLayout->setSpacing(0);

    //将框架先添加到总体布局上，其后跟着addStretch()
    favoriteLayout->addWidget(favoriteListFrame);
    favoriteLayout->addStretch();

    //下面是测试!!!!
    createFavoriteList();
    //修改列表名
    favoriteOnlyList->changeListNameS(tr("试听音乐"));
//    createFavoriteList();
}

//新建一个喜爱歌曲列表
void FavoriteList::createFavoriteList()
{
    AudioList *newList = new AudioList();
    //隐藏掉“添加本地音乐”这一框架
    newList->hideAddLocateFrame();
    favoriteOnlyList = newList;

    //创建DisplayWidget对象的实例，以方便将试听的音乐添加到列表中
//    disWidget = new DisplayWidget(this);
//    disWidget->hide();
    //接收从DisplayWidget传递过来的添加信号，将这首歌曲添加到“试听音乐列表”
//    connect(disWidget, SIGNAL(addThisMusicToListDis(SingleMusic*)),
//            this, SLOT(addMusicToList(SingleMusic*)));



    //维护这个窗体所持有的列表
    favoriteLists.insert(favoriteLists.end(), favoriteOnlyList);

    //将这个歌曲列表添加到框架中
    favoriteListFrameLayout->addWidget(favoriteOnlyList);

    connect(favoriteOnlyList, SIGNAL(OkToPlayAudio(SingleMusic*, bool)),
            this, SLOT(OkToFavoriteOver(SingleMusic*, bool)));
}

//接受下层传递过来的歌曲，并向上层窗体传递，同时还需要维护播放的唯一性
//也即要使得只有一个歌曲列表能够被选中，这个窗体内的其它列表应该完全关闭，
//其中的歌曲也全部停止播放
void FavoriteList::OkToFavoriteOver(SingleMusic *mu, bool fb)
{
    favoriteOnlyMusic = mu;

    favoriteNetID = fb;

    foreach(AudioList *a, favoriteLists)
    {
        //判断是哪个列表传递过来的信号
        if(a->NetID)
        {
            emit fromFavoriteToSecFrame(favoriteOnlyMusic, favoriteNetID);
            favoriteOnlyList->show();
            //控制其不再继续播放
            a->NetID = false;
        }
        else
        {
            //其它列表则要关闭其中所有歌曲的播放，并隐藏列表
            a->closeAllMusicInList();
            a->hideList();
        }
    }
}

void FavoriteList::closeAllFavoriteList()
{
    foreach(AudioList *f, favoriteLists)
    {
        f->closeAllMusicInList();
        f->hideList();
    }
    favoriteNetID = false;
}

//将DisplayWidget传递过来的试听歌曲添加到试听列表
void FavoriteList::addMusicToList(SingleMusic *mus)
{
    favoriteOnlyMusic = mus;
    //调用AudioList类的public函数addDisplayMusic()
    favoriteOnlyList->addDisplayMusic(favoriteOnlyMusic);
    favoriteOnlyList->show();

}
