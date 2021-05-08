#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "moveitem.h"
#include "renderarea.h"
#include <scoresdialog.h>
#include <QMessageBox>
#include <QLayout>
#include <string>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QDataStream>
#include <QtWidgets>

#include <QFontDatabase>


//const int IdRole = Qt::UserRole;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    showMaximized();

    ui->setupUi(this);
    selectLevel(ui->level);
    this->setStyleSheet("background-color: #6fc666;");

    ui->startButton->setIcon(QIcon(":/images/images/play-button.png"));
    ui->startButton->setCheckable(true);
    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress("127.0.0.1"), 5051);

    scence = new QGraphicsScene(this);
    ui->graphicsView->setScene(scence);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setStyleSheet("background: transparent");
    scence->setSceneRect(0,0,100,100);

    QPen mypen=QPen(Qt::red);
    QLineF TopLine(scence->sceneRect().topLeft(),scence->sceneRect().topRight());
    QLineF LeftLine(scence->sceneRect().topLeft(),scence->sceneRect().bottomLeft());
    QLineF RightLine(scence->sceneRect().topRight(),scence->sceneRect().bottomRight());
    QLineF Bottom(scence->sceneRect().bottomLeft(),scence->sceneRect().bottomRight());


    mypen=QPen(Qt::white);
    scence->addRect(200, 8, 60, 80,mypen);
    scence->addRect(-155, 8, 60, 80,mypen);
    scence->addRect(225, 28, 40, 40,mypen);
    scence->addRect(-160, 28, 40, 40,mypen);

    scence->addLine(50, -120, 50, 250,mypen);

    scence->addEllipse(30, 30, 40, 40,mypen);
    scence->addEllipse(10, 10, 80, 80,mypen);
    mypen=QPen(Qt::black);

    scence->addLine(5, -120, 5, 250,mypen);
    scence->addLine(95, -120, 95, 250,mypen);

    scence->addLine(-120, -120, -120, 250,mypen);
    scence->addLine(225, -120, 225, 250,mypen);
    scence->setBackgroundBrush(Qt::darkGreen);
    int ItemCount=1;

    for(int i =0;i<ItemCount;i++){
        MoveItem *ball=new MoveItem(45,45,0,0,0);
        MoveItem *rect11=new MoveItem(-127,-20,1,1,0);
        MoveItem *rect12=new MoveItem(-127,40,1,2,0);
        MoveItem *rect13=new MoveItem(-127,100,1,1,0);

        MoveItem *rect14=new MoveItem(88,-20,1,1,1);
        MoveItem *rect15=new MoveItem(88,40,1,1,1);
        MoveItem *rect16=new MoveItem(88,100,1,1,1);



        MoveItem *rect21=new MoveItem(218,-20,1,3,0);
        MoveItem *rect22=new MoveItem(218,40,1,4,0);
        MoveItem *rect23=new MoveItem(218,100,1,3,0);

        MoveItem *rect24=new MoveItem(-2,-20,1,3,1);
        MoveItem *rect25=new MoveItem(-2,40,1,3,1);
        MoveItem *rect26=new MoveItem(-2,100,1,3,1);

        scence->addItem(ball);
        scence->addItem(rect11);
        scence->addItem(rect12);
        scence->addItem(rect13);
        scence->addItem(rect14);
        scence->addItem(rect15);
        scence->addItem(rect16);

        scence->addItem(rect21);
        scence->addItem(rect22);
        scence->addItem(rect23);
        scence->addItem(rect24);
        scence->addItem(rect25);
        scence->addItem(rect26);
    }
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),scence,SLOT(advance()));
    timer->start(100);


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


/*void MainWindow::on_startButton_clicked()
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

//    Dialog dialog;
//    dialog.setModal(true);
//    dialog.exec();

//}


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

void MainWindow ::Connect() {
    if(socket->waitForConnected()) {
           socket->write(this->command.toUtf8().constData());
           socket->waitForBytesWritten();

           /*
           // add if client reads from server
           socket->waitForReadyRead(3000);
           //qDebug() << "Reading from server: " << socket->bytesAvailable();
           //qDebug() << socket->readAll();*/

       }
}


/*void MainWindow::on_startButton_toggled(bool checked)
{
    if(checked) {
        ui->startButton->setIcon(QIcon(":/images/pause-icon.png"));
        this->command = "SYSTEM_START";
    }
    else {
        ui->startButton->setIcon(QIcon(":/images/play-button.png"));
        this->command = "SYSTEM_RESUME";
    }
    this->Connect();
}
*/
void MainWindow::on_stopButton_clicked()
{
    this->command = "STOP";
    this->Connect();
    socket->close();
    //this->close();
}



void MainWindow::on_startButton_toggled(bool checked)
{
    if(checked) {
        ui->startButton->setIcon(QIcon(":/images/images/pause-icon.png"));
        this->command = "START";
    }
    else {
        ui->startButton->setIcon(QIcon(":/images/images/play-button.png"));
        this->command = "RESUME";
    }
    this->Connect();


}
