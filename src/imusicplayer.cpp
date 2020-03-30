#include "imusicplayer.h"
#include "ui_imusicplayer.h"
#include "fileSystem/filesystem.h"
#include <QListWidget>
#include <QFileDialog>
#include <QMessageBox>

IMusicPlayer::IMusicPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IMusicPlayer)
{
    ui->setupUi(this);

    hlayout1 = new QHBoxLayout;
    hlayout2 = new QHBoxLayout;
    listwidget = new QListWidget(this);
    hlayout1->addWidget(listwidget);
    ui->tab_now->setLayout(hlayout1);
    ui->tab_history->setLayout(hlayout2);
    ui->tabWidget->setCurrentIndex(0);

    connect(&m_player,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(slot_playModelSelect()));
    connect(&m_player,SIGNAL(positionChanged(qint64)),this,SLOT(slot_modifyProgress(qint64)));
    connect(&m_player,SIGNAL(durationChanged(qint64)),this,SLOT(slot_duration(qint64)));

    connect(ui->slider_position,SIGNAL(valueChanged(int)),this,SLOT(slot_setPosition(int)));
    connect(ui->slider_position,SIGNAL(sliderMoved(int)),this,SLOT(slot_position_change_sliderMoved(int)));
    connect(ui->slider_volume,SIGNAL(sliderMoved(int)),this,SLOT(slot_volume_change_sliderMoved(int)));

    connect(ui->btn_player,SIGNAL(clicked()),this,SLOT(slot_btn_player_clicked()));
    connect(ui->btn_pause,SIGNAL(clicked()),this,SLOT(slot_btn_pause_clicked()));
    connect(ui->btn_load,SIGNAL(clicked()),this,SLOT(slot_btn_load_clicked()));
    connect(ui->btn_prev,SIGNAL(clicked()),this,SLOT(slot_btn_prev_clicked()));
    connect(ui->btn_next,SIGNAL(clicked()),this,SLOT(slot_btn_next_clicked()));

    connect(listwidget,SIGNAL(currentRowChanged(int)),this,SLOT(slot_currentRow_change(int)));
    connect(listwidget,SIGNAL(itemDoubleClicked(QListWidgetItem *)),this,
            SLOT(slot_listWidget_doubleClicked(QListWidgetItem *)));
    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(slot_tabWidget_currentChanged(int)));

    ui->combox_play_model->setCurrentIndex(0);  //默认顺序播放
    ui->slider_volume->setMaximum(100);
    ui->slider_volume->setValue(50);

    m_prevOrnext=false;
    m_bIsmove = false;
    m_hisPath = "";

    getHistotyConfig();
}

IMusicPlayer::~IMusicPlayer()
{
    delete ui;
}

void IMusicPlayer::getMusicList()
{
    FileSystem file;

    QList<QString> fileNameList = file.getFileList("E:\\Work\\qt_coding\\IMusicPlayer\\resource\\music");
    for(int i=0;i<fileNameList.size();i++){
        QListWidgetItem *listwidgetItem = new QListWidgetItem;
        listwidgetItem->setText(fileNameList.at(i));
        listwidget->insertItem(i+1,listwidgetItem);
    }
    listwidget->setCurrentRow(0);
}

void IMusicPlayer::setPlayMusicUrl(const QString &url)
{
    m_player.setMedia(QUrl::fromLocalFile(url));
}

void IMusicPlayer::playMusic(int row)
{
    setPlayMusicUrl(m_filePath + listwidget->item(row)->text());

    m_player.play();

    //写入历史文件
    recordHistoryMusic(m_hisPath);
}

//重载
void IMusicPlayer::playMusic(const QString &text)
{
    setPlayMusicUrl(m_filePath + text);

    m_player.play();

    //写入历史文件
    recordHistoryMusic(m_hisPath);
}

void IMusicPlayer::recordHistoryMusic(const QString &path)
{
    FileSystem fileSystem;

    if(!fileSystem.openFile(path))
        return;

    QString array;
    fileSystem.ReadAll(array);

    if(!array.contains(listwidget->currentItem()->text()))
    {
        fileSystem.Write(listwidget->currentItem()->text()+",");
    }


    fileSystem.Close();
}

void IMusicPlayer::readHistoryMusic(const QString &path,QString &data)
{
    FileSystem fileSystem;
    if(!fileSystem.openFile(path))
        return;

    fileSystem.ReadAll(data);

    fileSystem.Close();
}

void IMusicPlayer::showHistoryList()
{
    if(m_filePath == "")
    {
        QMessageBox::information(this,"提示","暂无历史播放","确定");
        return;
    }


    listwidget->clear();
    QString array;
    readHistoryMusic(m_hisPath,array);
    QString music(array);
    QStringList musicList=music.split(",");
    for(int i=0;i<musicList.size()-1;i++)
    {
        QListWidgetItem *listwidgetItem = new QListWidgetItem;
        listwidgetItem->setText(musicList.at(i));
        listwidget->insertItem(i+1,listwidgetItem);
    }
    listwidget->setCurrentRow(0);
}

void IMusicPlayer::showList()
{
    static int cnt=0;

    if(m_musicList.size()==0)
        return;
    for(int i=0;i<m_musicList.size();i++){
        QListWidgetItem *listwidgetItem = new QListWidgetItem;
        QString fileName=m_musicList.at(i).section("/",-1);
        if(cnt==0){
            listwidgetItem->setText(fileName);
            listwidget->insertItem(i+1,listwidgetItem);
        }else{
            QStringList historyNames=getAllListWidgetText();
            if(!historyNames.contains(fileName)){
                listwidgetItem->setText(fileName);
                listwidget->insertItem(historyNames.size()+1,listwidgetItem);
            }
        }
    }
    listwidget->setCurrentRow(0);
    cnt++;
}

