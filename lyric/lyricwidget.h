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

#include "lyricfile.h"



class LyricWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LyricWidget(QWidget *parent = 0);

private:
    //创建歌词窗体的布局
    void createLyricInterface();

    //显示歌词(暂时还实现随时间滚动的效果，之后补上
    void showLyric();

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


    //歌词文件对象
    LyricFile *Ly;
    //一句歌词(包含时间及歌词，at(1)才是歌词，at(0)是时间字符串）
    //QStringList *singleLyric;






};

#endif // LYRICWIDGET_H
