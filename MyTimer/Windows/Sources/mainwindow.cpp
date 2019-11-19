#include "../MyTimer/Windows/Headers/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include "../MyTimer/Windows/Headers/createtimer.h"
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

/**
 * @brief current_time shows the current time in the main window
 */
void MainWindow::current_time()
{
    QTime curr_time = QTime::currentTime();
    QString curr_time_text = curr_time.toString("hh : mm : ss");
    ui->labelTimer->setText(curr_time_text);

}

/**
 * @brief check_timers check all of the timers if their time is up
 */
void MainWindow:: check_timers(){

    QTime curr_time = QTime::currentTime();
    int curr_int;
    curr_int = curr_time.msecsSinceStartOfDay();

    for (unsigned long long int i = 0; i < timers.size(); i++){
        if(curr_int  >= timers[i]){
            give_signal(timers_audio[i]);
            delete_timer(i);
        }
    }
}

/**
 * @brief check_alarms check all of the alarms if their time is up
 */
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
            give_signal(alarms_audio[i]);
    }
}

/**
 * @brief give_signal is implemeted when the timer or alarm is worked. It just opens the finishsignal window and play the proper audio
 * @param i is the value of the certain audio to play
 */
void MainWindow:: give_signal(int i){


    FSW = new FinishSignal(this);
    FSW->show();
    QMediaPlayer *player = new QMediaPlayer;
    QString path = "D:/MyRepositories/OOP/OOP-2nd-Course-2Lab/MyTimer/Audio/1.mp3";
    switch (i) {
        case 0:{
            path = "D:/MyRepositories/OOP/OOP-2nd-Course-2Lab/MyTimer/Audio/1.mp3";
            break;
        }
        case 1:{
            path = "D:/MyRepositories/OOP/OOP-2nd-Course-2Lab/MyTimer/Audio/2.mp3";
            break;
        }
        case 2:{
            path = "D:/MyRepositories/OOP/OOP-2nd-Course-2Lab/MyTimer/Audio/3.mp3";
            break;
        }
    }
    QUrl adress(QFileInfo(path).absoluteFilePath());
    player->setMedia(adress);
    player->setVolume(50);
    player->play();
}

/**
 * @brief add_timer adds the timer to the timer list.
 * @param in is the value of the time in msecs
 * @param audio_num the number of the proper audio to play
 * @param ifchecked tells if the value of the time of the current timer should be changed in timer list
 */
void MainWindow::add_timer(int in, int audio_num, bool ifchecked)
{
    timers_audio.push_back(audio_num);
    timers_to_check.push_back(ifchecked);
    QTime temp, curr_time;
    curr_time  = QTime::currentTime();
    int a, res;
    a = curr_time.msecsSinceStartOfDay();
    res = in - a;
    temp = temp.fromMSecsSinceStartOfDay(res);

    QString time_string = temp.toString("hh : mm : ss");
    ui->timerList->addItem(time_string);
    if(ifchecked == 0)
        timers.push_back(in - a);
    else
        timers.push_back(in);
}

/**
 * @brief upd_timers updates the value of the proper timers in the timer list
 */
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
            if(timers_to_check[i] == 1){
                temp_text = temp_time.toString("hh : mm : ss");
                ui->timerList->item(i)->setText(temp_text);
        }
    }

}

/**
 * @brief add_alarm adds the alarm to the alarm list.
 * @param in is the value of the time in msecs
 * @param audio_num the number of the proper audio to play
 */
void MainWindow::add_alarm(int in, int audio_num)
{
    QTime curr_time = QTime::currentTime();
    int curr_time_int = curr_time.msecsSinceStartOfDay();
    int alarm_val = in - curr_time_int;

    QTime alarm = alarm.fromMSecsSinceStartOfDay(alarm_val);
    alarms.push_back(alarm);
    alarms_audio.push_back(audio_num);
    QString alarm_string = alarm.toString("hh : mm : ss");
    ui->alarmList->addItem(alarm_string);
}

/**
 * @brief delete_timer just deletes the timer from the list
 * @param i the index of the timer to delete
 */
void MainWindow::delete_timer(int i)
{
    timers.erase(timers.begin() + i);
    timers_audio.erase(timers_audio.begin() + i);
    timers_to_check.erase(timers_to_check.begin() + i);
    ui->timerList->takeItem(i);

}

/**
 * @brief delete_alarm  just deletes the alarm from the list
 * @param i the index of the alarm to delete
 */
void MainWindow::delete_alarm(int i)
{
  alarms.erase(alarms.begin() + i);
  alarms_audio.erase(alarms_audio.begin() + i);
  ui->alarmList->takeItem(i);
}

