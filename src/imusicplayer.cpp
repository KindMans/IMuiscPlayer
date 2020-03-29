#include "imusicplayer.h"
#include "ui_imusicplayer.h"
#include "fileSystem/filesystem.h"
#include <QListWidget>
#include <QFileDialog>

IMusicPlayer::IMusicPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IMusicPlayer)
{
    ui->setupUi(this);

    connect(ui->listWidget,SIGNAL(currentRowChanged(int)),this,SLOT(on_currentRow_change(int)));
    connect(&m_player,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(on_seqPlayMusic()));
    connect(&m_player,SIGNAL(positionChanged(qint64)),this,SLOT(on_fast_forward(qint64)));
    connect(&m_player,SIGNAL(durationChanged(qint64)),this,SLOT(on_duration(qint64)));
    connect(ui->position_change,SIGNAL(valueChanged(int)),this,SLOT(on_speed_progress(int)));

    ui->combox_play_model->setCurrentIndex(0);  //默认顺序播放
    ui->volume_change->setMaximum(100);
    ui->volume_change->setValue(50);

    m_prevOrnext=false;
    m_bIsmove = false;
    m_hisPath = "";
    getHistotyConfig();

    hlayout = new QHBoxLayout(this);
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
        ui->listWidget->insertItem(i+1,listwidgetItem);
    }
    ui->listWidget->setCurrentRow(0);
}

void IMusicPlayer::setPlayMusicUrl(const QString &url)
{
    m_player.setMedia(QUrl::fromLocalFile(url));
}

void IMusicPlayer::playMusic(int row)
{
    setPlayMusicUrl(m_filePath + ui->listWidget->item(row)->text());

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

    if(!array.contains(ui->listWidget->currentItem()->text()))
    {
        fileSystem.Write(ui->listWidget->currentItem()->text()+",");
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
    ui->listWidget->clear();
    QString array;
    readHistoryMusic(m_hisPath,array);
    QString music(array);
    QStringList musicList=music.split(",");
    for(int i=0;i<musicList.size()-1;i++)
    {
        QListWidgetItem *listwidgetItem = new QListWidgetItem;
        listwidgetItem->setText(musicList.at(i));
        ui->listWidget->insertItem(i+1,listwidgetItem);
    }
    ui->listWidget->setCurrentRow(0);
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
    ret=qrand()%ui->listWidget->count();
    if(ret==ui->listWidget->currentRow())
    {
        numRandom();
    }
    return ret;
}

QStringList IMusicPlayer::getAllListWidgetText()
{
    QStringList allItemText;
    for(int i=0;i<ui->listWidget->count();i++){
        QString itemText=ui->listWidget->item(i)->text();
        allItemText.push_back(itemText);
    }
    return allItemText;
}

void IMusicPlayer::on_fast_forward(qint64 position)
{
    if(qAbs(m_player.position()-position)>99)
    {
        m_player.setPosition(position);
    }
    ui->position_change->setValue(position);
}

void IMusicPlayer::on_duration(qint64 duration)
{
    ui->position_change->setRange(0,duration);
}

void IMusicPlayer::on_speed_progress(int value)
{
    if(m_bIsmove)
    {
       m_player.setPosition(value);
       m_bIsmove=false;
    }

}

void IMusicPlayer::on_currentRow_change(int row)
{
    ui->listWidget->setCurrentRow(row);
}

void IMusicPlayer::on_btn_player_clicked()
{
    m_prevOrnext = true;
    int row=ui->listWidget->currentRow();
    playMusic(row);
}

void IMusicPlayer::on_btn_pause_clicked()
{
    stopMusic();
}

void IMusicPlayer::on_seqPlayMusic()
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
            int count = ui->listWidget->currentRow();
            if(count == ui->listWidget->count()-1)
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
//            m_playerList.clear();
//            int currentRow=ui->listWidget->currentRow();
//            m_playerList.addMedia(QUrl::fromLocalFile(m_filePath+ui->listWidget->item(currentRow)->text()));
//            m_playerList.setCurrentIndex(1);
//            m_playerList.setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
//            m_player.setPlaylist(&m_playerList);
//            m_player.play();
            nextRow=ui->listWidget->currentRow();
        }

        ui->listWidget->setCurrentRow(nextRow);
        playMusic(nextRow);
    }
}

