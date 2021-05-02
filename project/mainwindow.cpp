#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <scoresdialog.h>
#include <dialog.h>
#include <QMessageBox>
#include <QLayout>
#include <string>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QFile>
#include <QDataStream>



#include <QFontDatabase>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    showMaximized();


    ui->setupUi(this);
    selectLevel(ui->level);
    this->setStyleSheet("background-color: #6fc666;");


    // donanımdan gelen verilerle update

    int teamScore = 4;
    setTeamScore(teamScore);
    int computerScore = 3;
    setComputerScore(computerScore);

    //QLineEdit *q = new QLineEdit(this);
    //ui->IPaddress->setPlaceholderText("IP ADDRESS");


}

MainWindow::~MainWindow()
{
    delete ui;
}


// set team score
void MainWindow:: setTeamScore(int score){

    MainWindow::teamScore = score;
    ui->teamScoreLabel->display(MainWindow::teamScore);
    ui->teamScoreLabel->setDigitCount(QString("%1").arg(MainWindow::teamScore).length());

}

int MainWindow:: getTeamScore(){

    return MainWindow::teamScore;
}


// set computer score
void MainWindow:: setComputerScore(int score){

    MainWindow::computerScore = score;
    ui->computerScoreLabel->display(MainWindow::computerScore);
    ui->computerScoreLabel->setDigitCount(QString("%1").arg(MainWindow::computerScore).length());
}

int MainWindow:: getComputerScore(){

    return MainWindow::computerScore;
}

void MainWindow:: setLevel(int level){

    MainWindow::level = level;
}

int MainWindow:: getLevel(){

    return MainWindow::level;
}


// level combo
void MainWindow:: selectLevel(QComboBox *level){

    level->addItem("Easy");
    level->addItem("Normal");
    level->addItem("Hard");

}

// takes ip from hw and returns it
/*QString MainWindow:: getIPFromHardware(){

    QString ip = "192.168.1.1";

    return ip;
}*/


void MainWindow::on_startButton_clicked()
{
    // start game

    // check ip validation
    //QString ip = ui->IPaddress->text();
    //int equal = QString::compare(ip, getIPFromHardware(), Qt::CaseInsensitive);
    //ui->lab->setText(QString::number(equal));

    // null
    /*if(ip.isEmpty()){
        QMessageBox Msgbox;
        Msgbox.setText("IP address cannot be NULL");
        Msgbox.exec();
    }
    // not match
    else if(equal != 0){
        QMessageBox Msgbox;
        Msgbox.setText("Cannot connect the IP");
        Msgbox.exec();
    }*/

    Dialog dialog;
    dialog.setModal(true);
    dialog.exec();

}

void MainWindow::on_stopButton_clicked()
{
        writeFileScores(getTeamScore(), getComputerScore());

}

void MainWindow::on_level_currentIndexChanged(int index)
{

    //ui->lab->setText(QString::number(index));

    // index == 0 easy,  == 1 normal, == 2 hard

    setLevel(index);
    //qDebug() << getLevel();

}


void MainWindow:: writeFileScores(int computerScore, int teamScore){

    QString path = QDir::current().absolutePath() + "/scores.txt";
    QFile file(path);
    if(file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text)){
        //QMessageBox::information(0, "error", file.errorString());
        QTextStream stream(&file);
        stream<< "," << teamScore << "," << computerScore ;
        file.close();
        //qDebug() << "Writing finished";
    }

}

void MainWindow::on_scoresButton_clicked()
{
    ScoresDialog scores;
    scores.setModal(true);
    scores.exec();
}
