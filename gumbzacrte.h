#ifndef GUMBZACRTE_H
#define GUMBZACRTE_H

#include <QGraphicsRectItem>

#include <QGraphicsSceneMouseEvent>



class GumbzaCrte:public QObject, public QGraphicsRectItem{

    Q_OBJECT

public:
    GumbzaCrte(QString name, QGraphicsItem* parent=NULL);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);

signals:

    void aktiviraj();

private:

    QGraphicsTextItem* text;

};
#endif // GUMBZACRTE_H
