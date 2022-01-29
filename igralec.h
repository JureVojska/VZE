#ifndef IGRALEC_H
#define IGRALEC_H

#include<QGraphicsPixmapItem>
#include <QString>

class Igralec
{
public:
    Igralec();
    int denar;
    QString za_v_shop[4];
    QString tanki[4];
    QString topi[3];
    QString zastava;
    int primarnax[3];
    int primarnay[3];
    int vrtenje[3];

    int st_tankov[6];
    void american();
    void nemec();
    void soviet();


};

#endif // IGRALEC_H
