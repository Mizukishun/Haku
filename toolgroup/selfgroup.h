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
#include <QFileDialog>
#include <QListWidget>

class SelfGroup : public QWidget
{
    Q_OBJECT
public:
    explicit SelfGroup(QWidget *parent = 0);

signals:
    //新建完成信号
    void filesuccess();

public slots:
    //更改箭头的样式
    void arrowChange();
    //打开文件选择对话框
    //void showAudioFile();
    //另外一种歌曲选择的方式
    void showFiles();

private:
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

    //箭头字符
    QString arrowString = "> ";



    /********************************************************/
    //以下是用于显示歌词名称列表的窗体，首先打开文件选择对话框，之后在选择了歌曲文件后
    //将其名称等信息保存到这个新窗体中，可能要用到模型-代理-视图

    //整个歌曲列表的布局
    QVBoxLayout *widgetLayout;
    //整个歌曲列表
    QWidget *test_widget;

    //存放歌曲列表的QListWidget组件
    QListWidget *test_list;
    //存放歌曲路径
    QString musicPath;
    QStringList musicPathList;
    //存放歌曲名
    QString musicName;
    QStringList musicNameList;





};

#endif // SELFGROUP_H
