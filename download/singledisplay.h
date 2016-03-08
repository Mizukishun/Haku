#ifndef SINGLEDISPLAY_H
#define SINGLEDISPLAY_H

/*这个类用于在搜索之后，展示其中的一条歌曲，从而通过在displaywidget界面中
 * 创建多条歌曲显示出搜索出来的所有歌曲，并能够通过单击选中一条歌曲，而双击
 * 则是播放这首歌曲，因为要被其他类访问，所以这个类的大部分属性与方法都是public的
 * */

#include <QWidget>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QPixmap>


class SingleDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit SingleDisplay(QWidget *parent = 0);

    //创建主界面
    void createDsingleInterface();

protected:
    void mouseDoubleClickEvent(QMouseEvent *);


signals:
    //发送信号，让上层窗体接收这个信号发送的歌曲名,从而进一步地播放这首歌
    void DsinglePlayThisMusic(QString musicname);

    //发送信号，通知上层窗体要下载这首歌曲
    void DsingleDownloadMusic(QString downloadMusicName);

public slots:
    //当鼠标单击歌曲名按钮时，播放这首歌曲
    void playThisMusic();
    //当鼠标单击下载按钮时，就下载这首歌曲
    void DsDownloadThisMusic();

public:
    //开头的CheckBox
    QCheckBox *singleCheckBox;
    //歌曲名按钮
    QPushButton *DsingleMusicBtn;
    //专辑名按钮
    QPushButton *DsingleAlbumBtn;
    //时长按钮
    QPushButton *DsingleTimeBtn;
    //播放按钮
    QPushButton *DsinglePlayBtn;
    //添加到列表按钮
    QPushButton *DsingleAddBtn;
    //下载按钮
    QPushButton *DsingleDownloadBtn;
    //三个小按钮的布局
    QHBoxLayout *threeBtnLayout;
    //大布局
    QHBoxLayout *DsingleLayout;


    //要播放的歌曲名
    QString DsMusicName;
    //要下载的歌曲名
    QString DsDownloadMusicName;

    //编号，用来控制当滑动条值变化时有哪些歌曲显示出来，其余的则隐藏
    int SDnumber;

};

#endif // SINGLEDISPLAY_H
