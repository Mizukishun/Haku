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
#include <QTimer>

#include "lyricfile.h"



class LyricWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LyricWidget(QWidget *parent = 0);

    //隐藏全部歌词
    void hideAllLyric();

    // 没有歌词就显示相应的通知
    void havingNoLyric();

private:
    //创建歌词窗体的布局
    void createLyricInterface();

    //初始显示的歌词
    void initShowLyric();

    //设置按钮要显示的文本
    void showLyricOnBtn();

signals:


public slots:
    //随计时器而滚动歌词的显示
    void scrollShow();


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

    //每一个按钮对应的一句歌词
    QString ly1;
    QString ly2;
    QString ly3;
    QString ly4;
    QString ly5;
    QString ly6;
    QString ly7;
    QString ly8;
    QString ly9;

    //歌词文件对象
    LyricFile *Ly;

    //测试用，计时器对象，使歌词随其而变化滚动
    QTimer *testTimer;

    //计数对象，使得随时间变化能够替换为不同的歌词
    qint8 ki;

    //一句歌词(包含时间及歌词，at(1)才是歌词，at(0)是时间字符串）
    //QStringList *singleLyric;






};

#endif // LYRICWIDGET_H
