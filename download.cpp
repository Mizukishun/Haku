#include "download.h"
#include <QPalette>

Download::Download(QWidget *parent) : QWidget(parent)
{
    //设置边框
    setContentsMargins(0, 0, 0, 0);
    //设置固定的宽度
    setFixedWidth(300);
    //设置背景颜色
    QPalette Dp;
    Dp.setColor(QPalette::Background, Qt::white);
    setWindowOpacity(1);
    setAutoFillBackground(true);
    setPalette(Dp);

    //创建界面布局
    createInterface();

}

//创建下载窗体的界面布局
void Download::createInterface()
{
    //主布局
    mainLayout = new QVBoxLayout(this);

    //测试用的，之后删除
    testLayout = new QHBoxLayout;
    progressbar = new QProgressBar;
    progressbar->setValue(0);
    testLayout->addWidget(progressbar);
    DSwidget = new DisplayWidget(this);
    urlLine = new QLineEdit;
    testUrlLabel = new QLabel;
    connect(DSwidget, SIGNAL(progressValue(qint64, qint64)),
            this, SLOT(updateProgressBar(qint64, qint64)));
    connect(DSwidget, SIGNAL(testDownloadUrl(QString)), this, SLOT(urlTestLine(QString)));

    mainLayout->addLayout(testLayout);
    mainLayout->addWidget(urlLine);
    mainLayout->addWidget(testUrlLabel);
    mainLayout->addWidget(DSwidget);
    mainLayout->addStretch();

    DSwidget->hide();

}

//测试用，更新测试用的进度条的值
void Download::updateProgressBar(qint64 updateValue, qint64 max)
{
    progressbar->setMaximum(max);
    progressbar->setValue(updateValue);
}

//测试用，看是否获得了正确的歌曲下载地址
void Download::urlTestLine(QString s)
{
    urlLine->setText(s);
    testUrlLabel->setText(s);
}
