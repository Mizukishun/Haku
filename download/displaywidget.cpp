#include "displaywidget.h"

DisplayWidget::DisplayWidget(QWidget *parent) : QWidget(parent)
{
    createInterface();
}

void DisplayWidget::createInterface()
{
    /****************************设置窗体背景颜色等*********************/
    QPalette p;
    p.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(p);


    //*****************************最顶一栏**************************/
    topFrame = new QFrame;
    topLayout = new QHBoxLayout(topFrame);
    topLabel = new QLabel(tr("搜索歌曲的结果为"));
    topPlayBtn = new QPushButton(tr("播放"));
    //topPlayBtn->setFlat(true);
    topAddBtn = new QPushButton(tr("添加"));
    //topAddBtn->setFlat(true);
    topDownloadBtn = new QPushButton(tr("下载"));
    //topDownloadBtn->setFlat(true);
    topLayout->addWidget(topLabel);
    topLayout->addStretch();
    topLayout->addWidget(topPlayBtn);
    topLayout->addWidget(topAddBtn);
    topLayout->addWidget(topDownloadBtn);

    /*****************************显示搜索结果***********************/
    displayFrame = new QFrame;
    displayFrameLayout = new QVBoxLayout(displayFrame);

    //顶栏
    firstLayout = new QHBoxLayout;
    firstCheckBox = new QCheckBox(tr(" 全选"));
    firstMusicNameBtn = new QPushButton(tr("歌曲名"));
    firstMusicNameBtn->setFlat(true);
    firstAlbumBtn = new QPushButton(tr("专辑名"));
    firstAlbumBtn->setFlat(true);
    firstTimeBtn = new QPushButton(tr("时长"));
    firstTimeBtn->setFlat(true);
    firstControlBtn = new QPushButton(tr("操作"));
    firstControlBtn->setFlat(true);

    firstLayout->addWidget(firstCheckBox);
    firstLayout->addWidget(firstMusicNameBtn);
    firstLayout->addSpacing(50);
    firstLayout->addWidget(firstAlbumBtn);
    firstLayout->addWidget(firstTimeBtn);
    firstLayout->addWidget(firstControlBtn);

    //测试用，显示搜索出来的歌曲
    secondLayout = new QVBoxLayout;

    //将上面两个布局添加到显示搜索结果的框架中
    displayFrameLayout->addLayout(firstLayout);
    displayFrameLayout->addLayout(secondLayout);

    /**********************************主布局**************************************/
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(topFrame);
    mainLayout->addWidget(displayFrame);
    mainLayout->addStretch();
}

//从网络上搜索歌曲,要如何处理呢？？？
void DisplayWidget::search(QString s)
{
    searchMusic = s;

    clearList();

    //利用了第三方的百度音乐的api接口
    url_baidu_api = "http://tingapi.ting.baidu.com/v1/restserver/ting?";

    //要发送的查询信息
    sendData.append("from=webapp_music&");
    sendData.append("method=baidu.ting.search.catalogSug&");
    sendData.append("format=json&");
    sendData.append("query=" + searchMusic);

    //将api接口与具体的查询信息连接起来，作为要发送的所有信息
    sendURL = url_baidu_api + QString(sendData);

    //设置网络接收与发送对象
    manager = new QNetworkAccessManager;
    requester = new QNetworkRequest;
    requester->setUrl(QUrl(sendURL));
    manager->get(*requester);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(handFinished(QNetworkReply*)));

}

void DisplayWidget::requireMusicInfo(QString rs)
{

}

//处理QNetworkAccessManager对象的finished()信号的槽函数
void DisplayWidget::handFinished(QNetworkReply *reply)
{
    //获取响应的状态码信息
    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    //如果没有发生错误
    if(reply->error() == QNetworkReply::NoError)
    {
        //获取收到的字节信息
        QByteArray bytes = reply->readAll();
        //将字节信息转换为字符串
        QString results(bytes);

        //解析获得歌曲信息
        parseReply(results);

    }

}


