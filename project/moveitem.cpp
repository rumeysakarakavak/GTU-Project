#include "moveitem.h"

MoveItem::MoveItem(int coordX,int coordY,int option,int number,int groupObject)
{
    speed=1;
    turn=0;
    maxKatsayi=1;
    flag=0;
    conditionMax=9;
    group=groupObject;
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
    if(optionShape==1){
        if(group==0)
            setPos(mapToParent(0,-(speed)));
        else
            setPos(mapToParent(0,-(speed)*6));
    }
    else{
        setPos(mapToParent((maxKatsayi),0));
        if(turn==0){
            maxKatsayi+=1;
        }
        else{
            maxKatsayi-=1;
        }
        if(maxKatsayi==conditionMax || maxKatsayi==(conditionMax*-1)){
            if(turn==0 && maxKatsayi==conditionMax){
                maxKatsayi=0;
                turn=1;
                if(flag==1){
                    maxKatsayi=0;
                    conditionMax=25;
                }
                printf("aaaa");
            }
            else if(turn==0 && maxKatsayi==(conditionMax*-1)){
                maxKatsayi=0;
                conditionMax=48;
                turn=0;
                printf("bbbb");
            }
            else if(turn==1 && maxKatsayi==conditionMax){
                maxKatsayi=-9;
                conditionMax=40;
                turn=0;
                printf("cccc");
            }
            else if(turn==1 && maxKatsayi==(conditionMax*-1)){
                maxKatsayi=-9;
                if(flag==1){
                    conditionMax=27;
                }
                else{
                    conditionMax=21;
                }
                turn=0;
                flag=1;
                printf("dddd");
            }
        }

    }

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



