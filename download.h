#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>



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


private:

};

#endif // DOWNLOAD_H
