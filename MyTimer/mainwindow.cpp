#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include "createtimer.h"
#include <QMediaPlayer>
#include <QUrl>
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    curr_time = QDateTime::currentDateTime();
    QString curr_time_string = curr_time.toString("dd/MM/yyyy");
    ui->labelData->setText(curr_time_string);

    timer = new QTimer(this);
    checker = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(current_time()));
    connect(checker, SIGNAL(timeout()), this, SLOT(check_timers()));
    connect(timer, SIGNAL(timeout()), this, SLOT(upd_timers()));
    connect(timer, SIGNAL(timeout()), this, SLOT(check_alarms()));

    timer->start(1000);
    checker->start(400);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::current_time()
{
    QTime curr_time = QTime::currentTime();
    QString curr_time_text = curr_time.toString("hh : mm : ss");
    ui->labelTimer->setText(curr_time_text);

}

void MainWindow:: check_timers(){

    QTime curr_time = QTime::currentTime();
    int curr_int;
    curr_int = curr_time.msecsSinceStartOfDay();

    for (unsigned long long int i = 0; i < timers.size(); i++){
        if(curr_int  >= timers[i]){
            give_signal();
            delete_timer(i);
        }
    }
}

void MainWindow::check_alarms()
{
    QTime curr_time = QTime::currentTime();
    int curr_hour, curr_min, curr_sec;
    int temp_hour, temp_min, temp_sec;
    curr_hour = curr_time.hour();
    curr_min = curr_time.minute();
    curr_sec = curr_time.second();
    for(unsigned long long i = 0; i < alarms.size(); i++){
        temp_hour = alarms[i].hour();
        temp_min = alarms[i].minute();
        temp_sec = alarms[i].second();
        if((temp_hour == curr_hour) && (temp_min == curr_min) && (temp_sec == curr_sec))
            give_signal();
    }
}

void MainWindow:: give_signal(){


    FSW = new FinishSignal(this);
    FSW->show();
    QMediaPlayer *player = new QMediaPlayer;
    const QString path = "D:/MyRepositories/OOP/OOP-2nd-Course-2Lab/MyTimer/Audio/1.mp3";
    QUrl adress(QFileInfo(path).absoluteFilePath());
    player->setMedia(adress);
    player->setVolume(50);
    player->play();
}

void MainWindow::add_timer(int in)
{
    timers.push_back(in);
    QTime temp, curr_time;
    curr_time  = QTime::currentTime();
    int a, res;
    a = curr_time.msecsSinceStartOfDay();
    res = in - a;
    temp = temp.fromMSecsSinceStartOfDay(res);

    QString time_string = temp.toString("hh : mm : ss");
    ui->timerList->addItem(time_string);
}

void MainWindow::upd_timers()
{

    QTime curr_time = QTime::currentTime();
    QString temp_text;
    QTime temp_time;
    int temp_val,curr_time_int;
    curr_time_int = curr_time.msecsSinceStartOfDay();

    for(unsigned long long int i = 0; i < timers.size(); i++){
        temp_val = timers[i] - curr_time_int;
        temp_time = temp_time.fromMSecsSinceStartOfDay(temp_val);
        temp_text = temp_time.toString("hh : mm : ss");
        ui->timerList->item(i)->setText(temp_text);
    }

}

void MainWindow::add_alarm(int in)
{
    QTime curr_time = QTime::currentTime();
    int curr_time_int = curr_time.msecsSinceStartOfDay();
    int alarm_val = in - curr_time_int;

    QTime alarm = alarm.fromMSecsSinceStartOfDay(alarm_val);
    alarms.push_back(alarm);
    QString alarm_string = alarm.toString("hh : mm : ss");
    ui->alarmList->addItem(alarm_string);
}

void MainWindow::delete_timer(int i)
{
    timers.erase(timers.begin() + i);
    ui->timerList->takeItem(i);

}

void MainWindow::delete_alarm(int i)
{
  alarms.erase(alarms.begin() + i);
  ui->alarmList->takeItem(i);
}

void MainWindow::edit_timer(int val)
{
    int row = ui->timerList->currentRow();
    QTime curr_time = QTime::currentTime();
    int curr_time_int = curr_time.msecsSinceStartOfDay();
    timers[row] = val;
    QTime temp = QTime::fromMSecsSinceStartOfDay(val - curr_time_int);
    QString out = temp.toString("hh : mm : ss");
    ui->timerList->currentItem()->setText(out);
}

void MainWindow::edit_alarm(int val)
{
    int row = ui->alarmList->currentRow();
    QTime curr_time = QTime::currentTime();
    int curr_time_int = curr_time.msecsSinceStartOfDay();
    int alarm_int = val - curr_time_int;
    QTime alarm = alarm.fromMSecsSinceStartOfDay(alarm_int);
    alarms[row] = alarm;
    QString out = alarm.toString("hh : mm : ss");
    ui->alarmList->currentItem()->setText(out);
}

void MainWindow::on_editTimer_clicked()
{
    if (ui->timerList->currentRow() == -1)
        QMessageBox::information(this, "Wrong input", "You did not choose the item!");
    else{
         CTW = new CreateTimer(this);
         CTW->show();
         connect(CTW, &CreateTimer::timer_set, this, &MainWindow::edit_timer);
    }
}

void MainWindow::on_editAlarm_clicked()
{
    if (ui->alarmList->currentRow() == -1)
        QMessageBox::information(this, "Wrong input", "You did not choose the item!");
    else{
        CTW = new CreateTimer(this);
        CTW->show();
        connect(CTW, &CreateTimer::timer_set, this, &MainWindow::edit_alarm);
    }
}


void MainWindow::on_createTimer_clicked()
{
    CTW = new CreateTimer(this);
    CTW->show();
    connect(CTW ,&CreateTimer::timer_set, this, &MainWindow::add_timer);
}

void MainWindow::on_deleteTimer_clicked()
{
    if (ui->timerList->currentRow() == -1)
        QMessageBox::information(this, "Wrong input", "You did not choose the item!");
    else{
         int curr = ui->timerList->currentRow();
         delete_timer(curr);
    }
}


void MainWindow::on_createAlarm_clicked()
{
    CTW = new CreateTimer(this);
    CTW->show();
    connect(CTW ,&CreateTimer::timer_set, this, &MainWindow::add_alarm);
}

void MainWindow::on_deleteAlarm_clicked()
{
    if (ui->alarmList->currentRow() == -1)
        QMessageBox::information(this, "Wrong input", "You did not choose the item!");
    else{
         int curr = ui->alarmList->currentRow();
         delete_alarm(curr);
    }
}

