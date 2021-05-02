#include "moveitem.h"

MoveItem::MoveItem(int coordX,int coordY,int option,int number)
{
    speed=1;

    angle=(0);
    setRotation(angle);
    int StartX=coordX;
    int StartY=coordY;
    colorField=number;
    //if(qrand() % 1){

        optionShape=option;
    /*}
    else{
        StartX=(200);
        StartY=(200);
    }*/
    setPos(mapToParent(StartX,StartY));
}

MoveItem::~MoveItem()
{

}

void MoveItem::DoCollision()
{

}

void MoveItem::advance(int phase)
{
    if(!phase){
        return;
    }
    QPointF location=this->pos();
    speed=speed*-1;
    setPos(mapToParent(0,-(speed)));
}

QRectF MoveItem:: boundingRect() const
{
    if(optionShape==1){
        return QRectF (0,0,14,14);
    }
    else{
        return QRectF (0,0,10,10);
    }
}

void MoveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect=boundingRect();
    QBrush Brush=(Qt::darkGreen);
    if(colorField==0){
        Brush.setColor(Qt::white);
    }
    else if(colorField==1){
        Brush.setColor(Qt::red);
    }
    else if(colorField==2){
        Brush.setColor(Qt::darkBlue);
    }
    else if(colorField==3){
        Brush.setColor(Qt::yellow);
    }
    else if(colorField==4){
        Brush.setColor(QColor(105, 105, 105, 127));
    }

    if(!scene()->collidingItems(this).isEmpty()){
        DoCollision();
    }
    painter->setPen(Qt::black);
    if(optionShape==1){
        painter->fillRect(rect,Brush);
        painter->drawRect(rect);
    }
    else{
        painter->setBrush(Brush);
        painter->drawEllipse(rect);
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);
}



