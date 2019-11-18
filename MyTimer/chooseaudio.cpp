#include "chooseaudio.h"
#include "ui_chooseaudio.h"
#include <QMessageBox>
#include <QMediaPlayer>
#include <QUrl>
#include <QFileInfo>

ChooseAudio::ChooseAudio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseAudio)
{
    ui->setupUi(this);
    ui->listAudio->addItem("1.mp3");
    ui->listAudio->addItem("2.mp3");
    ui->listAudio->addItem("3.mp3");
    player = new QMediaPlayer;
    audio_num = 0;
}

ChooseAudio::~ChooseAudio()
{
    delete ui;
}

void ChooseAudio::on_listen_clicked()
{
    player->stop();
    int row = ui->listAudio->currentRow();
    if (row == -1)
        QMessageBox::information(this, "Wrong input", "You did not choose the item!");
    else{
        QString path;// "D:/MyRepositories/OOP/OOP-2nd-Course-2Lab/MyTimer/Audio/1.mp3";
        switch(row){
            case 0:{
                path = "D:/MyRepositories/OOP/OOP-2nd-Course-2Lab/MyTimer/Audio/1.mp3";
                break;
            }
            case 1:{
                path = "D:/MyRepositories/OOP/OOP-2nd-Course-2Lab/MyTimer/Audio/2.mp3";
                break;
            }
            case 2:{
                path = "D:/MyRepositories/OOP/OOP-2nd-Course-2Lab/MyTimer/Audio/3.mp3";
                break;
            }
        }
        QUrl adress1(QFileInfo(path).absoluteFilePath());
        player->setMedia(adress1);
        player->setVolume(50);
        player->play();
    }
}

void ChooseAudio::on_choose_clicked()
{
    player->stop();
    int row = ui->listAudio->currentRow();
    if (row == -1)
        QMessageBox::information(this, "Wrong input", "You did not choose the item!");
    else{

        switch(row){
            case 0:{
                audio_num = 0;
                break;
            }
            case 1:{
                audio_num = 1;
                break;
            }
            case 2:{
                audio_num = 2;
                break;
            }
        }
    }
    emit audio_type(audio_num);
    this->close();
}
