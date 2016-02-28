#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QIcon>
#include <QStackedWidget>
#include <QPushButton>
#include <QSplitter>
#include <QMouseEvent>
#include <QTextEdit>
#include <QLineEdit>
#include <QToolButton>
#include <QSize>
#include "secframe.h"


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~Widget();

protected:
    //还未实现，重现实现鼠标移动事件，使得窗体能够移动
//    void mouseMoveEvent(QMouseEvent *event);
//    void mousePressEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent *event);

signals:
    //这个信号关联了整个程序的退出函数，而这个信号是由下面的quitEmit()函数发送的
    void quit();            //这里有个疑问：信号可以不用具体实现吗？？？



private slots:
    //关闭按钮的点击事件关联了这个槽函数，而这个槽函数会发送这个窗体的quit()信号
    void quitEmit();
    //点击最小化按钮所关联的槽函数
    void minWidget();



private:
    /***************************************************************/
    //整个窗体的主布局,是在垂直方向上再放三个子布局,因为要设置三个子布局有不同的大小，
    //所以主布局选择了QGridLayout
    QGridLayout *mainLayout;
    //第一个子布局
    QHBoxLayout *firstLayout;
    //第二个子布局
    QHBoxLayout *secondLayout;
    //第三个子布局
    QHBoxLayout *threeLayout;

    /****************************************************************/
    //第一个子布局上的元素
    //用户头像按钮及名字
    QPushButton *userImage;
    QPushButton *userName;
    QPixmap *userImagePix;

    //搜索框及其按钮
    QLineEdit *searchEdit;
    QPushButton *searchBtn;

    //皮肤按钮
    QPushButton *skinBtn;
    //设置按钮
    QPushButton *preferenceBtn;
    //控制器按钮
    QPushButton *controlBtn;
    //隐藏音乐库按钮
    QPushButton *hideBtn;
    //最小化按钮
    QPushButton *minimumBtn;
    //关闭按钮
    QPushButton *closeBtn;

    /*****************************************************************/
    //第二个子布局
    SecFrame *secFrameLayout;

    /******************************************************************/
    //第三个子布局上的元素
    //播放按钮
    QPushButton *playerBtn;
    //上一曲按钮
    QPushButton *preMusicBtn;
    //下一曲按钮
    QPushButton *nextMusicBtn;
    //我喜欢按钮
    QPushButton *loveMusicBtn;
    //下载按钮
    QPushButton *downloadBtn;
    //相似歌曲按钮
    QPushButton *similarBtn;
    //播放顺序按钮
    QPushButton *orderBtn;
    //音量按钮
    QPushButton *volumeBtn;
    //音效按钮
    QPushButton *soundEffectsBtn;
    //打开桌面歌词按钮
    QPushButton *lyricBtn;
    //播放队列按钮
    QPushButton *playQueueBtn;

    //另外，播放时间那个长条，先用addStretch()替上，之后要补上
    /***********************************************************************/







};

#endif // WIDGET_H
