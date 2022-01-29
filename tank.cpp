#include<QKeyEvent>
#include<QDebug>
#include "tank.h"
#include "metek.h"
#include "katyusha.h"
#include"igra.h"

extern Igra *igra;

bool Tank::dovoli_premik=true;
short Tank::nacin=0;
bool Tank::izpisano=0;

Tank::Tank(bool stev)
{
    st_igralca=stev;

}

Tank::~Tank()
{
    qDebug()<<"tank izbrisan";
}

void Tank::nastaviTank(int x,int y,int zx,int zy,QString slika,short vrsta)  //zx in zy je tocka primarnega iztrela
{
    zivljenske_tocke=100*vrsta+100;
    skoda_napada=15*vrsta+60;
    bencin=vrsta*100+100;
    moc=100;
    kot_radiani=0;

    if(st_igralca==0)zamik_x=zx;
    else zamik_x=-zx;
    zamik_y=-zy;

    QPixmap *pom=new QPixmap(slika);
    tposx=x;
    tposy=y-pom->height();
    setPixmap(*pom);
    if(st_igralca==1)this->setTransform(QTransform::fromScale(-1,1));
    delete pom;
    setPos(tposx,tposy);

}

void Tank::keyPressEvent(QKeyEvent *event)
{
    if(dovoli_premik==true){
        igra->bitka->obvestilo->hide();
        switch (event->key()) {
            case Qt::Key_A:{
                if(Tank::izpisano==1){
                    igra->bitka->skrijIzpise();
                    Tank::izpisano=0;
                }
                if(Tank::nacin==0){
                    if(bencin>0){
                        tposx-=3;
                        setPos(tposx,tposy);
                        igra->centerOn(this);

                        if(st_igralca==0){
                            igra->bitka->topnapadalca->postavi(tposx,tposy);
                        }
                        else{
                            igra->bitka->topbranilca->postavi(tposx,tposy);
                        }
                        bencin--;
                    }else igra->bitka->obvestila(1);
                }else igra->bitka->obvestila(9);
            } break;

            case Qt::Key_D:{
                if(Tank::izpisano==1){
                    igra->bitka->skrijIzpise();
                    Tank::izpisano=0;
                }
                if(Tank::nacin==0){
                    if(bencin>0){
                        tposx+=3;
                        setPos(tposx,tposy);
                        igra->centerOn(this);

                        if(st_igralca==0){
                            igra->bitka->topnapadalca->postavi(tposx,tposy);
                        }
                        else{
                            igra->bitka->topbranilca->postavi(tposx,tposy);
                        }
                        bencin--;
                    }else igra->bitka->obvestila(1);
                }else igra->bitka->obvestila(9);
            } break;

            case Qt::Key_Right:{
            qDebug()<<moc;
            igra->bitka->podatek_moc->show();
                if(Tank::izpisano==1){
                    igra->bitka->skrijIzpise();
                    Tank::izpisano=0;
                }
                if(moc<250){
                    moc=moc+1;
                    if(Tank::nacin==1)raketomet->sprememba_moci(moc);
                }else igra->bitka->obvestila(4);
            } break;

            case Qt::Key_Left:{
                igra->bitka->podatek_moc->show();
                if(Tank::izpisano==1){
                    igra->bitka->skrijIzpise();
                    Tank::izpisano=0;
                }
                if(moc>10){
                    moc=moc-1;
                    if(Tank::nacin==1)raketomet->sprememba_moci(moc);
                }

                qDebug()<<moc;
            } break;

            case Qt::Key_Up:{
                if(Tank::izpisano==1){
                    igra->bitka->skrijIzpise();
                    Tank::izpisano=0;
                }
                if(kot_radiani<1.36){
                    kot_radiani+=0.01;
                    if(st_igralca==0)igra->bitka->topnapadalca->setRotation(-get_kot_stopinje());
                    else igra->bitka->topbranilca->setRotation(-get_kot_stopinje());
                     qDebug()<<kot_radiani;
                }
                else igra->bitka->obvestila(5);
           } break;

            case Qt::Key_Down:{
                if(Tank::izpisano==1){
                    igra->bitka->skrijIzpise();
                    Tank::izpisano=0;
                }
                if(kot_radiani>0.02){
                    kot_radiani-=0.01;
                    if(st_igralca==0)igra->bitka->topnapadalca->setRotation(-get_kot_stopinje());
                    else igra->bitka->topbranilca->setRotation(-get_kot_stopinje());
                    qDebug()<<kot_radiani;
                }

           } break;

             case Qt::Key_1:{

                if(Tank::izpisano==1){
                    igra->bitka->skrijIzpise();
                    Tank::izpisano=0;
                }
                short pom;
                if(st_igralca==0)pom=igra->bitka->drzava_nap;
                else pom=igra->bitka->drzava_bra;

                if(igra->igralec[pom]->st_tankov[3]!=0){
                    if(Tank::nacin==0){
                        Tank::dovoli_premik=false;
                        raketomet=new Katyusha(tposx,st_igralca,moc);
                        igra->bitka->addItem(raketomet);
                        igra->igralec[pom]->st_tankov[3]--;
                    }
                }else igra->bitka->obvestila(6);

            } break;
            case Qt::Key_2:{



                    short pom;
                    if(st_igralca==0)pom=igra->bitka->drzava_nap;
                    else pom=igra->bitka->drzava_bra;
                    if(igra->igralec[pom]->st_tankov[4]!=0){
                        if(Tank::nacin==0){

                            igra->bitka->podatek_moc->hide();
                            if(Tank::izpisano==1){
                                igra->bitka->skrijIzpise();
                                Tank::izpisano=0;
                            }

                            bomber=new Letalo(tposx,tposy,st_igralca);
                            igra->bitka->addItem(bomber);
                            Tank::nacin=2;
                            igra->igralec[pom]->st_tankov[4]--;
                            qDebug()<<"stevilo tankov od 4="<<igra->igralec[pom]->st_tankov[4];
                        }
                    }else igra->bitka->obvestila(7);

            } break;

             case Qt::Key_0:{
                igra->bitka->podatek_moc->hide();
                if(Tank::izpisano==1){
                    igra->bitka->skrijIzpise();
                    Tank::izpisano=0;
                }

                if(Tank::nacin==1){
                    raketomet->pelji();
                    Tank::dovoli_premik=false;
                    Tank::nacin=0;
                }
            }break;

            case Qt::Key_I:{

                if(Tank::izpisano==0){
                    igra->bitka->posodobiizpise();
                    Tank::izpisano=1;

                }
                else {
                    igra->bitka->skrijIzpise();
                    Tank::izpisano=0;
                }

            }break;

            case Qt::Key_Space:{
                igra->bitka->podatek_moc->hide();
                if(Tank::izpisano==1){
                    igra->bitka->skrijIzpise();
                    Tank::izpisano=0;
                }

                 if(Tank::nacin==0)this->ustreli();
                 if(Tank::nacin==1)raketomet->rafal();
                 if(Tank::nacin==2)bomber->spusti();

                 Tank::dovoli_premik=false;
            } break;

            default:
                 igra->bitka->obvestila(2);
            break;

        }
        igra->bitka->izpisMoci(moc);



    }else igra->bitka->obvestila(3);


}

void Tank::ustreli()
{
    int pomx,pomy;
    if(st_igralca==0){
        pomy=igra->bitka->topnapadalca->get_dolzina()*sin(kot_radiani);
        pomx=igra->bitka->topnapadalca->get_dolzina()*cos(kot_radiani);
        pomy=-pomy;
        qDebug()<<"x="<<pomx;
        qDebug()<<"y="<<pomy;
    }
    else{
        pomy=igra->bitka->topbranilca->get_dolzina()*sin(kot_radiani);
        pomx=igra->bitka->topbranilca->get_dolzina()*cos(kot_radiani);
        pomx=-pomx;
        pomy=-pomy;
    }

    Metek *metek=new Metek(tposx,tposy,zamik_x+pomx,zamik_y+pomy,st_igralca,1,skoda_napada);
    metek->vnos(kot_radiani,moc);
    igra->bitka->addItem(metek);
}


