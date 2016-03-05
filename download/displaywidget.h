#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

//这个部件主要用于显示下载的内容，是搜索后显示出来的窗口
//尽量把所有的歌曲下载的功能都在这个类中实现吧

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QTreeView>
#include <QPalette>
#include <QTextEdit>


#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtNetwork>
#include <QUrl>
#include <QFile>
#include <QFileInfo>



class DisplayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DisplayWidget(QWidget *parent = 0);

private:
    //创建主界面
    void createInterface();

    //测试用,获取歌曲的信息
    void requireMusicInfo(QString);


signals:
    //void searchMusics(QString);

public slots:
    void search(QString);

private:
    /************************主界面上的元素***********************/
    //主布局
    QVBoxLayout *mainLayout;

    //播放、添加、下载按钮一栏
    QFrame *topFrame;
    QHBoxLayout *topLayout;
    QLabel *topLabel;
    QPushButton *topPlayBtn;
    QPushButton *topAddBtn;
    QPushButton *topDownloadBtn;

    //搜索出来的歌曲显示框架
    QFrame *displayFrame;
    //框架中的布局
    QVBoxLayout *displayFrameLayout;
    //框架中的顶栏
    QHBoxLayout *firstLayout;
    QCheckBox *firstCheckBox;
    QPushButton *firstMusicNameBtn;
    QPushButton *firstAlbumBtn;
    QPushButton *firstTimeBtn;
    QPushButton *firstControlBtn;

    //框架中的歌曲显示
    QHBoxLayout *secondLayout;              //之后可能要被其他船体替代掉
    //测试用，之后删除
    QCheckBox *secondTestCheckBox;
    QLineEdit *secondTestLineEdit;
    //测试用，用于展示获得的歌曲的各项信息
    QTextEdit *TextEdit1;
    QLineEdit *LineEdit1;
    QLineEdit *LineEdit2;
    QTextEdit *TextEdit2;
    QLineEdit *LineEdit3;
    QTextEdit *TextEdit3;


    /************************************歌曲的信息元素等**********************************/
    //要搜索的歌曲名
    QString searchMusic;
    //百度音乐接口的地址
    QString url_baidu_music;

    /***********************************网络相关的元素************************************/




public:
    //获得的歌曲链接地址,因为可能要传递其他窗体进行播放，所以定义成public的
    QString MusicLink;





};

#endif // DISPLAYWIDGET_H
