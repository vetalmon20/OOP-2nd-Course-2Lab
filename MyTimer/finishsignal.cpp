#include "finishsignal.h"
#include "ui_finishsignal.h"

FinishSignal::FinishSignal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FinishSignal)
{
    ui->setupUi(this);
}

FinishSignal::~FinishSignal()
{
    delete ui;
}

void FinishSignal::on_OK_clicked()
{
    close();
}
