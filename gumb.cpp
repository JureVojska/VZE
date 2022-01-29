#include "Gumb.h"

#include <QGraphicsTextItem>

#include <QBrush>
#include <QFont>


Gumb::Gumb(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setRect(0,0,60,60);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(119, 119, 60));
    setBrush(brush);


    text = new QGraphicsTextItem(name,this);
    text->setFont(QFont("times",9,QFont::Bold));
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;


    text->setPos(xPos,yPos);

    setAcceptHoverEvents(true);

}



void Gumb::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    emit aktiviraj();
}



void Gumb::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(85, 85, 43));
    setBrush(brush);

}



void Gumb::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(119, 119, 60));
    setBrush(brush);
}
