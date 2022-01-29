#ifndef ZEMLJEVID_H
#define ZEMLJEVID_H
#include <QGraphicsScene>
#include "obmocje.h"
#include "igralec.h"
#include "trgovina.h"
#include "gumb.h"
#include "gumbzacrte.h"
#include "opozorilo.h"
#include "shrani.h"

class Zemljevid: public QGraphicsScene{
    Q_OBJECT
public:
    Zemljevid();
    void ustvari_igralce();
    void ustvari_trgovino();
    void ustvari_ostalo();
    void ustvari_informacije();
    void ustvari_obmocja();
    void povej_sosede();

    void napad(short drzava_branilca, int id_branilca);
    void oznaci_moznosti_grajenja();
    void posodobi_informacije();
    void izbrisivseizzemljevida();


    bool crtenarisane;
    int stanje;
    Obmocje *o[82];
    Trgovina *trgovina;
    Opozorilo *warning;

    int get_igralec_na_potezi();
    void set_igralec_na_potezi(short a);
    int get_st_tovarn();
    int get_st_mest();
    int get_st_obmocij(short drz);
    int get_st_tankov(short n);
    int get_st_ladij(short n);

public slots:
    void oznaci_ogrozene();
    void stanje_na_2();
    void stanje_na_1();
    void izrisi_trgovino();
    void nasledn();
    void preklic();
    void crte();
private:
    int sirina;
    int visina;
    int st_polj;
    short igralec_na_potezi;
    QGraphicsPixmapItem  *mapa;
    QGraphicsPixmapItem *flag;
    QGraphicsPixmapItem *tov;
    QGraphicsPixmapItem *mes;
    QGraphicsPixmapItem *den;
    QGraphicsPixmapItem *tanki;
    QGraphicsPixmapItem *ladje;
    QGraphicsTextItem *tov_tex;
    QGraphicsTextItem *mes_tex;
    QGraphicsTextItem *den_tex;
    QGraphicsTextItem *tanki_tex;
    QGraphicsTextItem *ladje_tex;
    QGraphicsTextItem *obm_tex;
    Gumb* napadi;
    Gumb* tovarna;
    Gumb* mesto;
    Gumb* naslednji;
    Gumb* preklici;
    Shrani *save;
    Shrani *nalozi;
    GumbzaCrte *pokazicrte;
};

#endif // ZEMLJEVID_H
