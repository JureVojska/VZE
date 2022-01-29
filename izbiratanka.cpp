 #include "izbiratanka.h"
#include<QDebug>
#include"igra.h"
extern Igra *igra;

Izbiratanka::Izbiratanka(short st, short st_dr, bool nap_bra, QGraphicsItem *parent): QGraphicsRectItem(parent){
    setRect(0,0,100,60);
    st_tanka=st;
    st_drzave=st_dr;
    na_ba=nap_bra;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(242, 230, 217));
    setBrush(brush);
    setAcceptHoverEvents(true);

}

void Izbiratanka::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    igra->bitka->obvestilo->hide();
    if(na_ba==0){
        qDebug()<<igra->igralec[st_drzave]->primarnax[st_tanka];
        qDebug()<<igra->igralec[st_drzave]->primarnay[st_tanka];
        if(igra->igralec[st_drzave]->st_tankov[st_tanka]>0){
            igra->bitka->napadalec->nastaviTank(1500,702,igra->igralec[st_drzave]->primarnax[st_tanka],igra->igralec[st_drzave]->primarnay[st_tanka],igra->igralec[st_drzave]->tanki[st_tanka],st_tanka);
            igra->bitka->topnapadalca->nastaviTop(igra->bitka->napadalec->x(),igra->bitka->napadalec->y(),igra->igralec[st_drzave]->primarnax[st_tanka],igra->igralec[st_drzave]->primarnay[st_tanka],igra->igralec[st_drzave]->topi[st_tanka],igra->igralec[st_drzave]->vrtenje[st_tanka]);
            igra->igralec[st_drzave]->st_tankov[st_tanka]--;
            igra->bitka->izbrisinapadalne();
        }
        else igra->bitka->obvestila(8);
    }
    if(na_ba==1){
        if(igra->igralec[st_drzave]->st_tankov[st_tanka]>0){
            qDebug()<<na_ba;
            qDebug()<<st_tanka;
            igra->bitka->branilec->nastaviTank(4500,702,igra->igralec[st_drzave]->primarnax[st_tanka],igra->igralec[st_drzave]->primarnay[st_tanka],igra->igralec[st_drzave]->tanki[st_tanka],st_tanka);
            igra->bitka->topbranilca->nastaviTop(igra->bitka->branilec->x(),igra->bitka->branilec->y(),igra->igralec[st_drzave]->primarnax[st_tanka],igra->igralec[st_drzave]->primarnay[st_tanka],igra->igralec[st_drzave]->topi[st_tanka],igra->igralec[st_drzave]->vrtenje[st_tanka]);
            igra->bitka->izbrisibranilne();
            igra->igralec[st_drzave]->st_tankov[st_tanka]--;
        }else igra->bitka->obvestila(8);
    }
}
void Izbiratanka::hoverEnterEvent(QGraphicsSceneHoverEvent *){
    this->brush.setStyle(Qt::SolidPattern);
    this->brush.setColor(QColor(232, 202, 179));
    this->setBrush(brush);
}
void Izbiratanka::hoverLeaveEvent(QGraphicsSceneHoverEvent *){
    this->brush.setStyle(Qt::SolidPattern);
    this->brush.setColor(QColor(242, 230, 217));
    this->setBrush(brush);
}

