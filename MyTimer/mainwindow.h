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

    ~MainWindow();

public slots:
    void current_time();
    void give_signal();
    void add_timer(int in);
    void check_timers();
    void upd_timers();

private slots:
    void on_createTimer_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer, *checker;
    QDateTime curr_time;
    CreateTimer *CTW;
    FinishSignal *FSW;

    void delete_timer(int i);

};
#endif // MAINWINDOW_H
