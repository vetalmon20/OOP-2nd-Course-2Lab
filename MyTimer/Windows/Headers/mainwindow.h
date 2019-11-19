#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include "createtimer.h"
#include "createalarm.h"
#include "finishsignal.h"
#include <vector>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow class describes the proper ui window that represents the main user interface and all possibilities of the program
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    std::vector <int> timers;
    std::vector <bool> timers_to_check;
    std::vector <QTime> alarms;

    std::vector <int> timers_audio;
    std::vector <int> alarms_audio;

    ~MainWindow();

public slots:
    /**
     * @brief current_time shows the current time in the main window
     */
    void current_time();

    /**
     * @brief give_signal is implemeted when the timer or alarm is worked. It just opens the finishsignal window and play the proper audio
     * @param i is the value of the certain audio to play
     */
    void give_signal(int i);

    /**
     * @brief add_timer adds the timer to the timer list.
     * @param in is the value of the time in msecs
     * @param audio_num the number of the proper audio to play
     * @param ifchecked tells if the value of the time of the current timer should be changed in timer list
     */
    void add_timer(int in, int audio_num, bool ifchecked);

    /**
     * @brief edit_timer edits the chosen timer in the timer list.
     * @param in is the value of the time in msecs
     * @param audio_num the number of the proper audio to play
     * @param ifchecked tells if the value of the time of the current timer should be changed in timer list
     */
    void edit_timer(int val, int audio_num, bool ifchecked);

    /**
     * @brief check_timers check all of the timers if their time is up
     */
    void check_timers();

    /**
     * @brief upd_timers updates the value of the proper timers in the timer list
     */
    void upd_timers();

    /**
     * @brief add_alarm adds the alarm to the alarm list.
     * @param in is the value of the time in msecs
     * @param audio_num the number of the proper audio to play
     */
    void add_alarm(int in, int audio_num);

    /**
     * @brief edit_alarm edits the alarm in the alarm list.
     * @param in is the value of the time in msecs
     * @param audio_num the number of the proper audio to play
     */
    void edit_alarm(int val, int audio_num);

    /**
     * @brief check_alarms check all of the alarms if their time is up
     */
    void check_alarms();

private slots:

    /**
     * @brief on_createTimer_clicked is implemeted when the button "create Timer" is clicked. It opens the createtimer window.
     */
    void on_createTimer_clicked();

    /**
     * @brief on_deleteTimer_clicked  is implemeted when the button "delete Timer" is clicked. It calls the delete function for the current timer in the list.
     */
    void on_deleteTimer_clicked();

    /**
     * @brief on_editTimer_clicked  is implemeted when the button "edit Timer" is clicked. It opens the createtimer window for the current timer in the list.
     */
    void on_editTimer_clicked();

    /**
     * @brief on_createAlarm_clicked  is implemeted when the button "create Alarm" is clicked.  It opens the createalarm window.
     */
    void on_createAlarm_clicked();

    /**
     * @brief on_deleteAlarm_clicked is implemeted when the button "delete Alarm" is clicked. It calls the delete function for the current alarm in the list.
     */
    void on_deleteAlarm_clicked();

    /**
     * @brief on_editAlarm_clicked is implemeted when the button "edit Alarm" is clicked. It opens the createalarm window for the current alarm in the list.
     */
    void on_editAlarm_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer, *checker;
    QDateTime curr_time;
    CreateTimer *CTW;
    createAlarm *CAW;
    FinishSignal *FSW;

    /**
     * @brief delete_timer just deletes the timer from the list
     * @param i the index of the timer to delete
     */
    void delete_timer(int i);

    /**
     * @brief delete_alarm  just deletes the alarm from the list
     * @param i the index of the alarm to delete
     */
    void delete_alarm(int i);

};
#endif // MAINWINDOW_H
