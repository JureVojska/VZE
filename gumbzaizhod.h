#ifndef GUMBZAIZHOD_H
#define GUMBZAIZHOD_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>

class Gumbzaizhod:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Gumbzaizhod(QGraphicsItem* parent=NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);
private:
    QGraphicsTextItem *napis;
};

#endif // GUMBZAIZHOD_H
