#include "dialog.h"
#include "ui_dialog.h"
#include "moveitem.h"
#include <QtWidgets>
#include "renderarea.h"

const int IdRole = Qt::UserRole;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
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
}

Dialog::~Dialog()
{
    delete ui;
}


