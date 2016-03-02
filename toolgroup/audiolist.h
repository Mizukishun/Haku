#ifndef AUDIOLIST_H
#define AUDIOLIST_H

#include <QWidget>
#include "singlemusic.h"
#include "simplifiedmusic.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QFileDialog>
#include <QFileInfo>
#include <QMediaPlayer>
#include <QDebug>


class AudioList : public QWidget
{
    Q_OBJECT
public:
    explicit AudioList(QWidget *parent = 0);



signals:

public slots:
    //创建一条新的“新建列表"
    void createList();
    //向窗体中添加歌曲
    void addMusic();

private:
    /************************添加歌曲按钮的框架部分*******************/
    //”添加本地歌曲“按钮
    QPushButton *addLocateMusic;
    //”添加本地歌曲文件夹"按钮
    QPushButton *addLocateMusicFile;
    //上面两按钮组合成布局
    QVBoxLayout *addLocateLayout;
    //上面所构成的框架
    QFrame *addLocateFrame;

    //装载下部分歌曲所需的框架
    QFrame *newAudioFrame;
    QVBoxLayout *newAudioLayout;

    /*************************************************************/

    //这一窗体的总体布局
    QVBoxLayout *AudioLayout;


    /************************对歌曲的处理************************************/
    //用于保存多首歌曲的路径
    QStringList musicPathS;
    //用于保存多首歌曲的名称
    QStringList musicNameS;
    //用于保存单首歌曲的路径
    QString musicPath;
    //用于保存单首歌曲的名称
    QString musicName;

    //维护一个歌曲对象列表
    QList<SingleMusic *> musicObjectList;



};

#endif // AUDIOLIST_H
