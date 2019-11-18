#ifndef CREATETIMER_H
#define CREATETIMER_H

#include <QDialog>

namespace Ui {
class CreateTimer;
}

class CreateTimer : public QDialog
{
    Q_OBJECT

public:
    explicit CreateTimer(QWidget *parent = nullptr);
    ~CreateTimer();

private slots:
    void on_pushButton_clicked();

    int on_create_clicked();

signals:
    void timer_set(int time);

private:
    Ui::CreateTimer *ui;
};

#endif // CREATETIMER_H
