#ifndef TANK_H
#define TANK_H

#include<QObject>
#include<QGraphicsPixmapItem>
#include "katyusha.h"
#include"letalo.h"
#include"top.h"

class Tank:public QObject,public QGraphicsPixmapItem{
Q_OBJECT
public:
    Tank(bool stev);
    ~Tank();
    void nastaviTank(int x, int y, int zx, int zy, QString slika, short vrsta);
    void keyPressEvent(QKeyEvent *event);
    void ustreli();

    float get_kot_stopinje(){
        return 180*kot_radiani/3.1415926;
    }
    static bool dovoli_premik;

    static short nacin;
    static bool izpisano;

    Katyusha *raketomet;
    Letalo *bomber;

    int skoda_napada;
    int moc;
    int zivljenske_tocke;
    int bencin;

private:

    int tposx,tposy;
    int zamik_x,zamik_y;

    float kot_radiani;
    bool st_igralca;
};

#endif // TANK_H
