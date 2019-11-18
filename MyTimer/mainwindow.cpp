#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include "createtimer.h"
#include <QMediaPlayer>
#include <QUrl>
#include <QFileInfo>
#include <QDebug>


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
        if(curr_int + 1000 >= timers[i]){
            give_signal();
            delete_timer(i);
        }
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

void MainWindow::delete_timer(int i)
{
    timers.erase(timers.begin() + i);
    ui->timerList->takeItem(i);

}


void MainWindow::on_createTimer_clicked()
{
    CTW = new CreateTimer(this);
    CTW->show();
    connect(CTW ,&CreateTimer::timer_set, this, &MainWindow::add_timer);
}

void MainWindow::on_pushButton_clicked()
{
    for(unsigned long long int i = 0; i < timers.size(); i++){
        qDebug() << timers[i] << " ";
    }
}
