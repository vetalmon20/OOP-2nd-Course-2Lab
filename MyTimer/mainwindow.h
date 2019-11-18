#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include "createtimer.h"
#include "finishsignal.h"
#include <vector>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    std::vector <int> timers;
    std::vector <QTime> alarms;

    std::vector <int> timers_audio;
    std::vector <int> alarms_audio;

    ~MainWindow();

public slots:
    void current_time();
    void give_signal(int i);

    void add_timer(int in, int audio_num);
    void edit_timer(int val, int audio_num);
    void check_timers();
    void upd_timers();

    void add_alarm(int in, int audio_num);
    void edit_alarm(int val, int audio_num);
    void check_alarms();

private slots:
    void on_createTimer_clicked();

    void on_deleteTimer_clicked();

    void on_editTimer_clicked();

    void on_createAlarm_clicked();

    void on_deleteAlarm_clicked();

    void on_editAlarm_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer, *checker;
    QDateTime curr_time;
    CreateTimer *CTW;
    FinishSignal *FSW;

    void delete_timer(int i);
    void delete_alarm(int i);

};
#endif // MAINWINDOW_H
