#ifndef MANAGETIMER_H
#define MANAGETIMER_H

#include <QDialog>

namespace Ui {
class ManageTimer;
}

class ManageTimer : public QDialog
{
    Q_OBJECT

public:
    explicit ManageTimer(QWidget *parent = nullptr);
    ~ManageTimer();

private:
    Ui::ManageTimer *ui;
};

#endif // MANAGETIMER_H
