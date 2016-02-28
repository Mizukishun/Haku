#ifndef TOOLGROUP_H
#define TOOLGROUP_H

/*这个类用于实现歌曲列表
 *
 */

#include <QToolBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>


class ToolGroup : public QToolBox
{
    Q_OBJECT
public:
    ToolGroup(QWidget *parent = 0);


    //下面这些事暂时用于测试用的，可能要删除
    QGroupBox *groupTest;
    QVBoxLayout *testLayout;
    QPushButton *testBtn;
    QLabel *testLabel;
    QTextEdit *tText;
    QPushButton *newList;
    QGroupBox *groupTest2;
    QGroupBox *groupTest3;


};

#endif // TOOLGROUP_H
