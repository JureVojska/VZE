#include "kupiprodaj.h"
#include <QDebug>

#include"igra.h"
extern Igra *igra;

Kupiprodaj::Kupiprodaj(int st_izdelka, bool kupi, int c, QGraphicsItem *parent): QGraphicsRectItem(parent){
    setRect(0,0,30,20);

    izdelek=st_izdelka;
    kalip=kupi;  //kupi 1 prodaj 0
    cena=c;

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    if(kupi==1)
        brush.setColor(Qt::darkGreen);
    if(kupi==0)
        brush.setColor(Qt::red);
    setBrush(brush);
}

void Kupiprodaj::mousePressEvent(QGraphicsSceneMouseEvent *)
{

    if(kalip==1){
        if(igra->igralec[igra->zemljevid->get_igralec_na_potezi()]->denar>=cena){
            igra->igralec[igra->zemljevid->get_igralec_na_potezi()]->st_tankov[izdelek]++;
            igra->igralec[igra->zemljevid->get_igralec_na_potezi()]->denar-=cena;
        }else {
            igra->zemljevid->posodobi_informacije();
            igra->zemljevid->warning->prikazsporocila(4);
        }


    }
    else if(kalip==0){
        if(igra->igralec[igra->zemljevid->get_igralec_na_potezi()]->st_tankov[izdelek]>0){
            igra->igralec[igra->zemljevid->get_igralec_na_potezi()]->st_tankov[izdelek]--;
            igra->igralec[igra->zemljevid->get_igralec_na_potezi()]->denar+=cena/5*4;
        }else {
            igra->zemljevid->posodobi_informacije();
            igra->zemljevid->warning->prikazsporocila(5);
        }

    }
    igra->zemljevid->trgovina->posodobi();
    igra->zemljevid->posodobi_informacije();
}

