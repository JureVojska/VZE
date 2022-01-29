#ifndef GUMBTRGOVINA_H
#define GUMBTRGOVINA_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>

class Gumbtrgovina:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Gumbtrgovina(QGraphicsItem* parent=NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);
private:
    QGraphicsTextItem *napis;



};

#endif // GUMBTRGOVINA_H
