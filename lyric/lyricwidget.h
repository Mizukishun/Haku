#ifndef LYRICWIDGET_H
#define LYRICWIDGET_H

/* 显示歌词的窗体，要嵌入到主界面中
 *
 * */

#include <QWidget>
#include <QLabel>
#include <QPalette>
#include <QPainter>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>



class LyricWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LyricWidget(QWidget *parent = 0);

private:
    //创建歌词窗体的布局
    void createLyricInterface();

signals:

public slots:

private:
    //设置歌词窗体的背景色
    QPalette p;
    //歌词窗体的主体布局
    QHBoxLayout *lyricLayout;
    //为了使歌词标签能够居中显示在窗体中，故再增添两层布局
    //真正装载歌词的框架
    QFrame *lyricFrame;
    //歌词的真正显示布局
    QVBoxLayout *lyFrameLayout;

    //显示九条歌词，每条歌词都用按钮来表示（用按钮是为了能够居中显示歌词）
    QPushButton *lyBtn1;
    QPushButton *lyBtn2;
    QPushButton *lyBtn3;
    QPushButton *lyBtn4;
    QPushButton *lyBtn5;
    QPushButton *lyBtn6;
    QPushButton *lyBtn7;
    QPushButton *lyBtn8;
    QPushButton *lyBtn9;

    //主标签，即正在播放的那句歌词,但暂时不确定是否用QLabel
    QLabel *mainLabel;






    //测试用，看是否将窗体放好了,之后都得删除
    QPushButton *testBtn1;
    QPushButton *testBtn2;
    QLabel *testLabel1;
    QLabel *testLabel2;




};

#endif // LYRICWIDGET_H
