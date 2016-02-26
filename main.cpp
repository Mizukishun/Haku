#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置窗体的Icon？？？？
    //a.setWindowIcon(QPixmap(":/images/haku_icon_25.png"));

    Widget w;
    w.show();

    return a.exec();
}