//解析获得的歌曲信息，因为一开始获得的歌曲信息还是一串以JSon格式出现的字符串
//通过解析其中的各项数据，获得歌曲的各种信息。
//注意此时的results是JSon格式的数据！！！
void DisplayWidget::parseReply(QString ps)
{


    //创建QJsonParseError对象， 用来获取解析结果
    QJsonParseError error;
    //使用静态函数获取JSonDocument对象
    QJsonDocument jsonDoc = QJsonDocument::fromJson(ps.toUtf8(), &error);
    //获得了QJsonDocument对象后，就对其进行解析
    if(error.error == QJsonParseError::NoError)
    {
        //如果没有错误，则还看是否为空
        if(!(jsonDoc.isNull() || jsonDoc.isEmpty()))
        {
            //如果jsonDoc是JSon对象,则其对应QVariantMap对象，有键值对
            if(jsonDoc.isObject())
            {
                //转换为QJsonObject对象
                QJsonObject jsObject = jsonDoc.object();
                //看该对象是否含有键"song"
                if(jsObject.contains("song"))
                {
                    //获取该键所对应的值
                    QJsonValue songValue = jsObject.take("song");
                    //判断这个值是否为数组
                    if(songValue.isArray())
                    {
                        //如果是数组，则先将其转换为数组
                        QJsonArray songArray = songValue.toArray();
                        //获取这个数组的元素个数
                        int songArraySize = songArray.size();
                        //然后就是对每个元素的处理
                        for(int i = 0; i < songArraySize; ++i)
                        {
                            QJsonValue songInfo = songArray.at(i);
                            //根据浏览器的分析，其中的还是QJsonObject对象，所以仍需判断处理
                            if(songInfo.isObject())
                            {
                                QJsonObject songInfoObject = songInfo.toObject();
                                //含有键”songname"，就把其值提取出来
                                if(songInfoObject.contains("songname"))
                                {
                                        QJsonValue songnameValue = songInfoObject.take("songname");
                                        if(songnameValue.isString())
                                        {
                                            QString songNameString = songnameValue.toString();
                                            songnameList.append(songNameString);
                                        }
                                }
                                if(songInfoObject.contains("artistname"))
                                {
                                    QJsonValue artistnameValue = songInfoObject.take("artistname");
                                    if(artistnameValue.isString())
                                    {
                                        QString artistnameString = artistnameValue.toString();
                                        artistnameList.append(artistnameString);
                                    }
                                }
                                if(songInfoObject.contains("songid"))
                                {
                                    QJsonValue songidValue = songInfoObject.take("songid");
                                    if(songidValue.isString())
                                    {
                                        QString songidString = songidValue.toString();
                                        songidList.append(songidString);
                                    }
                                }
                                if(songInfoObject.contains("has_mv"))
                                {
                                    QJsonValue has_mvValue = songInfoObject.take("has_mv");
                                    if(has_mvValue.isBool())
                                    {
                                        bool has_mvBool = has_mvValue.toBool();
                                        has_mvList.append(has_mvBool);
                                    }
                                }
                                if(songInfoObject.contains("encrypted_songid"))
                                {
                                    QJsonValue encrypted_songidValue = songInfoObject.take("encrypted_songid");
                                    if(encrypted_songidValue.isString())
                                    {
                                        QString encrypted_songidString = encrypted_songidValue.toString();
                                        encrypted_songidList.append(encrypted_songidString);
                                    }
                                }
                            }
                        }
                    }
                }
                //以上便是对"song"这一字段对象的遍历及处理
                //而下面则是对“album"这一字段对象的遍历及处理
                if(jsObject.contains("album"))
                {
                    QJsonValue albumObject = jsObject.take("album");

                    if(albumObject.isArray())
                    {
                        QJsonArray albumArray = albumObject.toArray();
                        int albumSize = albumArray.size();
                        for(int j = 0; j < albumSize; ++j)
                        {
                            QJsonValue albumValue = albumArray.at(j);
                            if(albumValue.isObject())
                            {
                                QJsonObject albumInfoObject = albumValue.toObject();

                                if(albumInfoObject.contains("albumname"))
                                {
                                    QJsonValue albumnameValue = albumInfoObject.take("albumname");
                                    if(albumnameValue.isString())
                                    {
                                        QString albumname_String = albumnameValue.toString();
                                        albumnameList.append(albumname_String);
                                    }
                                }
                                if(albumInfoObject.contains("artistpic"))
                                {
                                    QJsonValue artistpicValue = albumInfoObject.take("artistpic");
                                    if(artistpicValue.isString())
                                    {
                                        QString artistpic_String = artistpicValue.toString();
                                        album_artistpicList.append(artistpic_String);
                                    }
                                }
                                if(albumInfoObject.contains("albumid"))
                                {
                                    QJsonValue albumidValue = albumInfoObject.take("albumid");
                                    if(albumidValue.isString())
                                    {
                                        QString albumid_String = albumidValue.toString();
                                        albumidList.append(albumid_String);
                                    }
                                }
                                if(albumInfoObject.contains("artistname"))
                                {
                                    QJsonValue album_artistnameValue = albumInfoObject.take("artistname");
                                    if(album_artistnameValue.isString())
                                    {
                                        QString artistname_String = album_artistnameValue.toString();
                                        album_artistnameList.append(artistname_String);
                                    }
                                }

                            }

                        }
                    }
                }
                //以上便是对“album"字段的遍历及处理
                //以下则是对”order"字段的处理
                if(jsObject.contains("order"))
                {
                    QJsonValue orderInfo = jsObject.take("order");
                    if(orderInfo.isString())
                    {
                        QString order_String = orderInfo.toString();
                        orderList.append(order_String);
                    }
                }
                //以下则是对”error_code"字段的处理
                if(jsObject.contains("error_code"))
                {
                    QJsonValue error_code_Info = jsObject.take("error_code");
                    if(error_code_Info.isString())
                    {
                        QString error_code_String = error_code_Info.toString();
                        error_codeList.append(error_code_String);
                    }
                }
                //以下是对“artist"字段的处理
                if(jsObject.contains("artist"))
                {
                    QJsonValue artistInfo = jsObject.take("artist");
                    if(artistInfo.isArray())
                    {
                        QJsonArray artistArray = artistInfo.toArray();
                        int artistSize = artistArray.size();
                        for(int k = 0; k < artistSize; ++k)
                        {
                            QJsonValue artistValue = artistArray.at(k);
                            if(artistValue.isObject())
                            {
                                QJsonObject artistObject = artistValue.toObject();

                                if(artistObject.contains("artistid"))
                                {
                                    QJsonValue artist_artistidValue = artistObject.take("artistid");
                                    if(artist_artistidValue.isString())
                                    {
                                        QString artistid_String = artist_artistidValue.toString();
                                        artistidList.append(artistid_String);
                                    }
                                }
                                if(artistObject.contains("artistpic"))
                                {
                                    QJsonValue artistpicValue = artistObject.take("artistpic");
                                    if(artistpicValue.isString())
                                    {
                                        QString artistpic_String = artistpicValue.toString();
                                        artist_artistpicList.append(artistpic_String);
                                    }
                                }
                                if(artistObject.contains("artistname"))
                                {
                                    QJsonValue artist_artistnameValue = artistObject.take("artistname");
                                    if(artist_artistnameValue.isString())
                                    {
                                        QString artist_artistname_String = artist_artistnameValue.toString();
                                        artist_artistnameList.append(artist_artistname_String);
                                    }
                                }


                            }
                        }
                    }
                }
            }
        }
    }
    //对有错误的处理
    else
    {
        //现在只是单纯的返回，之后得补上具体的错误处理方案
        return;
    }

    //以上这些便完成了对于获取到的信息的解析，注意着其中传来的信息分为五部分，
    //分别是song、album、order、error_code、artist，其中有用的主要是song部分，
    //特别是利用songid，通过另外的一个借口方法获得歌曲的具体地址，获得地址之后方可
    //进行下载和播放。当然，我这里将返回的几乎所有的歌曲信息都分别保存到QList中了，
    //方便之后的使用。
    /*接下来，就应该将搜索到的这些歌曲名称显示出来，
     * 当用户点击具体某一首歌曲的时候，则将
     * 该首歌曲的songid传送给另一函数，请求得到该首歌曲的地址，并进行播放
     */



    //测试用
    createMusicListD();
}


