#ifndef CREATETIMER_H
#define CREATETIMER_H

#include <QDialog>
#include "chooseaudio.h"

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

    void on_chooseAudio_clicked();

    void set_audio_num(int in);

signals:
    void timer_set(int time, int audio_num);

private:
    Ui::CreateTimer *ui;
    ChooseAudio *CAW;
    int audio_num;
};

#endif // CREATETIMER_H
