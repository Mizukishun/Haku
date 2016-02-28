#ifndef LYFRAME_H
#define LYFRAME_H

#include <QFrame>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include "lyricwidget.h"

class lyFrame : public QFrame
{
    Q_OBJECT
public:
    lyFrame(QWidget *parent = 0);

private:
    QVBoxLayout *lyfLayout;

    LyricWidget *lyWidget;

};

#endif // LYFRAME_H
