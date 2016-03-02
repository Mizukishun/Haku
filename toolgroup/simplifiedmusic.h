#ifndef SIMPLIFIEDMUSIC_H
#define SIMPLIFIEDMUSIC_H

/*这个类用于“新建列表”那一横
 */

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFrame>
#include <QMouseEvent>
#include <QLabel>

class SimplifiedMusic : public QWidget
{
    Q_OBJECT
public:
    explicit SimplifiedMusic(QWidget *parent = 0);


protected:
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *);
    //下面三个鼠标事件暂时不同实现，但还是写出来
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);


private:
    //创建主界面，要定义成私有的吗？？？
    void createInterface();

signals:

public slots:
    //切换图标
    void transformIcon();

private:
    //展开关闭按钮
    QPushButton *openAndCloseBtn;
    //列表名按钮
    QPushButton *listNameBtn;
    //列表菜单按钮
    QPushButton *listMenuBtn;

    //布局
    QHBoxLayout *listLayout;

    //一个布尔值，用于判断是打开、还是关闭列表，
    //其实也就是用于切换openAndCloseBtn用哪个图标而已,默认是关闭的
    bool closeBtn = true;


};

#endif // SIMPLIFIEDMUSIC_H
