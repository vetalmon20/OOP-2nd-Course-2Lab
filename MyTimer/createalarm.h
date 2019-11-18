#ifndef CREATEALARM_H
#define CREATEALARM_H

#include <QDialog>
#include "chooseaudio.h"

namespace Ui {
class createAlarm;
}

class createAlarm : public QDialog
{
    Q_OBJECT

public:
    explicit createAlarm(QWidget *parent = nullptr);
    ~createAlarm();

private slots:
    void on_pushButton_clicked();

    int on_create_clicked();

    void on_chooseAudio_clicked();

    void set_audio_num(int in);

    void on_AmTimer_clicked();

    void on_defaultTimer_clicked();

signals:
    void timer_set(int time, int audio_num);

private:
    Ui::createAlarm *ui;
    ChooseAudio *CAW;
    int audio_num;
};

#endif // CREATEALARM_H
