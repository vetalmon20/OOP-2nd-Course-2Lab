#ifndef EDITTIMER_H
#define EDITTIMER_H

#include <QDialog>

namespace Ui {
class EditTimer;
}

class EditTimer : public QDialog
{
    Q_OBJECT

public:
    explicit EditTimer(QWidget *parent = nullptr);
    ~EditTimer();

private slots:
    void on_cancel_clicked();

    int on_create_clicked();

signals:
    void timer_change(int time);

private:
    Ui::EditTimer *ui;
};

#endif // EDITTIMER_H
