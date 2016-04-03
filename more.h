#ifndef MORE_H
#define MORE_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QProcess>
#include <QUrl>
#include <QDesktopServices>
#include <QImage>
#include <QPixmap>



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
    //启动默认浏览器打开我这个Haku项目的GitHub页面
    void openMyGitHub();

private:
    //点击这个按钮就启动酷狗音乐
    QPushButton *openKugouBtn;
    //点击这个按钮启动默认浏览器，打开我的GitHub主页
    QPushButton *openMyGitHubBtn;

    //主布局
    QVBoxLayout *mainLayout;
    //第一行的小布局
    QHBoxLayout *firstLineLayout;

    //要启动的酷狗进程
    QProcess *kugouProcess;

};

#endif // MORE_H