void IMusicPlayer::getHistotyConfig()
{
    FileSystem fileSystem;
    QDir dir(QDir::currentPath());
    dir.cdUp();
    m_hisPath = dir.path()+"/config/config.ini";
    if(!fileSystem.openFile(m_hisPath))
        return;
}

void IMusicPlayer::stopMusic()
{
    if(m_player.state()==QMediaPlayer::State::PausedState)
    {
        m_player.play();
        ui->btn_pause->setText("暂停");
    }
    else if(m_player.state()==QMediaPlayer::State::PlayingState)
    {
        m_player.pause();
        ui->btn_pause->setText("继续");
    }
}

int IMusicPlayer::numRandom()
{
    int ret;
    qsrand(time(NULL));
    ret=qrand()%listwidget->count();
    if(ret==listwidget->currentRow())
    {
        numRandom();
    }
    return ret;
}

QStringList IMusicPlayer::getAllListWidgetText()
{
    QStringList allItemText;
    for(int i=0;i<listwidget->count();i++){
        QString itemText=listwidget->item(i)->text();
        allItemText.push_back(itemText);
    }
    return allItemText;
}

void IMusicPlayer::slot_modifyProgress(qint64 position)
{
    ui->slider_position->setValue(position);
}

void IMusicPlayer::slot_duration(qint64 duration)
{
    ui->slider_position->setRange(0,duration);
}

void IMusicPlayer::slot_setPosition(int value)
{
    if(m_bIsmove)
    {
       m_player.setPosition(value);
       m_bIsmove=false;
    }

}

void IMusicPlayer::slot_position_change_sliderMoved(int position)
{
    Q_UNUSED(position);
    m_bIsmove=true;
}

void IMusicPlayer::slot_volume_change_sliderMoved(int position)
{
    m_player.setVolume(position);
}

void IMusicPlayer::slot_btn_player_clicked()
{
    m_prevOrnext = true;
    int row=listwidget->currentRow();
    playMusic(row);
}

void IMusicPlayer::slot_btn_pause_clicked()
{
    stopMusic();
}

void IMusicPlayer::slot_playModelSelect()
{

    if(m_player.state()==QMediaPlayer::State::StoppedState)
    {
        if(m_prevOrnext)
        {
            m_prevOrnext=false;
            return;
        }

        int nextRow = 0;

        qDebug()<<"当前行："<<ui->combox_play_model->currentText();
        if(ui->combox_play_model->currentIndex()==0)
        {
            int count = listwidget->currentRow();
            if(count == listwidget->count()-1)
            {
                nextRow = 0;
            }else{
                nextRow = count + 1;
            }
        }
        else if(ui->combox_play_model->currentIndex()==1)
        {
            nextRow=numRandom();
        }
        else if(ui->combox_play_model->currentIndex()==2)
        {
            nextRow=listwidget->currentRow();
        }

        listwidget->setCurrentRow(nextRow);
        playMusic(nextRow);
    }
}

void IMusicPlayer::slot_btn_load_clicked()
{
    FileSystem fileSystem;
    m_musicList = QFileDialog::getOpenFileNames(this,"请选择音乐文件","","*.mp3");
    //QStringList musicList = fileSystem.getFileList("E:\\Work\\qt_coding\\IMusicPlayer\\resource\\music\\");
    //m_filePath=fileSystem.getFilePath();
    if(m_musicList.size()==0)
        return;
    qDebug()<<m_musicList.front();

    QStringList list = m_musicList.front().split("/");
    for(int i=0;i<list.size()-1;i++)
    {
        m_filePath+=list.at(i)+"/";
    }

    qDebug()<<m_filePath;
    ui->tabWidget->setCurrentIndex(0);
    showList();
}

void IMusicPlayer::slot_btn_prev_clicked()
{
    m_prevOrnext = true;
    m_player.stop();
    int nextRow;
    int count = listwidget->count();
    int currentRow = listwidget->currentRow();
    if(currentRow == 0){
        nextRow = count-1;
    }else
    {
        nextRow = currentRow-1;
    }
    QString temp=m_filePath+listwidget->item(nextRow)->text();
    qDebug()<<temp;
    listwidget->setCurrentRow(nextRow);
    playMusic(nextRow);
}

void IMusicPlayer::slot_btn_next_clicked()
{
    m_prevOrnext = true;
    m_player.stop();
    int nextRow;
    int count = listwidget->count();
    int currentRow = listwidget->currentRow();
    if(currentRow == count-1){
        nextRow = 0;
    }else
    {
        nextRow = currentRow+1;
    }
    QString temp=m_filePath+listwidget->item(nextRow)->text();
    qDebug()<<temp;
    listwidget->setCurrentRow(nextRow);
    playMusic(nextRow);
}

void IMusicPlayer::slot_currentRow_change(int row)
{
    listwidget->setCurrentRow(row);
}

void IMusicPlayer::slot_listWidget_doubleClicked(QListWidgetItem *item)
{
    m_prevOrnext=true;
    qDebug()<<item->text();
    playMusic(item->text());
}


void IMusicPlayer::slot_tabWidget_currentChanged(int index)
{
    if(ui->tabWidget->currentIndex()==0) //音乐馆
    {
        listwidget->clear();
        showList();

        if(!hlayout2->isEmpty())
            hlayout2->removeWidget(listwidget);
        if(hlayout1->isEmpty())
            hlayout1->addWidget(listwidget);

    }else if(ui->tabWidget->currentIndex()==1) //播放历史
    {
        showHistoryList();

        if(!hlayout1->isEmpty())
            hlayout1->removeWidget(listwidget);
        if(hlayout2->isEmpty())
            hlayout2->addWidget(listwidget);

    }
    ui->tabWidget->setCurrentIndex(index);
}
