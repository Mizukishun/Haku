#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

//暂时只是测试用，看是否有在下载歌曲
#include <QProgressBar>
#include "download/displaywidget.h"

class Download : public QWidget
{
    Q_OBJECT
public:
    explicit Download(QWidget *parent = 0);

private:
    //创建下载窗体的界面布局
    void createInterface();

signals:

public slots:
    //测试用，之后删除
    void updateProgressBar(qint64, qint64);

private:
    /*******************************下载窗体的布局*********************/
    QVBoxLayout *mainLayout;

    //测试用，之后删除
    QHBoxLayout *testLayout;
    QProgressBar *progressbar;
    DisplayWidget *DSwidget;
};

#endif // DOWNLOAD_H
