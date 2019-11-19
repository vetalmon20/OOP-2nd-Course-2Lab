#include "../MyTimer/Windows/Headers/finishsignal.h"
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

/**
 * @brief on_OK_clicked is implemeted when the button "pushButton" is clicked. It just closes the window.
 */
void FinishSignal::on_OK_clicked()
{
    close();
}
