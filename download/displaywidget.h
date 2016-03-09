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
#include <QScrollBar>
#include <QScrollArea>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtNetwork>
#include <QUrl>
#include <QFile>
#include <QFileInfo>
#include <QDir>

#include <QJsonArray>
#include <QJSonDocument>
#include <QJSonObject>
#include <QJsonValue>
#include <QJsonParseError>

#include "singledisplay.h"
#include "toolgroup/singlemusic.h"


class DisplayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DisplayWidget(QWidget *parent = 0);

    //创建显示出来的歌曲列表
    void createMusicListD();
    //关闭来自这个窗体的歌曲的播放，以方便其他窗体歌曲的播放
    void closeDWmusic();

private:
    //创建主界面
    void createInterface();

    //测试用,获取歌曲的信息
    void requireMusicInfo(QString);

    //解析获得的歌曲信息
    void parseReply(QString);

    //在每次搜索时都要把前面搜索过的内容清除掉，防止对本次搜索的干扰
    void clearList();

    //处理用song.play方法获得歌曲信息，其中包含了歌曲的播放地址信息
    void parseSongInfo(QString);



    //播放歌曲，（其实就是要将歌曲地址传递到主程序中的，让主程序播放)
    //void playMusic(QString musicName);

    //通过歌曲名找到歌曲id
    QString searchMusicID(QString musicname);

    //根据歌曲id找到歌曲的播放地址,根据的是songplay方法
    void songPlay(QString sid);




    /***************************歌曲下载************************/


    //根据歌曲名先找到songid再找到歌曲的下载地地址，根据的是song.downWeb方法
    void songDownloadLink(QString songName);
    //处理从网络获取的JSon格式的字符串信息，从中解析出歌曲的下载地址
    void parseDownloadInfo(QString);

    /**********************************************************/


signals:
    //void searchMusics(QString);
    //发送信号给上层窗体，让其将歌曲传递给上一层窗体，进而播放该首歌曲
    void DWplayMusic(SingleMusic*, bool);

    //通知secFrame显示搜索结果
    void okToShow(bool);

    //通知其他窗体，下载已经完成
    void downloadOK(bool);

    //通知其他窗体下载的进度
    void progressValue(qint64, qint64);

    //测试用，看是否得到正确的歌曲下载地址
    void testDownloadUrl(QString);

public slots:
    void search(QString);

    //处理QNetworkAccessManager对象的finished信号的槽函数
    void handFinished(QNetworkReply*);
    //获取歌曲的试听的地址
    void getAuditionLink(QNetworkReply*);
    //接收下层小窗体的信号，播放其上的歌曲
    void DWplayThisMusic(QString musicname);
    //当滚动条滑动，值改变时，就隐藏一些歌曲，而现实另外一些歌曲。
    void showSpecial(int);

    void playMusic(QNetworkReply*);

    //下载歌曲,要下载指定歌曲，只要想下面这个函数传递一个歌曲名
    void songDownload(QString songName);

    //获取songid对应的下载地址
    void receiveDownloadLink(QNetworkReply*);
    //正在下载歌曲
    void isDownloading();
    //更新下载进度条
    void updateDownloadProgress(qint64, qint64);
    //下载完成
    void downloadFinished();

    //以下三个函数是测试用，看是否需要再次请求连接网络才能下载数据
    void TestisDownloading();
    void TestupdateDownloadProgress(qint64, qint64);
    void TestdownloadFinished();

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
    QVBoxLayout *secondLayout;              //之后可能要被其他船体替代掉
    //滚动条
    QScrollBar *DWscrollbar;

    //包围了滚动栏、搜索歌曲显示框架的布局
    QHBoxLayout *scrollLayout;
    QScrollArea *DWscrollArea;

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

    QByteArray sendData2;
    QString sendURL2;
    QNetworkAccessManager *manager2;
    QNetworkRequest *requester2;

    QNetworkAccessManager *manager3;
    QNetworkRequest *requester3;
    QNetworkReply *replyer3;




    //根据歌曲的下载地址下载相应的歌曲所需网络对象
    QNetworkReply *downloadReply;
    QNetworkRequest *downloadRequester;
    QNetworkAccessManager *downloadManager;         //这个会不会太多余了？？？
    QUrl downloadUrl;
    QString downloadUrlString;
    QString downloadMusicSize;


//    //下面为测试用，之后删除
    QNetworkReply *downloadReplyTest;
    QNetworkAccessManager *downloadManagerTest;
    QNetworkRequest *downloadRequesterTest;

    //以下测试用，看是否获得了歌曲的下载地址
    QLineEdit *testUrlLineEdit;



    /********************搜索时search.catalogSug从网络获取的歌曲信息**************************/
    //歌曲名
    QList<QString> songnameList;
    //歌手名
    QList<QString> artistnameList;
    //歌曲的id,应该是与歌曲名一一对应的（在search.catalogSug方法中）
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

    /***********************************************************************************/

    //控制当第一次单击鼠标时并不播放，只有单第二次单击时才播放
    int firstClick = -1;







public:
    //获得的歌曲链接地址,因为可能要传递其他窗体进行播放，所以定义成public的
    QString AuditionLink = "test";
    //播放的这首歌的相应的大壁纸地址
    QString pic_hugeLink;
    //播放的这首歌的歌词地址
    QString lrclink;
    //要试听的歌曲id
    QString AuditionID;

    //要播放的歌曲名，应该控制只有一首歌曲在播放
    QString DWmusic;

    //获取播放的功能
    SingleMusic *DWsingleMusic;

    //另存一份搜索出的歌曲信息,便于访问布局中的某个特定歌曲窗体
    QList<SingleDisplay *> SDnumberList;
    //搜索出的歌曲的数目
    int size;

    //在发送信号给上层窗体的同时，设置为true，说明要播放这首歌曲，其他正在播放的要歌曲要关闭
    bool DWoktoplay;


    //要下载的歌曲名
    QString downloadMusicName;

    //下载歌曲时，不同音质的音乐对应不同的下载地址以及大小
    //用QList<>将其一一对应起来
    QList<QString> file_bitrate_str;
    QList<QString> file_link_str;
    QList<QString> file_size_str;
    //下载的这首歌曲对应的歌词的地址，（只有一个）
    QString downloadLycLink;
    //这首歌曲的小图的地址（150*150大小）
    QString pic_bigLink;
    //这首歌曲的小图的地址(90*90大小）
    QString pic_smallLink;
    //下载到文件(以所下载的歌曲名命名）
    QFile *file;

    //这首歌曲总的要下载的大小
    qint64 totalSize;
    //已下载的大小
    qint64 downloadedSize;




};

#endif // DISPLAYWIDGET_H
