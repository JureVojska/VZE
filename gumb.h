
#ifndef GUMB_H

#define GUMB_H



#include <QGraphicsRectItem>

#include <QGraphicsSceneMouseEvent>



class Gumb:public QObject, public QGraphicsRectItem{

    Q_OBJECT

public:
    Gumb(QString name, QGraphicsItem* parent=NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);

signals:

    void aktiviraj();

private:

    QGraphicsTextItem* text;

};

#endif // GUMB_H
