#include "createalarm.h"
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

void createAlarm::on_pushButton_clicked()
{
    this->close();
}

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

void createAlarm::on_chooseAudio_clicked()
{
    CAW = new ChooseAudio(this);
    CAW->show();
    connect(CAW ,&ChooseAudio::audio_type, this, &createAlarm::set_audio_num);
}

void createAlarm::set_audio_num(int in)
{
    audio_num = in;
}

void createAlarm::on_AmTimer_clicked()
{
    ui->timeEdit->setDisplayFormat("hh:mm:ss AP");
}

void createAlarm::on_defaultTimer_clicked()
{
    ui->timeEdit->setDisplayFormat("hh:mm:ss");
}
