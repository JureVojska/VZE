#include "konec.h"
#include<QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include"igra.h"
#include<gumbzaizhod.h>
extern Igra *igra;

Konec::Konec(short a,int st_a, short b,int st_b,short c)
{
    int sirina=1180;
    int visina=sirina*0.6153;
    setRect(0,0,sirina,visina);
    setPos(0,0);
    setZValue(3);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(242, 230, 217));
    setBrush(brush);

    QGraphicsPixmapItem *zmagovalec=new QGraphicsPixmapItem(this);
    zmagovalec->setPixmap(QPixmap(igra->igralec[a]->zastava));
    zmagovalec->setPos(490,180);
    QGraphicsTextItem *zmagovalec_tocke= new QGraphicsTextItem(this);
    zmagovalec_tocke->setPlainText(QString ("KONČNE TOČKE:"+QString::number(st_a)));
    zmagovalec_tocke->setPos(430,280);
    zmagovalec_tocke->setDefaultTextColor(Qt::darkYellow);
    zmagovalec_tocke->setFont(QFont("times",20));


    QGraphicsPixmapItem *drugi=new QGraphicsPixmapItem(this);
    drugi->setPixmap(QPixmap(igra->igralec[b]->zastava));
    drugi->setPos(190,380);
    QGraphicsTextItem *drugi_tocke= new QGraphicsTextItem(this);
    drugi_tocke->setPlainText(QString ("KONČNE TOČKE:"+QString::number(st_b)));
    drugi_tocke->setPos(150,480);
    drugi_tocke->setDefaultTextColor(Qt::gray);
    drugi_tocke->setFont(QFont("times",20));


    QGraphicsPixmapItem *porazenec=new QGraphicsPixmapItem(this);
    porazenec->setPixmap(QPixmap(igra->igralec[c]->zastava));
    porazenec->setPos(790,380);
    QGraphicsTextItem *porazenec_tocke= new QGraphicsTextItem(this);
    porazenec_tocke->setPlainText(QString ("KONČNE TOČKE:0"));
    porazenec_tocke->setPos(770,480);
    porazenec_tocke->setDefaultTextColor(Qt::darkRed);
    porazenec_tocke->setFont(QFont("times",20));

    QGraphicsTextItem *winner= new QGraphicsTextItem(this);
    winner->setPlainText(QString ("ZMAGOVALEC!!!"));
    winner->setPos(360,40);
    winner->setDefaultTextColor(Qt::darkYellow);
    winner->setFont(QFont("arial",45));

    Gumbzaizhod *n=new Gumbzaizhod(this);
    n->setPos(560,600);
}
