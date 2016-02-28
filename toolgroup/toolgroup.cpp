#include "toolgroup.h"
#include <QPalette>
#include "selfgroup.h"

ToolGroup::ToolGroup(QWidget *parent)
    : QToolBox(parent)
{
    //设置窗体的背景颜色
    QPalette tpp;
    tpp.setColor(QPalette::Window, Qt::black);
    setAutoFillBackground(true);
    setPalette(tpp);

    //下面是测试用
    groupTest = new QGroupBox;
    testBtn = new QPushButton;
    testBtn->setText(tr("按钮"));
    testLabel = new QLabel(tr("第二个按钮"));
    testLayout = new QVBoxLayout(groupTest);
    testLayout->addWidget(testBtn);
    testLayout->addWidget(testLabel);

    groupTest2 = new QGroupBox;
    newList = new QPushButton;
    newList->setFlat(true);
    newList->setText(tr("+新建列表"));
    QVBoxLayout *testLayout2 = new QVBoxLayout(groupTest2);
    testLayout2->addWidget(newList);

    groupTest3 = new QGroupBox;
    tText = new QTextEdit;
    QVBoxLayout *testLayout3 = new QVBoxLayout(groupTest3);
    testLayout3->addWidget(tText);

    SelfGroup *newone = new SelfGroup();
    SelfGroup *newtwo = new SelfGroup();
    SelfGroup *newthree = new SelfGroup();

    this->addItem((QWidget*) groupTest2, tr("> 默认"));
    this->addItem((QWidget*)groupTest,tr("> 测试"));
    this->addItem((QWidget*) groupTest3, tr("> 英语歌曲"));
    this->addItem(newone, tr("One"));
    this->addItem(newtwo, tr("TWO"));
    this->addItem(newthree, tr("THREE"));


}

