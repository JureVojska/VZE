#ifndef OPOZORILO_H
#define OPOZORILO_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>

class Opozorilo:public QObject, public QGraphicsRectItem
{
public:
    Opozorilo();
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);
    void prikazsporocila(int o);
private:
    QGraphicsTextItem *napis;
};

#endif // OPOZORILO_H
