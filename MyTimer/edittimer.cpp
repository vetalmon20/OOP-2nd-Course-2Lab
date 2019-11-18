#include "edittimer.h"
#include "ui_edittimer.h"

EditTimer::EditTimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditTimer)
{
    ui->setupUi(this);
}

EditTimer::~EditTimer()
{
    delete ui;
}

void EditTimer::on_cancel_clicked()
{
    this->close();
}

int EditTimer::on_create_clicked()
{
    QTime user_time = ui->timeEdit->time();
    QTime curr_time = QTime::currentTime();
    int a, b, c;
    a = user_time.msecsSinceStartOfDay();
    b = curr_time.msecsSinceStartOfDay();
    c = a + b;
    emit timer_change(c);
    this->close();
    return c;
}
