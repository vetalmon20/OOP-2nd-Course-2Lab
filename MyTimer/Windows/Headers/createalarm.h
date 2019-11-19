#ifndef CREATEALARM_H
#define CREATEALARM_H

#include <QDialog>
#include "chooseaudio.h"

namespace Ui {
class createAlarm;
}

/**
 * @brief The createAlarm class describes the proper ui window that is dedicated to create an alarm
 */
class createAlarm : public QDialog
{
    Q_OBJECT

public:
    explicit createAlarm(QWidget *parent = nullptr);
    ~createAlarm();

private slots:

    /**
     * @brief on_pushButton_clicked is implemeted when the button "pushButton" is clicked. It just closes the window
     */
    void on_pushButton_clicked();

    /**
     * @brief on_create_clicked is implemeted when the button "Create" is clicked. It creates the alarm with the certain settings
     * @return the sum of the input and current time in mscs.
     */
    int on_create_clicked();

    /**
     * @brief on_chooseAudio_clicked is implemeted when the button "chooseAudio" is clicked. It opens the chooseaudio window.
     */
    void on_chooseAudio_clicked();

    /**
     * @brief set_audio_num is sets the value for the audio_num
     * @param in the future value of the audio_num
     */
    void set_audio_num(int in);

    /**
     * @brief on_AmTimer_clicked is implemeted when the radiobox "Am timer" is clicked. It switches the type of the input time to Am-Pm
     */
    void on_AmTimer_clicked();

    /**
     * @brief on_defaultTimer_clicked is implemeted when the radiobox "Default timer" is clicked. It switches the type of the input time to 24h.
     */
    void on_defaultTimer_clicked();

signals:
    /**
     * @brief timer_set is a signal that is emitted when the timer is created.
     * @param time is the sum of the current time and the input time of the user.
     * @param audio_num is the number of the audio to play on the alarm.
     */
    void timer_set(int time, int audio_num);

private:
    Ui::createAlarm *ui;
    ChooseAudio *CAW;
    int audio_num;
};

#endif // CREATEALARM_H
