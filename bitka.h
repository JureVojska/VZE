#ifndef BITKA_H
#define BITKA_H

#include <QGraphicsScene>
#include"tank.h"
#include "izbiratanka.h"

class Bitka:public QGraphicsScene{
    Q_OBJECT
public:
    Bitka();
    void novabitka(int id_branilca, short drzava_branilca, short drzava_napadalca);
    void izberitanke();
    void izbrisibranilne();
    void izbrisinapadalne();
    Tank *napadalec;
    Top *topnapadalca;
    Tank *branilec;
    Top *topbranilca;
    void spremembaIgralca(bool naVrst);

    bool zmagovalec;
    void ustvari_izpise();
    void posodobiizpise();
    void skrijIzpise();
    void izpisMoci(int moc);
    void obvestila(short o);
    void izbrisivseizbitke();
    QGraphicsTextItem *podatek_moc;
    QGraphicsTextItem *obvestilo;

    short drzava_nap;
    short drzava_bra;

    ~Bitka(); //destruktor
private:

    int st_obmocja;
    QGraphicsTextItem *podatek_o_hpju1;
    QGraphicsTextItem *podatek_o_hpju2;
    QGraphicsTextItem *podatek_o_bencinu1;
    QGraphicsTextItem *podatek_o_bencinu2;
    QGraphicsTextItem *podatek_o_katyushah1;
    QGraphicsTextItem *podatek_o_katyushah2;
    QGraphicsTextItem *podatek_o_letalih1;
    QGraphicsTextItem *podatek_o_letalih2;
    Izbiratanka *izbira_lahki;
    Izbiratanka *izbira_srednji;
    Izbiratanka *izbira_tezki;
    Izbiratanka *izbira_lahki_bra;
    Izbiratanka *izbira_srednji_bra;
    Izbiratanka *izbira_tezki_bra;
    QGraphicsPixmapItem *izbira_lahki_nap_slika;
    QGraphicsPixmapItem *izbira_srednji_nap_slika;
    QGraphicsPixmapItem *izbira_tezki_nap_slika;
    QGraphicsPixmapItem *izbira_lahki_bra_slika;
    QGraphicsPixmapItem *izbira_srednji_bra_slika;
    QGraphicsPixmapItem *izbira_tezki_bra_slika;
    int visina,sirina;

};

#endif // BITKA_H
