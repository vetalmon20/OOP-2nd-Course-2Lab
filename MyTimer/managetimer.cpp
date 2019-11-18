#include "managetimer.h"
#include "ui_managetimer.h"

ManageTimer::ManageTimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageTimer)
{
    ui->setupUi(this);
}

ManageTimer::~ManageTimer()
{
    delete ui;
}
