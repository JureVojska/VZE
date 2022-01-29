#ifndef IGRA_H
#define IGRA_H

#include <QGraphicsView>
#include "zemljevid.h"
#include "bitka.h"

class Igra: public QGraphicsView{

public:
    Igra();
    void ustvari_igralce();

    Zemljevid *zemljevid;
    Bitka *bitka;

    void nabitko(int id_branilca, short drzava_branilca, int drzava_napadalca);
    void nazemljevid(int obm, short zmagovalec);
    void pobarvajmapo(short pomo);
    int sestejtocke(short a);

    void koncaj(short a, short b, short porazenec);
    void izbrisivseizigre();

    Igralec *igralec[3];

private:
    int sirina;
    int visina;

};

#endif // IGRA_H
