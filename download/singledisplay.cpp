#include "singledisplay.h"

SingleDisplay::SingleDisplay(QWidget *parent) : QWidget(parent)
{
    createDsingleInterface();
}


void SingleDisplay::createDsingleInterface()
{
    singleCheckBox = new QCheckBox;
    DsingleMusicBtn = new QPushButton;
    DsingleMusicBtn->setFlat(true);
    DsingleAlbumBtn = new QPushButton;
    DsingleAlbumBtn->setFlat(true);
    DsingleTimeBtn = new QPushButton;
    DsingleTimeBtn->setFlat(true);
    DsinglePlayBtn = new QPushButton;
    DsinglePlayBtn->setFlat(true);
    DsinglePlayBtn->setIcon(QPixmap(":/images/tri_30.png"));
    DsingleAddBtn = new QPushButton;
    DsingleAddBtn->setFlat(true);
    DsingleAddBtn->setIcon(QPixmap(":/images/addToList_30.png"));
    DsingleDownloadBtn = new QPushButton;
    DsingleDownloadBtn->setFlat(true);
    DsingleDownloadBtn->setIcon(QPixmap(":/images/downloadIcon.png"));

    threeBtnLayout = new QHBoxLayout;
    threeBtnLayout->setSpacing(0);
    threeBtnLayout->setMargin(0);
    threeBtnLayout->addWidget(DsinglePlayBtn);
    threeBtnLayout->addWidget(DsingleAddBtn);
    threeBtnLayout->addWidget(DsingleDownloadBtn);

    DsingleLayout = new QHBoxLayout(this);
    DsingleLayout->addWidget(singleCheckBox);
    DsingleLayout->addWidget(DsingleMusicBtn);
    DsingleLayout->addWidget(DsingleAlbumBtn);
    DsingleLayout->addWidget(DsingleTimeBtn);
    DsingleLayout->addStretch();
    DsingleLayout->addLayout(threeBtnLayout);

}
