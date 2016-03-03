#ifndef SINGLEMUSIC_H
#define SINGLEMUSIC_H

/*这个类用于展示在双击了简略的歌曲名之后，播放具体的音乐并
 * 扩展开来的界面，当播放音乐是要同时显示该首音乐的总时长
 * 以及已播放的时长，每次双击这个界面都会从头开始播放
 */

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QMediaPlayer>
#include <QMouseEvent>

class SingleMusic : public QWidget
{
    Q_OBJECT
public:
    explicit SingleMusic(QWidget *parent = 0);
    ~SingleMusic();

private:
    //创建主界面的函数, 要定义成私有的吗？？？
    void createInterface();
    //创建QMediaPlayer对象，并修改界面上的按钮的文本显示
    void createObject();

signals:
    void OkToPlay(SingleMusic *);

public slots:
    //重载鼠标双击事件,使得重头开始播放该首音乐
    void mouseDoubleClickEvent(QMouseEvent *);
    //重载鼠标单击事件，如果单击了，则说明这首可以进行播放，而其他的歌就不能播放
    void mousePressEvent(QMouseEvent *);

    //控制音乐的播放与暂停
    void playAndPause();
    //计算歌曲的总时长
    void musicLength(qint64);
    //计算歌曲已播放的时间
    void musicPlayed(qint64);

    //恢复初始状态的界面
    void resetGUI();



private:
    /*********************************按钮、标签的定义************************/
    //加号标识
    QPushButton *AdditionBtn;
    //歌手图片(统一用Haku标识
    QPushButton *musicianBtn;


    //歌曲名右边的歌曲总时长标签，音乐播放时需要隐藏
    QLabel *musicNameLengthLabel;                   //需显示或隐藏

    //以下按钮标签需添加到框架内，统一隐藏和显示！
    //喜爱按钮
    QPushButton *loveBtn;
    //已下载按钮
    QPushButton *downloadedBtn;
    //删除按钮
    QPushButton *deleteBtn;
    //详细信息按钮
    QPushButton *detailBtn;



    /**********************************布局*****************************/
    //右下侧小布局
    QHBoxLayout *rightBottomLayout;
    //右下侧的小布局，一开始是隐藏的，只有当播放音乐时才显示出来
    QFrame *rightBottomFrame;                       //初始隐藏，音乐播放时需显示出来

    //歌曲名与歌曲总时长的布局
    QHBoxLayout *musicNameLayout;
    //右侧布局
    QVBoxLayout *rightLayout;
    //总体布局
    QHBoxLayout *mainLayout;

    /*********************************音乐播放*******************************/
public:
    //歌曲名按钮
    QLabel *musicNameBtn;
    //保存单首歌曲路径
    QString SingleMusicPath;
    //保存单首歌曲名
    QString SingleMusicName;

    //已播放时长
    QLabel *playedLengthLabel;
    //音乐总时长
    QLabel *musicLengthLabel;

    //保存歌曲总时长，供其它部件使用
    qint64 musicTotalTime;
    //保存歌曲已播放时长，供其它部件使用
    qint64 musicPlayedTime;

    //在这个最底层窗体中定义一个QMediaPlayer对象，由它来控制歌曲的播放
    QMediaPlayer *player;

    //激活窗体，其实就是创建QMediaPlayer对象，并修改时长等按钮的文本
    void active();

    //如果选中(或者说单击）了这首歌，就可以进行播放,默认是不播放的
    bool ok;





};

#endif // SINGLEMUSIC_H
