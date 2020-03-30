#ifndef IMUSICPLAYER_H
#define IMUSICPLAYER_H

#include <QWidget>
#include <QString>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QListWidget>
#include <QHBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class IMusicPlayer; }
QT_END_NAMESPACE

class IMusicPlayer : public QWidget
{
    Q_OBJECT

public:
    IMusicPlayer(QWidget *parent = nullptr);
    ~IMusicPlayer();

    void getMusicList();    //调试接口
    void setPlayMusicUrl(const QString &url);
    void playMusic(int row);
    void playMusic(const QString &text);
    void stopMusic();
    void recordHistoryMusic(const QString &path);
    void readHistoryMusic(const QString &path,QString &data);
    void showHistoryList();
    void showList();
    void getHistotyConfig();
    QStringList getAllListWidgetText();

private:
    int numRandom();

private slots:
    void slot_modifyProgress(qint64 position);
    void slot_duration(qint64 duration);
    void slot_setPosition(int value);
    void slot_playModelSelect();

    void slot_btn_player_clicked();
    void slot_btn_pause_clicked();
    void slot_btn_load_clicked();
    void slot_btn_prev_clicked();
    void slot_btn_next_clicked();
    void slot_position_change_sliderMoved(int position);
    void slot_volume_change_sliderMoved(int position);

    void slot_currentRow_change(int row);
    void slot_listWidget_doubleClicked(QListWidgetItem *item);
    void slot_tabWidget_currentChanged(int index);

private:
    QStringList m_musicList;
    QString m_filePath;
    QMediaPlayer m_player;
    QMediaPlaylist m_playerList;
    bool m_prevOrnext;
    bool m_bIsmove;
    QString m_hisPath;
    QHBoxLayout *hlayout1;
    QHBoxLayout *hlayout2;
    QListWidget *listwidget;

private:
    Ui::IMusicPlayer *ui;
};
#endif // IMUSICPLAYER_H
