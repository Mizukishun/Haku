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

#include <QJsonArray>
#include <QJSonDocument>
#include <QJSonObject>
#include <QJsonValue>
#include <QJsonParseError>




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

    //解析获得的歌曲信息
    void parseReply(QString);


signals:
    //void searchMusics(QString);

public slots:
    void search(QString);

    //处理QNetworkAccessManager对象的finished信号的槽函数
    void handFinished(QNetworkReply*);

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
    QString url_baidu_api;

    /***********************************网络相关的元素************************************/
    //设置要发送的数据
    QByteArray sendData;
    //设置要发送到的链接
    QString sendURL;
    //设置网络接入管理对象
    QNetworkAccessManager *manager;
    //设置网络请求对象
    QNetworkRequest *requester;

    /*****************************搜索时从网络获取的歌曲信息******************************/
    //歌曲名
    QList<QString> songnameList;
    //歌手名
    QList<QString> artistnameList;
    //歌曲的id
    QList<QString> songidList;
    //是否有mv
    QList<bool> has_mvList;
    //encrypted_songid
    QList<QString> encrypted_songidList;

    //专辑的相关信息
    QList<QString> albumnameList;
    //专辑中的歌手图片地址
    QList<QString> album_artistpicList;
    //专辑的id
    QList<QString> albumidList;
    //专辑中的歌手名称
    QList<QString> album_artistnameList;

    //search.catalogSug方法所获得其他信息
    QList<QString> orderList;
    QList<QString> error_codeList;
    //歌手字段的信息
    //歌手的id
    QList<QString> artistidList;
    //歌手的图片
    QList<QString> artist_artistpicList;
    //
    QList<QString> artist_artistnameList;










public:
    //获得的歌曲链接地址,因为可能要传递其他窗体进行播放，所以定义成public的
    QString MusicLink;





};

#endif // DISPLAYWIDGET_H
