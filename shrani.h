#ifndef SHRANI_H
#define SHRANI_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>

class Shrani:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Shrani(bool sn,QGraphicsItem* parent=NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);
    void shraniigro();
    void naloziigro();
    void sezidaj();
private:
    QGraphicsTextItem *napis;
    bool shrani_nalozi;
};



#endif // SHRANI_H
