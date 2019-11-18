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
    emit timer_set(c);
    this->close();
    return c;
}
