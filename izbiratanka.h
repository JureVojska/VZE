#ifndef IZBIRATANKA_H
#define IZBIRATANKA_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QBrush>

class Izbiratanka:public QObject, public QGraphicsRectItem{
    Q_OBJECT
private:
    short st_tanka;
    short st_drzave;
    bool na_ba;
    QBrush brush;
public:
    Izbiratanka(short st, short st_dr, bool nap_bra, QGraphicsItem* parent=NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);
};

#endif // IZBIRATANKA_H
