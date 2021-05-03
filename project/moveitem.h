#ifndef MOVEITEM_H
#define MOVEITEM_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class MoveItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MoveItem(int coordX,int coordY,int option,int number,int groupObject);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~MoveItem();
    int colorField;
    int optionShape;
    int maxKatsayi;
    int turn;
    int conditionMax;
    int flag;
    int group;

signals:

private:
    qreal angle;
    qreal speed;
    void DoCollision();


protected:
    void advance(int phase);

public slots:
};

#endif // MOVEITEM_H
