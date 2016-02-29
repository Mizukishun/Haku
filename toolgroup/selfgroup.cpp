#include "selfgroup.h"
#include <QSizePolicy>

SelfGroup::SelfGroup(QWidget *parent) : QWidget(parent)
{
    //设置整个窗体的背景颜色
    QPalette sGPalette;
    sGPalette.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(sGPalette);

    //第一个开头横杠
    groupName = new QPushButton;
    groupName->setFlat(true);
    //分组名在之后要用%1.arg()这样的形式进行重新设置
    groupName->setText(tr("%1   新建列表").arg(arrowString));

    connect(groupName, SIGNAL(clicked()), this, SLOT(arrowChange()));


    threeLine = new QPushButton;
    threeLine->setFlat(true);
    //这个按钮的图标在之后也要重新设置
    threeLine->setIcon(QPixmap(":/images/playQueueIcon.png"));

    startLayout = new QHBoxLayout;
    startLayout->setMargin(0);
    startLayout->setSpacing(0);
    startLayout->addWidget(groupName);
    startLayout->addStretch();
    startLayout->addWidget(threeLine);

    //初始的窗体及其中元素布局
    initWidget = new QWidget;

    newMusic = new QPushButton;
    newMusic->setFlat(true);
    newMusic->setText(tr("+ 添加本地歌曲"));
    //连接鼠标单击事件与打开文件选择对话框事件
    //connect(newMusic, SIGNAL(clicked()), this, SLOT(showAudioFile()));
    connect(newMusic, SIGNAL(clicked()), this, SLOT(showFiles()));
    connect(this, SIGNAL(filesuccess()), this, SLOT(arrowChange()));

    newMusicFile = new QPushButton;
    newMusicFile->setFlat(true);
    newMusicFile->setText(tr("+ 添加本地歌曲文件夹"));

    //为了使得按钮显示在中央，故多加了一层布局
    QHBoxLayout *initLayout1 = new QHBoxLayout();
    initLayout1->addStretch();
    initLayout1->addWidget(newMusic);
    initLayout1->addStretch();
    QHBoxLayout *initLayout2 = new QHBoxLayout();
    initLayout2->addStretch();
    initLayout2->addWidget(newMusicFile);
    initLayout2->addStretch();

    initLayout = new QVBoxLayout(initWidget);
    initLayout->addLayout(initLayout1);
    initLayout->addLayout(initLayout2);

    //初始时这个窗体是显示出来的，只有当添加了歌曲文件后才隐藏
    //initWidget->hide();

    /**********************************************************************************/
    //以下是测试用，测试少数歌曲时的添加
    //音乐歌曲列表的窗体

    test_list = new QListWidget;


    test_widget = new QWidget;
    widgetLayout = new QVBoxLayout(test_widget);
    widgetLayout->setMargin(0);
    widgetLayout->setSpacing(0);
    widgetLayout->addWidget(test_list);
    test_widget->hide();

    /**********************************************************************************/
    //整体窗体的布局
    selfGroupLayout = new QVBoxLayout(this);
    selfGroupLayout->setSpacing(0);
    selfGroupLayout->setMargin(0);

    selfGroupLayout->addLayout(startLayout);
    selfGroupLayout->addWidget(test_widget);
    selfGroupLayout->addWidget(initWidget);

};

//定义槽函数arrowChange(),这里之后还需添加隐藏/显示歌曲列表的功能
//所以后面害的继续补充这个函数！！！！
void SelfGroup::arrowChange()
{
    if(arrowString == "> ")
    {
        arrowString = "v ";
        groupName->setText(tr("%1   新建列表").arg(arrowString));
        initWidget->hide();
        test_widget->show();
    }
    else
    {
        arrowString = "> ";
        groupName->setText(tr("%1   新建列表").arg(arrowString));
        initWidget->hide();
        test_widget->hide();
    }

}



void SelfGroup::showFiles()
{
    musicPathList = QFileDialog::getOpenFileNames(this, tr("Select Music"), "/",
                                              tr("Music files(*.mp3 *.ape *.flac)"));
    foreach(const QString s, musicPathList)
    {
        musicName = QFileInfo(s).fileName();
        musicNameList.append(musicName);
    }

    test_list->addItems(musicNameList);

    emit filesuccess();
    //test_widget->show();
}


