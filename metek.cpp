#include<QTimer>
#include<QDebug>
#include<typeinfo.h>

#include "metek.h"
#include"bitka.h"
#include"tank.h"

#include"igra.h"
extern Igra *igra;

Metek::Metek(int x, int y, int z_x, int z_y, bool dir,bool zadnM,int damage)
{
    mposx=x;
    mposy=y;
    zamik_x=z_x;
    zamik_y=z_y;
    mposx=x+zamik_x;
    mposy=y+zamik_y+20;
    skoda=damage;

    smer=dir;
    zadnjiMetek=zadnM;
    if(Tank::nacin==2)setPixmap(QPixmap(":slike/slike_bitka/metek2.png"));
    else setPixmap(QPixmap(":slike/slike_bitka/metek.png"));
    setPos(mposx,mposy);
    if(smer==1)this->setTransform(QTransform::fromScale(-1,1));
    casovnik=new QTimer();
    connect(casovnik,SIGNAL(timeout()),this,SLOT(premakni_metek()));
    if(Tank::nacin==2)casovnik->start(8);
    else casovnik->start(10);
    //qDebug()<<"y"<<mposy;
    this->setTransformOriginPoint(15,3);

    stevec=0;
    qDebug()<<"skoda="<<skoda;
}

void Metek::vnos(float v_kot,int v_moc)
{
    int kot_stopinje;
    kot_radiani=v_kot;
    if(smer==1)kot_radiani=-kot_radiani;
    moc=v_moc;
    g=10;
    m_x=0;
    hitrost=moc*cos(kot_radiani);
    //qDebug()<<hitrost<<"= hitrost";
    kot_stopinje=180*kot_radiani/3.1415926;
    //if(Tank::nacin==1)kot_stopinje=90;
    if(smer==0)this->setRotation(-kot_stopinje);
    else this->setRotation(kot_stopinje);


}

void Metek::ustavi_metek(bool a)
{
    casovnik->stop();
    delete casovnik;
    if(Tank::nacin==1&&zadnjiMetek==1){
        if(smer==0)igra->bitka->napadalec->raketomet->pelji();
        if(smer==1)igra->bitka->branilec->raketomet->pelji();
        //qDebug()<<"metek izbrisan peljem";
    }

    if(a==1)setPixmap(QPixmap(":slike/slike_bitka/eksplozija.png"));
    else {
        this->setRotation(0);
        setPos(x(),670);
        setPixmap(QPixmap(":slike/slike_bitka/zgresen.png"));
    }
    casovnik=new QTimer();
    connect(casovnik,SIGNAL(timeout()),this,SLOT(animacija()));
    casovnik->start(200);
}

float Metek::f(int x){
    return ((float)(x*tan(kot_radiani)-(g/(2*pow(moc,2)*pow(cos(kot_radiani),2)))*pow(x,2)));
}

void Metek::rotiraj(int x)
{

    float kt;
    kt=tan(kot_radiani)-(20*x/(2*pow(moc,2)*pow(cos(kot_radiani),2)));
    kt=tan(kt);
    kt=180*kt/3.1415926;
    if(smer==0)
        this->setRotation(-kt);
    else
        this->setRotation(kt);

    //qDebug()<<kt;
}

void Metek::premakni_metek()
{
    if(Tank::nacin==0){
        if(smer==0)m_x+=hitrost/10;
        else m_x-=hitrost/10;}
    else{
        if(smer==0)m_x+=3;
        else m_x-=3;
    }

    QList<QGraphicsItem *> list = collidingItems();                                        //preverja ali je metek zadel kaksen tank

    foreach(QGraphicsItem * i , list)
    {
        Tank * item= dynamic_cast<Tank *>(i);
        if (item)
        {
            item->zivljenske_tocke=item->zivljenske_tocke-skoda;
            ustavi_metek(1);

            return;
        }
    }
    stevec++;
    graf_y=-f(m_x)+mposy;
    graf_x=m_x+mposx;
    setPos(graf_x,graf_y);
    if(graf_y>710){
        ustavi_metek(0);
        return;
    }
    if(Tank::nacin==0)igra->centerOn(this);
    if(stevec%5==0)this->rotiraj(m_x);
}

void Metek::animacija()
{
        if(Tank::nacin==0){
            Tank::dovoli_premik=true;
            igra->bitka->spremembaIgralca(smer);
        }


        casovnik->stop();
        delete casovnik;
        igra->bitka->removeItem(this);
        delete this;
        qDebug()<<"metek izbrisan";
}
