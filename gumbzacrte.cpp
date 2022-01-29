#include "gumbzacrte.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include"igra.h"
extern Igra *igra;

GumbzaCrte::GumbzaCrte(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){

    // draw the rect

    setRect(0,0,30,30);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(209, 167, 122));

    setBrush(brush);



    // draw the text

    text = new QGraphicsTextItem(name,this);

    int xPos = rect().width()/2 - text->boundingRect().width()/2;

    int yPos = rect().height()/2 - text->boundingRect().height()/2;

    text->setPos(xPos,yPos);



    // allow responding to hover events

    setAcceptHoverEvents(true);

}


void GumbzaCrte::hoverEnterEvent(QGraphicsSceneHoverEvent *){

    // change color to cyan
    igra->zemljevid->preklic();
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(152, 104, 52));
    setBrush(brush);
    emit aktiviraj();

}



void GumbzaCrte::hoverLeaveEvent(QGraphicsSceneHoverEvent *){

    // change color to dark cyan

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(209, 167, 122));
    setBrush(brush);
    emit aktiviraj();

}
