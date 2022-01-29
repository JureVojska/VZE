#ifndef TRGOVINA_H
#define TRGOVINA_H

#include<QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include"kupiprodaj.h"

class Trgovina:public QObject, public QGraphicsRectItem
{
public:
    Trgovina();
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);
    void ustvari_napise();
    void ustvari_slike();
    void ustvari_gumbe();
    void podatki_trgovine( int igralecnavrsti);
    void posodobi();
    void izbrisivseiztrgovine();

private:
    QGraphicsTextItem *denar_st;
    QGraphicsTextItem *lahki_st;
    QGraphicsTextItem *srednji_st;
    QGraphicsTextItem *tezki_st;
    QGraphicsTextItem *katyusha_st;
    QGraphicsTextItem *ladje_st;
    QGraphicsTextItem *letala_st;


    QGraphicsPixmapItem *light_tank;
    QGraphicsPixmapItem *medium_tank;
    QGraphicsPixmapItem *heavy_tank;
    QGraphicsPixmapItem *katyusha;
    QGraphicsPixmapItem *letalo;
    QGraphicsPixmapItem *ladja;
    Kupiprodaj *lahki_kupi;
    Kupiprodaj *lahki_prodaj;
    Kupiprodaj *srednji_kupi;
    Kupiprodaj *srednji_prodaj;
    Kupiprodaj *tezki_kupi;
    Kupiprodaj *tezki_prodaj;
    Kupiprodaj *katyusha_kupi;
    Kupiprodaj *katyusha_prodaj;
    Kupiprodaj *ladja_kupi;
    Kupiprodaj *ladja_prodaj;
    Kupiprodaj *letalo_kupi;
    Kupiprodaj *letalo_prodaj;
    int denar;
    int igralecnavrst;

};

#endif // TRGOVINA_H
