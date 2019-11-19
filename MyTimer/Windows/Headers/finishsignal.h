#ifndef FINISHSIGNAL_H
#define FINISHSIGNAL_H

#include <QDialog>

namespace Ui {
class FinishSignal;
}

/**
 * @brief The FinishSignal class describes the proper ui window that is dedicated to emit the audio and visual signal after the end of the alarm/timer
 */
class FinishSignal : public QDialog
{
    Q_OBJECT

public:
    explicit FinishSignal(QWidget *parent = nullptr);
    ~FinishSignal();

private slots:
    /**
     * @brief on_OK_clicked is implemeted when the button "pushButton" is clicked. It just closes the window.
     */
    void on_OK_clicked();

private:
    Ui::FinishSignal *ui;
};

#endif // FINISHSIGNAL_H
