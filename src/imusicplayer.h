#ifndef IMUSICPLAYER_H
#define IMUSICPLAYER_H

#include <QWidget>
#include <QString>
#include <QList>
#include <QMediaPlayer>
#include <QMediaPlaylist>
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
    void stopMusic();
    void recordHistoryMusic(const QString &path);
    void readHistoryMusic(const QString &path,QString &data);
    void showHistoryList();
    void getHistotyConfig();

private:
    int numRandom();

    QStringList getAllListWidgetText();
private slots:
    void on_fast_forward(qint64 position);
    void on_duration(qint64 duration);
    void on_speed_progress(int value);
    void on_currentRow_change(int row);
    void on_btn_player_clicked();

    void on_btn_pause_clicked();

    void on_seqPlayMusic();

    void on_btn_load_clicked();

    void on_btn_prev_clicked();

    void on_btn_next_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_position_change_sliderMoved(int position);

    void on_volume_change_sliderMoved(int position);

    void on_tabWidget_currentChanged(int index);

private:
    QString m_filePath;
    QList<QString> m_musicList;
    QMediaPlayer m_player;
    QMediaPlaylist m_playerList;
    bool m_prevOrnext;
    bool m_bIsmove;
    QString m_hisPath;

    QHBoxLayout *hlayout;

private:
    Ui::IMusicPlayer *ui;
};
#endif // IMUSICPLAYER_H
