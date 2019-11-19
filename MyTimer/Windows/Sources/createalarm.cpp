#include "../MyTimer/Windows/Headers/createalarm.h"
#include "ui_createalarm.h"

createAlarm::createAlarm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createAlarm)
{
    ui->setupUi(this);
    ui->defaultTimer->click();
}

createAlarm::~createAlarm()
{
    delete ui;
}

/**
 * @brief timer_set is a signal that is emitted when the timer is created.
 * @param time is the sum of the current time and the input time of the user
 * @param audio_num is the number of the audio to play on the alarm
 */
void createAlarm::on_pushButton_clicked()
{
    this->close();
}

/**
 * @brief on_create_clicked is implemeted when the button "Create" is clicked. It creates the alarm with the certain settings
 * @return the sum of the input and current time in mscs.
 */
int createAlarm::on_create_clicked()
{
    QTime user_time = ui->timeEdit->time();
    QTime curr_time = QTime::currentTime();
    int a, b, c;
    a = user_time.msecsSinceStartOfDay();
    b = curr_time.msecsSinceStartOfDay();
    c = a + b;
    emit timer_set(c,audio_num);
    this->close();
    return c;
}

/**
 * @brief on_chooseAudio_clicked is implemeted when the button "chooseAudio" is clicked. It opens the chooseaudio window.
 */
void createAlarm::on_chooseAudio_clicked()
{
    CAW = new ChooseAudio(this);
    CAW->show();
    connect(CAW ,&ChooseAudio::audio_type, this, &createAlarm::set_audio_num);
}

/**
 * @brief set_audio_num is sets the value for the audio_num
 * @param in the future value of the audio_num
 */
void createAlarm::set_audio_num(int in)
{
    audio_num = in;
}

/**
 * @brief on_AmTimer_clicked is implemeted when the radiobox "Am timer" is clicked. It switches the type of the input time to Am-Pm
 */
void createAlarm::on_AmTimer_clicked()
{
    ui->timeEdit->setDisplayFormat("hh:mm:ss AP");
}

/**
 * @brief on_defaultTimer_clicked is implemeted when the radiobox "Default timer" is clicked. It switches the type of the input time to 24h.
 */
void createAlarm::on_defaultTimer_clicked()
{
    ui->timeEdit->setDisplayFormat("hh:mm:ss");
}
