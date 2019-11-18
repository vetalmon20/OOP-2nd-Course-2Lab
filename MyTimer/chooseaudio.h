#ifndef CHOOSEAUDIO_H
#define CHOOSEAUDIO_H

#include <QDialog>
#include <QMediaPlayer>


namespace Ui {
class ChooseAudio;
}

class ChooseAudio : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseAudio(QWidget *parent = nullptr);
    ~ChooseAudio();

private slots:
    void on_listen_clicked();

    void on_choose_clicked();

signals:
    void audio_type(int audio_num);

private:
    Ui::ChooseAudio *ui;
    QMediaPlayer *player;
    int audio_num;
};

#endif // CHOOSEAUDIO_H
