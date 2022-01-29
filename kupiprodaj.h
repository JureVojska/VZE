#ifndef KUPIPRODAJ_H
#define KUPIPRODAJ_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>

class Kupiprodaj:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Kupiprodaj(int st_izdelka, bool kupi, int c, QGraphicsItem *parent);
    void mousePressEvent(QGraphicsSceneMouseEvent *);

private:
    int izdelek;
    bool kalip; //kupi ali prodaj
    int cena;
};
#endif // KUPIPRODAJ_H
