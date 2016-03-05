#include "displaywidget.h"

DisplayWidget::DisplayWidget(QWidget *parent) : QWidget(parent)
{
    createInterface();
}

void DisplayWidget::createInterface()
{
    /****************************设置窗体背景颜色等*********************/
    QPalette p;
    p.setColor(QPalette::Background, Qt::lightGray);
    setAutoFillBackground(true);
    setPalette(p);


    //*****************************最顶一栏**************************/
    topFrame = new QFrame;
    topLayout = new QHBoxLayout(topFrame);
    topLabel = new QLabel(tr("搜索歌曲的结果为"));
    topPlayBtn = new QPushButton(tr("播放"));
    //topPlayBtn->setFlat(true);
    topAddBtn = new QPushButton(tr("添加"));
    //topAddBtn->setFlat(true);
    topDownloadBtn = new QPushButton(tr("下载"));
    //topDownloadBtn->setFlat(true);
    topLayout->addWidget(topLabel);
    topLayout->addStretch();
    topLayout->addWidget(topPlayBtn);
    topLayout->addWidget(topAddBtn);
    topLayout->addWidget(topDownloadBtn);

    /*****************************显示搜索结果***********************/
    displayFrame = new QFrame;
    displayFrameLayout = new QVBoxLayout(displayFrame);

    //顶栏
    firstLayout = new QHBoxLayout;
    firstCheckBox = new QCheckBox(tr(" 全选"));
    firstMusicNameBtn = new QPushButton(tr("歌曲名"));
    firstMusicNameBtn->setFlat(true);
    firstAlbumBtn = new QPushButton(tr("专辑名"));
    firstAlbumBtn->setFlat(true);
    firstTimeBtn = new QPushButton(tr("时长"));
    firstTimeBtn->setFlat(true);
    firstControlBtn = new QPushButton(tr("操作"));
    firstControlBtn->setFlat(true);

    firstLayout->addWidget(firstCheckBox);
    firstLayout->addWidget(firstMusicNameBtn);
    firstLayout->addSpacing(50);
    firstLayout->addWidget(firstAlbumBtn);
    firstLayout->addWidget(firstTimeBtn);
    firstLayout->addWidget(firstControlBtn);

    //测试用，显示搜索出来的歌曲
    secondLayout = new QHBoxLayout;
    secondTestCheckBox = new QCheckBox;
    secondTestLineEdit = new QLineEdit;

    LineEdit1 = new QLineEdit;
    LineEdit2 = new QLineEdit;
    LineEdit3 = new QLineEdit;
    TextEdit1 = new QTextEdit;
    TextEdit2 = new QTextEdit;
    TextEdit3 = new QTextEdit;

    QVBoxLayout *testNetLayout = new QVBoxLayout;
    testNetLayout->addLayout(secondLayout);
    testNetLayout->addWidget(LineEdit1);
    testNetLayout->addWidget(LineEdit2);
    testNetLayout->addWidget(LineEdit3);
    testNetLayout->addWidget(TextEdit1);
    testNetLayout->addWidget(TextEdit2);
    testNetLayout->addWidget(TextEdit3);

    secondLayout->addWidget(secondTestCheckBox);
    secondLayout->addWidget(secondTestLineEdit);



    //将上面两个布局添加到显示搜索结果的框架中
    displayFrameLayout->addLayout(firstLayout);
    displayFrameLayout->addLayout(testNetLayout);

    /**********************************主布局**************************************/
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(topFrame);
    mainLayout->addWidget(displayFrame);
    mainLayout->addStretch();
}

//从网络上搜索歌曲,要如何处理呢？？？
void DisplayWidget::search(QString s)
{
    searchMusic = s;




}

void DisplayWidget::requireMusicInfo(QString rs)
{

}

