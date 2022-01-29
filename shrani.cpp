#include "shrani.h"
#include <fstream>
#include"igra.h"
#include <QDebug>
extern Igra *igra;
using namespace std;

Shrani::Shrani(bool sn, QGraphicsItem *parent): QGraphicsRectItem(parent){
    setRect(0,0,50,40);
    shrani_nalozi=sn;
    setAcceptHoverEvents(true);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    if(shrani_nalozi==0){
        brush.setColor(Qt::yellow);
        setBrush(brush);
        napis= new QGraphicsTextItem("SHRANI",this);
        napis->setPos(-3,9);
    }
    else{
        brush.setColor(Qt::green);
        setBrush(brush);
        napis= new QGraphicsTextItem("NALOZI",this);
        napis->setPos(-2,9);
    }

    napis->setFont(QFont("times",9, QFont::Bold));

}

void Shrani::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    if(shrani_nalozi==0)shraniigro();
    else naloziigro();

}

void Shrani::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    if(shrani_nalozi==0){
        this->setBrush(Qt::darkYellow);
    }
    else this->setBrush(Qt::darkGreen);
}

void Shrani::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    if(shrani_nalozi==0){
        this->setBrush(Qt::yellow);
    }
    else this->setBrush(Qt::green);
}

void Shrani::shraniigro()
{
    //int pom=0;
    fstream dat;
    dat.open("save.txt",ios::out);
    if(dat.is_open()){
        igra->zemljevid->warning->prikazsporocila(9);
        dat<<igra->zemljevid->get_igralec_na_potezi();
        dat<<endl;
        for(int i=0;i<82;i++){
            dat<<i;
            dat<<" ";
            dat<<igra->zemljevid->o[i]->drzava;
            dat<<" ";
            dat<<igra->zemljevid->o[i]->mes_tov;
            dat<<endl;
        }
        for(int i=0;i<3;i++){
            dat<<i;
            dat<<" ";
            dat<<igra->igralec[i]->denar;
            dat<<" ";
            for(int j=0;j<6;j++){
                dat<<igra->igralec[i]->st_tankov[j];
                dat<<" ";
            }

            dat<<endl;
        }
    }
    else igra->zemljevid->warning->prikazsporocila(10);
    dat.close();
}

void Shrani::naloziigro()
{
    int id_obmocja;
    short drzava;
    short infra;
    int money;
    int id_igralca;
    int tab[6];
    short na_potezi;
    fstream dat;
    dat.open("save.txt",ios::in);
    if(dat.is_open()){

        dat>>na_potezi;
        while(!dat.eof()){
            dat>>id_obmocja;
            dat>>drzava;
            dat>>infra;
            //qDebug()<<"obmocje: "<<id_obmocja<<"||| drzava: "<<drzava<<"||| infrastruktura: "<<infra;
            igra->zemljevid->o[id_obmocja]->drzava=drzava;
            igra->zemljevid->o[id_obmocja]->mes_tov=infra;
            if(id_obmocja==81)break;
        }
        while(!dat.eof()){
            dat>>id_igralca;
            dat>>money;
            for(int i=0;i<6;i++){
                dat>>tab[i];
                igra->igralec[id_igralca]->st_tankov[i]=tab[i];
                //qDebug()<<"igralec: "<<id_igralca<<"denar: "<<money <<"stevilo "<<i<<". tankov: "<<tab[i];
            }

            igra->igralec[id_igralca]->denar=money+50;
        }
        igra->zemljevid->set_igralec_na_potezi(na_potezi);
        sezidaj();
        igra->zemljevid->posodobi_informacije();
    }
    else igra->zemljevid->warning->prikazsporocila(11);
    dat.close();
    igra->zemljevid->preklic();

}

void Shrani::sezidaj()
{//tovarna 1, mesto 2, glavno mesto 4
    for(int i=0;i<82;i++){
        if(igra->zemljevid->o[i]->mes_tov==1) {
                if(igra->zemljevid->o[i]->geo==4)
                    igra->zemljevid->o[i]->infrastruktura->setPixmap(QPixmap(":slike/slike_zemljevid/tovarna2.png"));
                else
                    igra->zemljevid->o[i]->infrastruktura->setPixmap(QPixmap(":slike/slike_zemljevid/tovarna.png"));

            }
        if(igra->zemljevid->o[i]->mes_tov==2)
            igra->zemljevid->o[i]->infrastruktura->setPixmap(QPixmap(":slike/slike_zemljevid/mesto.png"));
    }

}