void IMusicPlayer::on_btn_load_clicked()
{
    static int cnt=0;
    FileSystem fileSystem;
    QStringList musicList = QFileDialog::getOpenFileNames(this,"请选择音乐文件","","*.mp3");
    //QStringList musicList = fileSystem.getFileList("E:\\Work\\qt_coding\\IMusicPlayer\\resource\\music\\");
    //m_filePath=fileSystem.getFilePath();
    if(musicList.size()==0)
        return;
    qDebug()<<musicList.front();

    QStringList list = musicList.front().split("/");
    for(int i=0;i<list.size()-1;i++)
    {
        m_filePath+=list.at(i)+"/";
    }

    qDebug()<<m_filePath;
    for(int i=0;i<musicList.size();i++){
        QListWidgetItem *listwidgetItem = new QListWidgetItem;
        QString fileName=musicList.at(i).section("/",-1);
        if(cnt==0){
            listwidgetItem->setText(fileName);
            ui->listWidget->insertItem(i+1,listwidgetItem);
        }else{
            QStringList historyNames=getAllListWidgetText();
            if(!historyNames.contains(fileName)){
                listwidgetItem->setText(fileName);
                ui->listWidget->insertItem(historyNames.size()+1,listwidgetItem);
            }
        }
    }
    ui->listWidget->setCurrentRow(0);
    cnt++;
}

void IMusicPlayer::on_btn_prev_clicked()
{
    m_prevOrnext = true;
    stopMusic();
    int nextRow;
    int count = ui->listWidget->count();
    int currentRow = ui->listWidget->currentRow();
    if(currentRow == 0){
        nextRow = count-1;
    }else
    {
        nextRow = currentRow-1;
    }
    QString temp=m_filePath+ui->listWidget->item(nextRow)->text();
    qDebug()<<temp;
    ui->listWidget->setCurrentRow(nextRow);
    playMusic(nextRow);
}

void IMusicPlayer::on_btn_next_clicked()
{
    m_prevOrnext = true;
    stopMusic();
    int nextRow;
    int count = ui->listWidget->count();
    int currentRow = ui->listWidget->currentRow();
    if(currentRow == count-1){
        nextRow = 0;
    }else
    {
        nextRow = currentRow+1;
    }
    QString temp=m_filePath+ui->listWidget->item(nextRow)->text();
    qDebug()<<temp;
    ui->listWidget->setCurrentRow(nextRow);
    playMusic(nextRow);
}

void IMusicPlayer::on_listWidget_doubleClicked(const QModelIndex &index)
{
    m_prevOrnext=true;
    playMusic(index.row());
}

void IMusicPlayer::on_position_change_sliderMoved(int position)
{
    m_bIsmove=true;
}

void IMusicPlayer::on_volume_change_sliderMoved(int position)
{
    m_player.setVolume(position);
}

void IMusicPlayer::on_tabWidget_currentChanged(int index)
{
    if(ui->tabWidget->currentIndex()==0) //音乐馆
    {
        if(hlayout->widget()==NULL)
        {
            hlayout->addWidget(ui->listWidget);

        }
        ui->tab_now->setLayout(hlayout);
        ui->listWidget->clear();
        on_btn_load_clicked();

    }else if(ui->tabWidget->currentIndex()==1) //播放历史
    {
        showHistoryList();
        if(hlayout->widget()==NULL)
        {
          hlayout->addWidget(ui->listWidget);
        }
        ui->tab_history->setLayout(hlayout);
    }
    ui->tabWidget->setCurrentIndex(index);
}
