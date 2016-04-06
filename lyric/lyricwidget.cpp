#include "lyricwidget.h"

LyricWidget::LyricWidget(QWidget *parent) : QWidget(parent)
{
    //设置歌词窗体的颜色为透明
    p.setColor(QPalette::Background, QColor(0, 0, 0, 0));
    setPalette(p);

    //建立歌词文件对象LyricFile
    Ly = new LyricFile();

    //创建歌词窗体的界面
    createLyricInterface();

//    //创建QTimer对象，使歌词随其变化滚动，测试用，之后删除
//    testTimer = new QTimer(this);
//    connect(testTimer, SIGNAL(timeout()), this, SLOT(scrollShow()));
//    testTimer->start(1000);



}

//创建歌词窗体的界面
void LyricWidget::createLyricInterface()
{
    //歌词窗体的总体布局
    lyricLayout = new QHBoxLayout(this);
    lyricLayout->setSpacing(0);
    lyricLayout->setMargin(0);
    //为了使歌词居中显示，首先是在最外层这个布局的开始及结束添加左右两个
    lyricLayout->addStretch();

    //真正装载歌词的框架
    lyricFrame = new QFrame;
    //添加歌词的布局
    lyFrameLayout = new QVBoxLayout(lyricFrame);
    lyFrameLayout->setSpacing(20);
    lyFrameLayout->setMargin(10);
    //在歌词框架布局的最上面添加一个addStretch()
    lyFrameLayout->addStretch();

    /***************************歌词的添加就在这两条长横注释之间进行吧!***********************/

    //设置窗体所有按钮的文本颜色（初始的）
    QPalette p;
    p.setColor(QPalette::ButtonText, QColor(0, 0, 255, 255));
    setPalette(p);


    //添加显示九条歌词的按钮(其中的文本之后得删除!!!
    lyBtn1 = new QPushButton();
    lyBtn2 = new QPushButton();
    lyBtn3 = new QPushButton();
    lyBtn4 = new QPushButton();
    lyBtn5 = new QPushButton();
    lyBtn6 = new QPushButton();
    lyBtn7 = new QPushButton();
    lyBtn8 = new QPushButton();
    lyBtn9 = new QPushButton();

    //所有按钮都设置为setFlat(true);
    lyBtn1->setFlat(true);
    lyBtn2->setFlat(true);
    lyBtn3->setFlat(true);
    lyBtn4->setFlat(true);
    lyBtn5->setFlat(true);
    lyBtn6->setFlat(true);
    lyBtn7->setFlat(true);
    lyBtn8->setFlat(true);
    lyBtn9->setFlat(true);

    //所有按钮都设置为不可按的
    lyBtn1->setEnabled(false);
    lyBtn2->setEnabled(false);
    lyBtn3->setEnabled(false);
    lyBtn4->setEnabled(false);
    lyBtn5->setEnabled(false);
    lyBtn6->setEnabled(false);
    lyBtn7->setEnabled(false);
    lyBtn8->setEnabled(false);
    lyBtn9->setEnabled(false);


    //向歌词框架添加显示九条歌词的按钮
    lyFrameLayout->addWidget(lyBtn1);
    lyFrameLayout->addWidget(lyBtn2);
    lyFrameLayout->addWidget(lyBtn3);
    lyFrameLayout->addWidget(lyBtn4);
    lyFrameLayout->addWidget(lyBtn5);
    lyFrameLayout->addWidget(lyBtn6);
    lyFrameLayout->addWidget(lyBtn7);
    lyFrameLayout->addWidget(lyBtn8);
    lyFrameLayout->addWidget(lyBtn9);

    //替换上初始的歌词
    ki = 0;
    initShowLyric();


    /******************************不要把代码再添加到后面了，在上面去添加代码********************/

    //在歌词框架的最下面添加addStretch()
    lyFrameLayout->addStretch();
    //把装载歌词的框架添加到最外层布局上
    lyricLayout->addWidget(lyricFrame);
    //最后，在最外层布局的最右边添加一个addStretch()
    lyricLayout->addStretch();
}

//显示歌词
void LyricWidget::initShowLyric()
{
    //建立歌词文件对象LyricFile
    //Ly = new LyricFile();



    //暂时只是做测试用，只显示前面的几句歌词，还没有实现随时间滚动歌词显示的效果，之后得补上！！！
    /* 解释下，Ly->totalLyric.at(1)得到第二句歌词（测试用，暂时忽略掉第一句歌词）QStringList，
     * 所以第二个at(1)就是一句歌词中的歌词部分，因为at(0)是时间部分了
     * */

    //ki = 0;
    ly1 = Ly->totalLyric.value(ki).value(1);
    ly2 = Ly->totalLyric.value(ki+1).value(1);
    ly3 = Ly->totalLyric.value(ki+2).value(1);
    ly4 = Ly->totalLyric.value(ki+3).value(1);
    ly5 = Ly->totalLyric.value(ki+4).value(1);
    ly6 = Ly->totalLyric.value(ki+5).value(1);
    ly7 = Ly->totalLyric.value(ki+6).value(1);
    ly8 = Ly->totalLyric.value(ki+7).value(1);
    ly9 = Ly->totalLyric.value(ki+8).value(1);


    //设置每个歌词按钮的歌词文本显示
    lyBtn1->setText(ly1);
    lyBtn2->setText(ly2);
    lyBtn3->setText(ly3);
    lyBtn4->setText(ly4);
    lyBtn5->setText(ly5);
    lyBtn6->setText(ly6);
    lyBtn7->setText(ly7);
    lyBtn8->setText(ly8);
    lyBtn9->setText(ly9);

}

//随计时器滚动歌词的显示
void LyricWidget::scrollShow()
{
    //每次调用都会增加
    ki += 1;

    //如果歌词还有的话,就可以滚动显示歌词
    if(ki < Ly->totalLyric.size() - 4)
    {
        initShowLyric();
    }


}

//隐藏全部歌词
void LyricWidget::hideAllLyric()
{
    lyBtn1->hide();
    lyBtn2->hide();
    lyBtn3->hide();
    lyBtn4->hide();
    lyBtn5->hide();
    lyBtn6->hide();
    lyBtn7->hide();
    lyBtn8->hide();
    lyBtn9->hide();
}

//没有歌词，就显示相应的通知
void LyricWidget::havingNoLyric()
{
    lyBtn1->setText(tr(""));
    lyBtn2->setText(tr(""));
    lyBtn3->setText(tr(""));
    lyBtn4->setText(tr(""));
    lyBtn5->setText(tr("该歌曲暂无歌词"));
    lyBtn6->setText(tr(""));
    lyBtn7->setText(tr(""));
    lyBtn8->setText(tr(""));
    lyBtn9->setText(tr(""));
}

//从主窗体接收了positionChanged(qint64)信号，知道了歌曲的已播放时间
//滚动播放歌词
void LyricWidget::lyricScroll(qint64 playedTime)
{
    //测试用，看是否会持续把已播放时间传递过来
    //scrollShow();

    //如果记录歌词时间的lyricTimeList中还有歌词
    if(!Ly->lyricTimeList.isEmpty())
    {
        qint64 firstValue = Ly->lyricTimeList.first();
        if(playedTime >= firstValue)
        {
            //就滚动一格
            scrollShow();

            //为了防止多次比较同一个歌词的时间值，所以第一个时间值从QList中删除
            Ly->lyricTimeList.removeFirst();
        }
    }

    QPalette p2;
    p2.setColor(QPalette::ButtonText, QColor(255, 0, 0, 255));
    lyBtn4->setPalette(p2);
    //lyBtn4->setMinimumHeight(20);

}
