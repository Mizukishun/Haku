#ifndef LYRICWIDGET_H
#define LYRICWIDGET_H

//这个是歌词显示的窗口

#include <QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFrame>

class LyricWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LyricWidget(QWidget *parent = 0);

signals:

public slots:

private:


};

#endif // LYRICWIDGET_H
