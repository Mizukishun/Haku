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

signals:

public slots:

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

};

#endif // SINGLEDISPLAY_H