/**
 * @brief edit_timer edits the chosen timer in the timer list.
 * @param in is the value of the time in msecs
 * @param audio_num the number of the proper audio to play
 * @param ifchecked tells if the value of the time of the current timer should be changed in timer list
 */
void MainWindow::edit_timer(int val, int audio_num, bool ifchecked)
{
    int row = ui->timerList->currentRow();
    if(row == -1)
        return;
    QTime curr_time = QTime::currentTime();
    int curr_time_int = curr_time.msecsSinceStartOfDay();
    if(ifchecked == 1)
         timers[row] = val;
    else
        timers[row] = val - curr_time_int;
    timers_audio[row] = audio_num;
    timers_to_check[row] = ifchecked;
    QTime temp;
    temp = QTime::fromMSecsSinceStartOfDay(val - curr_time_int);
    QString out = temp.toString("hh : mm : ss");
    ui->timerList->currentItem()->setText(out);
}

/**
 * @brief edit_alarm edits the alarm in the alarm list.
 * @param in is the value of the time in msecs
 * @param audio_num the number of the proper audio to play
 */
void MainWindow::edit_alarm(int val, int audio_num)
{
    int row = ui->alarmList->currentRow();
    if(row == -1)
        return;
    QTime curr_time = QTime::currentTime();
    int curr_time_int = curr_time.msecsSinceStartOfDay();
    int alarm_int = val - curr_time_int;
    QTime alarm = alarm.fromMSecsSinceStartOfDay(alarm_int);
    alarms[row] = alarm;
    alarms_audio[row] = audio_num;
    QString out = alarm.toString("hh : mm : ss");
    ui->alarmList->currentItem()->setText(out);
}

/**
 * @brief on_editTimer_clicked  is implemeted when the button "edit Timer" is clicked. It opens the createtimer window for the current timer in the list.
 */
void MainWindow::on_editTimer_clicked()
{
    if (ui->timerList->currentRow() == -1)
        QMessageBox::information(this, "Wrong input", "You did not choose the item!");
    else{
         CTW = new CreateTimer(this);
         CTW->show();
         connect(CTW, &CreateTimer::timer_set, this, &MainWindow::edit_timer);
         connect(CTW, &CreateTimer::timer_alarm_set, this, &MainWindow::edit_timer);
    }
}

/**
 * @brief on_editAlarm_clicked is implemeted when the button "edit Alarm" is clicked. It opens the createalarm window for the current alarm in the list.
 */
void MainWindow::on_editAlarm_clicked()
{
    if (ui->alarmList->currentRow() == -1)
        QMessageBox::information(this, "Wrong input", "You did not choose the item!");
    else{
        CAW = new createAlarm(this);
        CAW->show();
        connect(CAW ,&createAlarm::timer_set, this, &MainWindow::edit_alarm);
    }
}

/**
 * @brief on_createTimer_clicked is implemeted when the button "create Timer" is clicked. It opens the createtimer window.
 */
void MainWindow::on_createTimer_clicked()
{
    CTW = new CreateTimer(this);
    CTW->show();
    connect(CTW ,&CreateTimer::timer_set, this, &MainWindow::add_timer);
    connect(CTW ,&CreateTimer::timer_alarm_set, this, &MainWindow::add_timer);
}

/**
 * @brief on_deleteTimer_clicked  is implemeted when the button "delete Timer" is clicked. It calls the delete function for the current timer in the list.
 */
void MainWindow::on_deleteTimer_clicked()
{
    if (ui->timerList->currentRow() == -1)
        QMessageBox::information(this, "Wrong input", "You did not choose the item!");
    else{
         int curr = ui->timerList->currentRow();
         if(curr == -1)
             return;
         delete_timer(curr);
    }
}

/**
 * @brief on_createAlarm_clicked  is implemeted when the button "create Alarm" is clicked.  It opens the createalarm window.
 */
void MainWindow::on_createAlarm_clicked()
{
    CAW = new createAlarm(this);
    CAW->show();
    connect(CAW ,&createAlarm::timer_set, this, &MainWindow::add_alarm);
}

/**
 * @brief on_deleteAlarm_clicked is implemeted when the button "delete Alarm" is clicked. It calls the delete function for the current alarm in the list.
 */
void MainWindow::on_deleteAlarm_clicked()
{
    if (ui->alarmList->currentRow() == -1)
        QMessageBox::information(this, "Wrong input", "You did not choose the item!");
    else{
         int curr = ui->alarmList->currentRow();
         delete_alarm(curr);
    }
}

