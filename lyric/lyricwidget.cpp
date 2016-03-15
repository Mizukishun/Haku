#include "lyricwidget.h"

LyricWidget::LyricWidget(QWidget *parent) : QWidget(parent)
{
    //设置歌词窗体的颜色为透明
    p.setColor(QPalette::Background, QColor(0, 0, 0, 0));
    setPalette(p);

    //创建歌词窗体的界面
    createLyricInterface();

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
    p.setColor(QPalette::ButtonText, QColor(255, 0, 0, 255));
    setPalette(p);


    //添加显示九条歌词的按钮(其中的文本之后得删除!!!
    lyBtn1 = new QPushButton(tr("歌词2：设置成长度不一样的"));
    lyBtn2 = new QPushButton(tr("歌词1："));
    lyBtn3 = new QPushButton(tr("歌词3：这样就可以更好第进行测试，看能不能显示出来"));
    lyBtn4 = new QPushButton(tr("歌词4：这丫也行"));
    lyBtn5 = new QPushButton(tr("歌词5：这一条歌词就设置为正在播放的歌词吧"));
    lyBtn6 = new QPushButton(tr("歌词6：这样就行了"));
    lyBtn7 = new QPushButton(tr("歌词7：怎样"));
    lyBtn8 = new QPushButton(tr("歌词8:弄一个好长的歌词这样就可以更好的第装逼了哈哈哈哈哈哈哈哈哈哈"));
    lyBtn9 = new QPushButton(tr("歌词9:算了"));

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




//    //主标签，即正在播放的那句歌词
//    mainLabel = new QLabel;

//    mainLabel->setText(tr("正在播放的歌词"));


//    //测试用，看是否有在主界面中显示出歌词窗体
//    testBtn1 = new QPushButton(tr("测试歌词窗体，,测试按钮的歌词长度是否会不能显示，所以设置长一点"));
//    testBtn1->setFlat(true);

//    testBtn2 = new QPushButton(tr("测试歌词是否用按钮显示"));
//    testBtn2->setFlat(true);
//    //测试按钮不能按
//    testBtn2->setEnabled(false);
//    //尝试设置按钮的字体颜色
//    QPalette p;
//    p.setColor(QPalette::ButtonText, QColor(255, 0, 0, 255));
//    testBtn2->setPalette(p);

//    testLabel1 = new QLabel(tr("第一个测试标签,顺带测试歌词长度"));
//    testLabel2 = new QLabel(tr("第二个测试标签"));

//    lyFrameLayout->addWidget(testBtn1);
//    lyFrameLayout->addWidget(testBtn2);
//    lyFrameLayout->addWidget(testLabel1);
//    lyFrameLayout->addWidget(mainLabel);
//    lyFrameLayout->addWidget(testLabel2);

    //testLabel1->hide();



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





    /******************************不要把代码再添加到后面了，在上面去添加代码********************/

    //在歌词框架的最下面添加addStretch()
    lyFrameLayout->addStretch();
    //把装载歌词的框架添加到最外层布局上
    lyricLayout->addWidget(lyricFrame);
    //最后，在最外层布局的最右边添加一个addStretch()
    lyricLayout->addStretch();
}
