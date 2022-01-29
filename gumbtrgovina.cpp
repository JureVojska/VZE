#include "gumbtrgovina.h"

#include"igra.h"
extern Igra *igra;

Gumbtrgovina::Gumbtrgovina(QGraphicsItem *parent): QGraphicsRectItem(parent){
    setRect(0,0,100,60);

    setAcceptHoverEvents(true);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
    napis= new QGraphicsTextItem("TRGOVINA",this);
    napis->setFont(QFont("times",13,QFont::Bold));
    napis->setPos(0,15);

}

void Gumbtrgovina::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    igra->zemljevid->preklic();
    igra->zemljevid->izrisi_trgovino();
}

void Gumbtrgovina::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);
}

void Gumbtrgovina::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

}


