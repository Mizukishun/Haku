#ifndef MORE_H
#define MORE_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProcess>



class More : public QWidget
{
    Q_OBJECT
public:
    explicit More(QWidget *parent = 0);



private:
    //创建这个小窗口中的界面布局
    void createInterface();

signals:

public slots:
    //启动一个外部程序，这个函数是启动酷狗音乐
    void openKugou();

private:
    //点击这个按钮就启动酷狗音乐
    QPushButton *openKugouBtn;

    //主布局
    QVBoxLayout *mainLayout;

    //要启动的酷狗进程
    QProcess *kugouProcess;

};

#endif // MORE_H
