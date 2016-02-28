#include "lyframe.h"

lyFrame::lyFrame(QWidget *parent)
    : QFrame(parent)
{
    lyWidget = new LyricWidget();


//    lyfText = new QTextEdit;
//    lyfBtn = new QPushButton;
//    lyfBtn->setText(tr("Hello Haku"));
    lyfLayout = new QVBoxLayout(this);
    lyfLayout->setMargin(0);
    lyfLayout->setSpacing(0);
    lyfLayout->addWidget(lyWidget);
//    lyfLayout->addWidget(lyfText);
//    lyfLayout->addWidget(lyfBtn);


}

