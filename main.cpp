#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置窗体的Icon？？？？
    //a.setWindowIcon(QPixmap(":/images/haku_icon_25.png"));

    Widget w;
    w.show();

    /*整个程序的退出是由关闭按钮实现的，但这其中转折了两次：
    **先是由closeBtn按钮的点击事件关联到Widget的quitEmit()槽函数，再由这个
    **槽函数发送Widget的quit()信号，再在从这里将Widget的quit()信号与整个程序的
    **退出事件关联一起
    */
    QObject::connect(&w, SIGNAL(quit()), &a, SLOT(quit()));

    return a.exec();
}
