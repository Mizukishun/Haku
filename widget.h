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

private:
    /***************************************************************/
    //整个窗体的主布局,是在垂直方向上再放三个子布局,因为要设置三个子布局有不同的大小，
    //所以主布局选择了QGridLayout
    QVBoxLayout *mainLayout;
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
    QLabel *userName;
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

    /******************************************************************/


    //窗体中按钮的普遍宽度
    const qint16 w = 50;
    //窗体中按钮的普遍高度
    const qint16 h = 50;
    //普遍尺寸
    QSize *sz = new QSize(w, h);

    //半按钮宽度
    const qint16 hw = w /2;
    //半按钮高度
    const qint16 hh = h / 2;
    //半尺寸
    QSize *hsz = new QSize(hw, hh);














    //测试用的，等会删除
    QPushButton *testText;
    QPushButton *testBtn;


};

#endif // WIDGET_H
