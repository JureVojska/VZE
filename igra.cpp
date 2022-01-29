#include "igra.h"
#include "igra.h"
#include <QGraphicsRectItem>
#include <QDebug>
#include "konec.h"



extern Igra *igra;

Igra::Igra()
{
    sirina=1180;
    visina=sirina*0.6153;
    setFixedSize(sirina,visina);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ustvari_igralce();

    bitka=new Bitka();
    zemljevid=new Zemljevid();
    setScene(zemljevid);
    QBrush ta;
    ta.setStyle(Qt::SolidPattern);
    ta.setColor(QColor(116, 148, 173));
    setBackgroundBrush(ta);
}

void Igra::ustvari_igralce()
{
    for(int i=0;i<3;i++){
        igralec[i]=new Igralec();
    }
    igralec[0]->american();
    igralec[1]->nemec();
    igralec[2]->soviet();
}

void Igra::nazemljevid(int obm,short zmagovalec)
{
    igra->bitka->napadalec->clearFocus();
    igra->bitka->branilec->clearFocus();
    qDebug()<<"zmag"<<zmagovalec;
    qDebug()<<"obmocje je"<<obm;
    igra->zemljevid->o[obm]->drzava=zmagovalec;
    if(zemljevid->o[7]->drzava!=0)koncaj(1,2,0);
    if(zemljevid->o[34]->drzava!=1)koncaj(0,2,1);
    if(zemljevid->o[57]->drzava!=2)koncaj(0,1,2);
    igra->zemljevid->nasledn();
    setScene(zemljevid);

}

void Igra::pobarvajmapo(short pomo)
{
    QBrush ta;
    ta.setStyle(Qt::SolidPattern);
    switch(pomo){
        case 0:ta.setColor(QColor(116, 148, 173));break;
        case 1:ta.setColor(QColor(179, 179, 179));break;
        case 2:ta.setColor(QColor(187, 115, 102));break;
    }

    setBackgroundBrush(ta);
}

int Igra::sestejtocke(short a)
{
    return (igra->zemljevid->get_st_obmocij(a)*300+igra->igralec[a]->denar);
}



void Igra::nabitko(int id_branilca, short drzava_branilca, int drzava_napadalca)
{
    //bitka=new Bitka();
    bitka->novabitka(id_branilca,drzava_branilca,drzava_napadalca);
    setScene(bitka);
    if(igra->zemljevid->o[id_branilca]->geo!=4)centerOn(QPointF(3000,650));
    else centerOn(QPointF(1550,650));
}


void Igra::koncaj(short a,short b,short porazenec)
{
    short zmagovalec,drugi;
    if(sestejtocke(a)>sestejtocke(b)){
        zmagovalec=a;
        drugi=b;
    }
    else {
        zmagovalec=b;
        drugi=a;
    }
    Konec *ko=new Konec(zmagovalec,sestejtocke(zmagovalec),drugi,sestejtocke(drugi),porazenec);
    igra->zemljevid->addItem(ko);

}

void Igra::izbrisivseizigre()
{
    delete igralec[0];
    delete igralec[1];
    delete igralec[2];
    delete bitka;
}

