#include "gumbzaizhod.h"
#include"igra.h"
#include "konec.h"
extern Igra *igra;

Gumbzaizhod::Gumbzaizhod(QGraphicsItem *parent): QGraphicsRectItem(parent){
    setRect(0,0,50,40);

    setAcceptHoverEvents(true);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
    napis= new QGraphicsTextItem("IZHOD",this);
    napis->setFont(QFont("times",9, QFont::Bold));
    napis->setPos(0,9);

}

void Gumbzaizhod::mousePressEvent(QGraphicsSceneMouseEvent *)
{

    igra->bitka->izbrisivseizbitke();
    igra->zemljevid->izbrisivseizzemljevida();
    igra->izbrisivseizigre();
    igra->close();
}

void Gumbzaizhod::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);
}

void Gumbzaizhod::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

}

