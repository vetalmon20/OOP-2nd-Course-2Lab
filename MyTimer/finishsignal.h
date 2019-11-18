#ifndef FINISHSIGNAL_H
#define FINISHSIGNAL_H

#include <QDialog>

namespace Ui {
class FinishSignal;
}

class FinishSignal : public QDialog
{
    Q_OBJECT

public:
    explicit FinishSignal(QWidget *parent = nullptr);
    ~FinishSignal();

private slots:
    void on_OK_clicked();

private:
    Ui::FinishSignal *ui;
};

#endif // FINISHSIGNAL_H
