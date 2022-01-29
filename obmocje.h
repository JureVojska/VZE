#ifndef OBMOCJE_H
#define OBMOCJE_H

#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>



class Obmocje:public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Obmocje(QString ime, int x, int y, short od, short id, short povrsje, QGraphicsItem* parent=NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);
    void pobarvaj();
    void pobarvaj2();
    void nastej_sosede(int a, int b, int c, int d, int e);
    void oznaci_sosednja_obmocja();
    void oznaci_za_grajenje();
    void crtaj(bool a);

    void postavitovarno();
    void postavimesto();
    QGraphicsPixmapItem *infrastruktura;

    int get_drzava();
    int sosedi[5];
    bool dovoli_napad;
    bool dovoli_grajenje;
    short drzava;
    short mes_tov;
    short geo;
signals:


private:
    QGraphicsTextItem* ime_kraja;
    QGraphicsLineItem *crta[5];
    short stevilka;
    int red;
    int green;
    int blue;
    short st_sosedov;
};

#endif // OBMOCJE_H
