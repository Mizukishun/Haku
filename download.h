#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

//暂时只是测试用，看是否有在下载歌曲
#include <QProgressBar>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "download/displaywidget.h"
#include "lyric/lyricfile.h"

class Download : public QWidget
{
    Q_OBJECT
public:
    explicit Download(QWidget *parent = 0);

private:
    //创建下载窗体的界面布局
    void createInterface();

signals:

public slots:
    //测试用，之后删除
    void updateProgressBar(qint64, qint64);
    void urlTestLine(QString);
    void lyricTest();

private:
    /*******************************下载窗体的布局*********************/
    QVBoxLayout *mainLayout;

    //测试用，之后删除
    QHBoxLayout *testLayout;
    QProgressBar *progressbar;
    DisplayWidget *DSwidget;
    QLineEdit *urlLine;
    QLabel *testUrlLabel;

    //测试歌词的解析是否正确，是否能够显示
    QLineEdit *lyLine1;
    QTextEdit *lyText1;
    QPushButton *lyBtn;
    QString teStr;

    LyricFile *lyT;
};

#endif // DOWNLOAD_H
