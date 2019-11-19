#include "../MyTimer/Windows/Headers/createtimer.h"
#include "ui_createtimer.h"
#include <QDateTime>
#include <QDebug>
#include "../MyTimer/Windows/Headers/mainwindow.h"

extern MainWindow *w;

CreateTimer::CreateTimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateTimer)
{
    ui->setupUi(this);
    ui->defaultTimer->click();
}

CreateTimer::~CreateTimer()
{
    delete ui;
}

/**
 * @brief on_pushButton_clicked is implemeted when the button "pushButton" is clicked. It just closes the window
 */
void CreateTimer::on_pushButton_clicked()
{
    this->close();
}

/**
 * @brief on_create_clicked is implemeted when the button "Create" is clicked. It creates the timer with the certain settings
 * @return the sum of the input and current time in mscs.
 */
int CreateTimer::on_create_clicked()
{
    QTime user_time = ui->timeEdit->time();
    QTime curr_time = QTime::currentTime();
    int a, b, c;
    a = user_time.msecsSinceStartOfDay();
    b = curr_time.msecsSinceStartOfDay();
    c = a + b;
    if(ui->defaultTimer->isChecked())
        emit timer_set(c,audio_num,1);
    if(ui->alarmTimer->isChecked())
        emit timer_alarm_set(c, audio_num,0);
    if(ui->AmTimer->isChecked())
        emit timer_alarm_set(c, audio_num,0);
    this->close();
    return c;
}

/**
 * @brief on_chooseAudio_clicked is implemeted when the button "chooseAudio" is clicked. It opens the chooseaudio window.
 */
void CreateTimer::on_chooseAudio_clicked()
{
    CAW = new ChooseAudio(this);
    CAW->show();
    connect(CAW ,&ChooseAudio::audio_type, this, &CreateTimer::set_audio_num);
}

/**
 * @brief set_audio_num is sets the value for the audio_num
 * @param in the future value of the audio_num
 */
void CreateTimer::set_audio_num(int in)
{
    audio_num = in;
}

/**
 * @brief on_AmTimer_clicked is implemeted when the radiobox "Am timer" is clicked. It switches the type of the input time to Am-Pm
 */
void CreateTimer::on_AmTimer_clicked()
{
    ui->timeEdit->setDisplayFormat("hh:mm:ss AP");
}

/**
 * @brief on_defaultTimer_clicked is implemeted when the radiobox "Default timer" is clicked. It switches the type of the input time to 24h.
 */
void CreateTimer::on_defaultTimer_clicked()
{
    ui->timeEdit->setDisplayFormat("hh:mm:ss");
}

/**
 * @brief on_alarmTimer_clicked is implemeted when the radiobox "Alarm timer" is clicked. It switches the type of the timer for alarmed-type
 */
void CreateTimer::on_alarmTimer_clicked()
{
    ui->timeEdit->setDisplayFormat("hh:mm:ss");
}
