#include "katyusha.h"
#include"tank.h"
#include"metek.h"
#include<cmath>
#include <QDebug>
#include<QTimer>
#include<QGraphicsPixmapItem>

#include"igra.h"
extern Igra *igra;

Katyusha::Katyusha(int ax,bool st_igral,int a)
{
    //this->setRect(0,0,70,70);

    moc=a;
    st_igralca=st_igral;
    st_iztrelkov=15;

    if(st_igral==0){
        QPixmap *pomo=new QPixmap(igra->igralec[igra->bitka->drzava_nap]->tanki[3]);
        koncnaposy=702-pomo->height();
        setPixmap(*pomo);
        delete pomo;
        koncnaposx=ax-300;
        zacetnaposx=koncnaposx-400;
        setPos(zacetnaposx,koncnaposy);}
    else {

        this->setTransform(QTransform::fromScale(-1,1));
        QPixmap *pomo=new QPixmap(igra->igralec[igra->bitka->drzava_bra]->tanki[3]);
        koncnaposy=702-pomo->height();
        setPixmap(*pomo);
        delete pomo;
        koncnaposx=ax+300;
        zacetnaposx=koncnaposx+340;
        setPos(zacetnaposx,koncnaposy);
    }



    voznja1=new QTimer;
    voznja2=new QTimer;
    iztrel=new QTimer;
    sled =new QTimer;
    connect(voznja1,SIGNAL(timeout()),this,SLOT(pripelji()));
    connect(voznja2,SIGNAL(timeout()),this,SLOT(odpelji()));
    connect(iztrel,SIGNAL(timeout()),this,SLOT(ustreli()));
    connect(sled,SIGNAL(timeout()),this,SLOT(fokusiraj()));
    voznja1->start(20);

}

void Katyusha::pelji()
{
    if(st_igralca==0)this->setTransform(QTransform::fromScale(-1,1));
    else this->setTransform(QTransform::fromScale(1,1));
    voznja2->start(20);
}

void Katyusha::rafal()
{
    iztrel->start(200);
}

void Katyusha::sledi()
{
    sled->start(5);
    pom=new QGraphicsRectItem;
    igra->bitka->addItem(pom);
    pom->setRect(0,0,5,5);
    pom->setPos(koncnaposx,koncnaposy);
    pom->hide();

    dolzina=pow(moc,2)*0.1-moc;
    if(st_igralca==0)dolzina=dolzina+koncnaposx;
    else dolzina=koncnaposx-dolzina;

    qDebug()<<"tralalaal";
}

void Katyusha::sprememba_moci(int a)
{
    moc=a;
}


//=============public slots=============================
void Katyusha::pripelji()
{
    if(st_igralca==0)setPos(x()+5,y());
    else setPos(x()-5,y());
    if((x()>=koncnaposx&&st_igralca==0)||(x()<=koncnaposx&&st_igralca==1)){
        voznja1->stop();
        Tank::nacin=1;
        Tank::dovoli_premik=true;
        delete voznja1;
    }

}

void Katyusha::odpelji()
{

    igra->centerOn(this);
    if(st_igralca==0)setPos(x()-5,y());
    else setPos(x()+5,y());
    if((x()<=zacetnaposx&&st_igralca==0)||(x()>=zacetnaposx&&st_igralca==1)){
        voznja2->stop();
        qDebug()<<"izbris katyushe :)";
        Tank::dovoli_premik=true;
        Tank::nacin=0;
        igra->bitka->spremembaIgralca(st_igralca);
        delete voznja2;
        delete this;
    }
}


void Katyusha::ustreli()
{
    int nakljucno=rand()%24-12;

    st_iztrelkov--;


    if(st_iztrelkov>1){
        Metek *metek=new Metek(x(),y(),0,30,st_igralca,0,25);
        metek->vnos(0.57,moc+nakljucno);
        igra->bitka->addItem(metek);
    }
    else{
        Metek *metek=new Metek(x(),y(),0,20,st_igralca,1,25);
        metek->vnos(0.57,moc+10);
        igra->bitka->addItem(metek);
        sledi();
        iztrel->stop();
        delete iztrel;
    }
}




void Katyusha::fokusiraj()
{
    if(st_igralca==0)pom->setPos(pom->x()+3,pom->y());
    else pom->setPos(pom->x()-3,pom->y());
    igra->centerOn(pom);
    if((pom->x()>dolzina&&st_igralca==0)||(pom->x()<dolzina-30&&st_igralca==1)||(x()>5000||x()<0)){
        sled->stop();
        delete sled;
        delete pom;
    }
}
