#ifndef CHOOSEAUDIO_H
#define CHOOSEAUDIO_H

#include <QDialog>
#include <QMediaPlayer>


namespace Ui {
class ChooseAudio;
}

/**
 * @brief The ChooseAudio class describes the proper ui window that is dedicated to choose the audio for alarm/timer
 */
class ChooseAudio : public QDialog
{
    Q_OBJECT

public:

    explicit ChooseAudio(QWidget *parent = nullptr);
    ~ChooseAudio();

private slots:

    /**
     * @brief on_listen_clicked is implemeted when the button "Listen" is clicked. It plays the certain audio.
     */
    void on_listen_clicked();

    /**
     * @brief on_choose_clicked is implemented when the button "Choose" is clicked. It chooses the audio for the alarm/timer
     */
    void on_choose_clicked();

signals:

    /**
     * @brief audio_type is a signal that is emitted when the audio is chosen.
     * @param audio_num is a number of the chosen audio to play on alarm/timer
     */
    void audio_type(int audio_num);

private:
    Ui::ChooseAudio *ui;
    QMediaPlayer *player;
    int audio_num;
};

#endif // CHOOSEAUDIO_H