void DisplayWidget::createMusicListD()
{
    //为了更好测试，所以暂时性地只显示4个条目
    for(int k = 0; k < 5; ++k)
    {
        QString singleName = songnameList.at(k);
        SingleDisplay *oneSong = new SingleDisplay();
        oneSong->DsingleMusicBtn->setText(singleName);
        secondLayout->addWidget(oneSong);
    }
}


//清除前次搜索的内容，防止对本次搜索的干扰
void DisplayWidget::clearList()
{
    if(!songnameList.isEmpty())
        songnameList.clear();
    if(!artistnameList.isEmpty())
        artistnameList.clear();
    if(!songidList.isEmpty())
        songidList.clear();
    if(!has_mvList.isEmpty())
        has_mvList.clear();
    if(!encrypted_songidList.isEmpty())
        encrypted_songidList.clear();

    if(!albumnameList.isEmpty())
        albumnameList.clear();
    if(!album_artistpicList.isEmpty())
        album_artistpicList.clear();
    if(!albumidList.isEmpty())
        albumidList.clear();
    if(!album_artistnameList.isEmpty())
        album_artistnameList.clear();

    if(!orderList.isEmpty())
        orderList.clear();
    if(!error_codeList.isEmpty())
        error_codeList.clear();
    if(!artistidList.isEmpty())
        artistidList.clear();
    if(!artist_artistnameList.isEmpty())
        artist_artistnameList.clear();
    if(!artist_artistpicList.isEmpty())
        artist_artistpicList.clear();

    if(!sendData.isEmpty())
        sendData.clear();


    //删除之前显示过的歌曲列表
    if(!secondLayout->isEmpty())
    {
        QLayoutItem *ite;
        QWidget *widg;
        while((ite = secondLayout->takeAt(0)))
        {
            if((widg = ite->widget())!= 0)
            {
                widg->hide();
                delete widg;
            }
            else
                delete ite;
        }
        delete secondLayout;
        //在删除之前的secondLayout之后，还要重新再创建一个新的空白secondLayout
        //并添加到原布局上
        secondLayout = new QVBoxLayout;
        displayFrameLayout->addLayout(secondLayout);
    }


}












