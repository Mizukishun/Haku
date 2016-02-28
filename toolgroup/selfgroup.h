#ifndef SELFGROUP_H
#define SELFGROUP_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPalette>
#include <QPixmap>
#include <QFrame>

class SelfGroup : public QWidget
{
    Q_OBJECT
public:
    explicit SelfGroup(QWidget *parent = 0);

signals:

public slots:
    void arrowChange();

private:
    //开头的箭头
//    QPushButton *arrow;
    //开头的分组名
    QPushButton *groupName;
    //开头的三横线
    QPushButton *threeLine;
    //初始的窗体，在添加了歌曲之后要隐藏起来
    QWidget *initWidget;
    //整体的布局
    QVBoxLayout *selfGroupLayout;
    //开头的布局
    QHBoxLayout *startLayout;
    //初始窗体中的布局
    QVBoxLayout *initLayout;
    //初始窗体中的“添加本地歌曲"按钮
    QPushButton *newMusic;
    //初始窗体中的”添加本地歌曲文件夹"按钮
    QPushButton *newMusicFile;

    //字符
    QString arrowString = "> ";

};

#endif // SELFGROUP_H
