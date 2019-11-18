#include "createtimer.h"
#include "ui_createtimer.h"
#include <QDateTime>
#include <QDebug>
#include "mainwindow.h"

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

void CreateTimer::on_pushButton_clicked()
{
    this->close();
}



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

void CreateTimer::on_chooseAudio_clicked()
{
    CAW = new ChooseAudio(this);
    CAW->show();
    connect(CAW ,&ChooseAudio::audio_type, this, &CreateTimer::set_audio_num);
}

void CreateTimer::set_audio_num(int in)
{
    audio_num = in;
}

void CreateTimer::on_AmTimer_clicked()
{
    ui->timeEdit->setDisplayFormat("hh:mm:ss AP");
}

void CreateTimer::on_defaultTimer_clicked()
{
    ui->timeEdit->setDisplayFormat("hh:mm:ss");
}

void CreateTimer::on_alarmTimer_clicked()
{
    ui->timeEdit->setDisplayFormat("hh:mm:ss");
}
