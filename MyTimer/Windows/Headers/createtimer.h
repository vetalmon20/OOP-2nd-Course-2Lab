#ifndef CREATETIMER_H
#define CREATETIMER_H

#include <QDialog>
#include "chooseaudio.h"

namespace Ui {
class CreateTimer;
}

/**
 * @brief The CreateTimer class describes the proper ui window that is dedicated to create a timer.
 */
class CreateTimer : public QDialog
{
    Q_OBJECT

public:
    explicit CreateTimer(QWidget *parent = nullptr);
    ~CreateTimer();

private slots:

    /**
     * @brief on_pushButton_clicked is implemeted when the button "pushButton" is clicked. It just closes the window
     */
    void on_pushButton_clicked();

    /**
     * @brief on_create_clicked is implemeted when the button "Create" is clicked. It creates the timer with the certain settings
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

    /**
     * @brief on_alarmTimer_clicked is implemeted when the radiobox "Alarm timer" is clicked. It switches the type of the timer for alarmed-type
     */
    void on_alarmTimer_clicked();

signals:
    /**
     * @brief timer_set is a signal that is emitted when the default timer is created.
     * @param time is the sum of the current time and the input time of the user.
     * @param audio_num is the number of the audio to play on the alarm.
     * @param ifchecked is the value that tells if the value of the alarm should be changed in the main window.
     */
    void timer_set(int time, int audio_num, bool ifchecked);

    /**
     * @brief timer_set is a signal that is emitted when the alarmed-type timer is created.
     * @param time is the sum of the current time and the input time of the user.
     * @param audio_num is the number of the audio to play on the alarm.
     * @param ifchecked is the value that tells if the value of the alarm should be changed in the main window.
     */
    void timer_alarm_set(int time, int audio_num, bool ifchecked);

private:
    Ui::CreateTimer *ui;
    ChooseAudio *CAW;
    int audio_num;
};

#endif // CREATETIMER_H
