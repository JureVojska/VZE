#include "bitka.h"
#include "tank.h"
#include "izbiratanka.h"
#include <QGraphicsRectItem>
#include<QDebug>
#include<QImage>
#include"igra.h"
#include"gumbzaizhod.h"

extern Igra *igra;
Bitka::Bitka()
{

    sirina=6000;
    visina=800;
    setSceneRect(0,0,sirina,visina);

    napadalec=new Tank(0);
    branilec=new Tank(1);
    topnapadalca=new Top(0);
    topbranilca=new Top(1);
    napadalec->setFlag(QGraphicsItem::ItemIsFocusable);
    branilec->setFlag(QGraphicsItem::ItemIsFocusable);


    addItem(napadalec);
    addItem(branilec);
    addItem(topnapadalca);
    addItem(topbranilca);
    //novabitka(0,0,0);
    ustvari_izpise();
}

void Bitka::novabitka(int id_branilca, short drzava_branilca, short drzava_napadalca) //vedno daj še center on
{

    st_obmocja=id_branilca;
    drzava_bra=drzava_branilca;
    drzava_nap=drzava_napadalca;

    if(igra->zemljevid->o[st_obmocja]->geo==1){
        izberitanke();
        igra->setBackgroundBrush(QBrush(QImage(":slike/slike_bitka/odzadje1.png")));
    }
    if(igra->zemljevid->o[st_obmocja]->geo==2){
        izberitanke();
        igra->setBackgroundBrush(QBrush(QImage(":slike/slike_bitka/odzadje2.png")));
    }
    if(igra->zemljevid->o[st_obmocja]->geo==3){
        izberitanke();
        igra->setBackgroundBrush(QBrush(QImage(":slike/slike_bitka/odzadje3.png")));
    }

    if(igra->zemljevid->o[st_obmocja]->geo==4) {
        igra->setBackgroundBrush(QBrush(QImage(":slike/slike_bitka/odzadje4.png")));
        napadalec->nastaviTank(1500,650,127,27,":slike/slike_bitka/ladja.png",2);
        topnapadalca->nastaviTop(napadalec->x(),napadalec->y(),127,27,":slike/slike_bitka/ladja_top",0);

        branilec->nastaviTank(4500,650,127,27,":slike/slike_bitka/ladja.png",2);
        topbranilca->nastaviTop(branilec->x(),branilec->y(),127,27,":slike/slike_bitka/ladja_top",0);
        igra->igralec[drzava_napadalca]->st_tankov[5]--;
        igra->igralec[drzava_branilca]->st_tankov[5]--;
        napadalec->setFocus();
    }
    podatek_moc->hide();
}

void Bitka::izberitanke()
{
    izbira_lahki=new Izbiratanka(0,drzava_nap,0);
    addItem(izbira_lahki);
    izbira_lahki->setPos(2700,250);

    izbira_lahki_nap_slika =new QGraphicsPixmapItem(izbira_lahki);
    izbira_lahki_nap_slika->setPixmap(igra->igralec[drzava_nap]->za_v_shop[0]);
    izbira_lahki_nap_slika->setPos(0,10);


    izbira_srednji=new Izbiratanka(1,drzava_nap,0);
    addItem(izbira_srednji);
    izbira_srednji->setPos(2700,400);

    izbira_srednji_nap_slika =new QGraphicsPixmapItem(izbira_srednji);
    izbira_srednji_nap_slika->setPixmap(igra->igralec[drzava_nap]->za_v_shop[1]);
    izbira_srednji_nap_slika->setPos(0,10);

    izbira_tezki=new Izbiratanka(2,drzava_nap,0);
    addItem(izbira_tezki);
    izbira_tezki->setPos(2700,550);

    izbira_tezki_nap_slika =new QGraphicsPixmapItem(izbira_tezki);
    izbira_tezki_nap_slika->setPixmap(igra->igralec[drzava_nap]->za_v_shop[2]);
    izbira_tezki_nap_slika->setPos(0,5);



}

void Bitka::izbrisibranilne()
{
    delete izbira_lahki_bra_slika;
    delete izbira_srednji_bra_slika;
    delete izbira_tezki_bra_slika;

    delete izbira_lahki_bra;
    delete izbira_srednji_bra;
    delete izbira_tezki_bra;
    igra->centerOn(QPointF(1575,650));
    napadalec->setFocus();
}

void Bitka::izbrisinapadalne()
{
    izbira_lahki_bra=new Izbiratanka(0,drzava_bra,1);
    addItem(izbira_lahki_bra);
    izbira_lahki_bra->setPos(3200,250);

    izbira_lahki_bra_slika =new QGraphicsPixmapItem(izbira_lahki_bra);
    izbira_lahki_bra_slika->setPixmap(igra->igralec[drzava_bra]->za_v_shop[0]);
    izbira_lahki_bra_slika->setPos(0,10);


    izbira_srednji_bra=new Izbiratanka(1,drzava_bra,1);
    addItem(izbira_srednji_bra);
    izbira_srednji_bra->setPos(3200,400);

    izbira_srednji_bra_slika =new QGraphicsPixmapItem(izbira_srednji_bra);
    izbira_srednji_bra_slika->setPixmap(igra->igralec[drzava_bra]->za_v_shop[1]);
    izbira_srednji_bra_slika->setPos(0,10);


    izbira_tezki_bra=new Izbiratanka(2,drzava_bra,1);
    addItem(izbira_tezki_bra);
    izbira_tezki_bra->setPos(3200,550);

    izbira_tezki_bra_slika =new QGraphicsPixmapItem(izbira_tezki_bra);
    izbira_tezki_bra_slika->setPixmap(igra->igralec[drzava_bra]->za_v_shop[2]);
    izbira_tezki_bra_slika->setPos(0,5);


    delete izbira_lahki_nap_slika;
    delete izbira_srednji_nap_slika;
    delete izbira_tezki_nap_slika;

    delete izbira_lahki;
    delete izbira_srednji;
    delete izbira_tezki;


}

void Bitka::spremembaIgralca(bool naVrst)
{
    if(naVrst==0){
        branilec->setFocus();
        igra->centerOn(branilec);
        izpisMoci(branilec->moc);
    }
    else{
        napadalec->setFocus();
        igra->centerOn(napadalec);
        izpisMoci(napadalec->moc);
    }
    //igra->bitka->novabitka(0,0,0);
    if(napadalec->zivljenske_tocke<=0)igra->nazemljevid(st_obmocja,drzava_bra);
    if(branilec->zivljenske_tocke<=0)igra->nazemljevid(st_obmocja,drzava_nap);
    podatek_moc->show();
}

void Bitka::ustvari_izpise()
{
    podatek_moc = new QGraphicsTextItem;
    addItem(podatek_moc);
    podatek_moc->setFont(QFont("times",20));

    obvestilo =new QGraphicsTextItem;
    obvestilo->setFont(QFont("times",20));
    obvestilo->setDefaultTextColor(Qt::red);

    podatek_o_hpju1=new QGraphicsTextItem;
    podatek_o_hpju2=new QGraphicsTextItem;
    podatek_o_bencinu2=new QGraphicsTextItem;
    podatek_o_bencinu1=new QGraphicsTextItem;
    podatek_o_katyushah1=new QGraphicsTextItem;
    podatek_o_katyushah2=new QGraphicsTextItem;
    podatek_o_letalih1=new QGraphicsTextItem;
    podatek_o_letalih2=new QGraphicsTextItem;

    addItem(podatek_o_hpju1);
    addItem(podatek_o_hpju2);
    addItem(podatek_o_bencinu1);
    addItem(podatek_o_bencinu2);
    addItem(podatek_o_katyushah1);
    addItem(podatek_o_katyushah2);
    addItem(podatek_o_letalih1);
    addItem(podatek_o_letalih2);
    addItem(obvestilo);

    podatek_o_hpju1->setDefaultTextColor(Qt::darkRed);
    podatek_o_hpju1->setFont(QFont("times",20));
    podatek_o_hpju2->setDefaultTextColor(Qt::darkRed);
    podatek_o_hpju2->setFont(QFont("times",20));
    podatek_o_bencinu1->setDefaultTextColor(Qt::darkRed);
    podatek_o_bencinu1->setFont(QFont("times",20));
    podatek_o_bencinu2->setDefaultTextColor(Qt::darkRed);
    podatek_o_bencinu2->setFont(QFont("times",20));
    podatek_o_katyushah1->setDefaultTextColor(Qt::darkRed);
    podatek_o_katyushah1->setFont(QFont("times",20));
    podatek_o_katyushah2->setDefaultTextColor(Qt::darkRed);
    podatek_o_katyushah2->setFont(QFont("times",20));
    podatek_o_letalih1->setDefaultTextColor(Qt::darkRed);
    podatek_o_letalih1->setFont(QFont("times",20));
    podatek_o_letalih2->setDefaultTextColor(Qt::darkRed);
    podatek_o_letalih2->setFont(QFont("times",20));
}

void Bitka::posodobiizpise()
{
    podatek_o_hpju1->setPlainText(QString ("življenske tocke: "+QString::number(napadalec->zivljenske_tocke)));
    podatek_o_bencinu1->setPlainText(QString ("bencin: "+QString::number(napadalec->bencin)));
    podatek_o_hpju2->setPlainText(QString ("življenske tocke: "+QString::number(branilec->zivljenske_tocke)));
    podatek_o_bencinu2->setPlainText(QString ("bencin: "+QString::number(branilec->bencin)));
    podatek_o_katyushah1->setPlainText(QString ("število katyush: "+QString::number(igra->igralec[drzava_nap]->st_tankov[3])));
    podatek_o_letalih1->setPlainText(QString ("število letal: "+QString::number(igra->igralec[drzava_nap]->st_tankov[4])));
    podatek_o_katyushah2->setPlainText(QString ("število katyush: "+QString::number(igra->igralec[drzava_bra]->st_tankov[3])));
    podatek_o_letalih2->setPlainText(QString ("število letal: "+QString::number(igra->igralec[drzava_bra]->st_tankov[4])));

    podatek_o_hpju1->setPos(igra->mapToScene(100,visina/3));
    podatek_o_bencinu1->setPos(igra->mapToScene(100,visina/3+40));
    podatek_o_hpju2->setPos(igra->mapToScene(830,visina/3));
    podatek_o_bencinu2->setPos(igra->mapToScene(830,visina/3+40));
    podatek_o_katyushah1->setPos(igra->mapToScene(100,visina/3+80));
    podatek_o_letalih1->setPos(igra->mapToScene(100,visina/3+120));
    podatek_o_katyushah2->setPos(igra->mapToScene(830,visina/3+80));
    podatek_o_letalih2->setPos(igra->mapToScene(830,visina/3+120));

    podatek_o_hpju1->show();
    podatek_o_hpju2->show();
    podatek_o_bencinu1->show();
    podatek_o_bencinu2->show();
    podatek_o_katyushah1->show();
    podatek_o_katyushah2->show();
    podatek_o_letalih1->show();
    podatek_o_letalih2->show();
}

void Bitka::skrijIzpise()
{
    podatek_o_hpju1->hide();
    podatek_o_hpju2->hide();
    podatek_o_bencinu1->hide();
    podatek_o_bencinu2->hide();
    podatek_o_katyushah1->hide();
    podatek_o_katyushah2->hide();
    podatek_o_letalih1->hide();
    podatek_o_letalih2->hide();
}

void Bitka::izpisMoci(int moc)
{
    podatek_moc->setPlainText(QString ("MOČ: "+QString::number(moc)));
    podatek_moc->setPos(igra->mapToScene(550,100));

}

void Bitka::obvestila(short o)
{
    switch (o) {
        case 1:{
            obvestilo->setPlainText(QString ("ZMANJKALO TI JE BENCINA!!"));
            obvestilo->setPos(igra->mapToScene(400,visina/3));
            qDebug()<<"bencin?";
            obvestilo->show();

        }
            break;
        case 2:{
            obvestilo->setPlainText(QString ("TA TIPKA NE OBSTAJA!!"));
            obvestilo->setPos(igra->mapToScene(400,visina/3));
            obvestilo->show();
        }
            break;
        case 3:{
            obvestilo->setPlainText(QString ("NE PRITISKAJ!!"));
            obvestilo->setPos(igra->mapToScene(400,visina/3));
            obvestilo->show();
        }
            break;

        case 4:{
            obvestilo->setPlainText(QString ("NAJVIšJA DOVOLJENA MOČ JE 250!!"));
            obvestilo->setPos(igra->mapToScene(400,visina/3));
            obvestilo->show();
        }
            break;

        case 5:{
            obvestilo->setPlainText(QString ("TOPA NE MOREM VEČ OBRNITI!!"));
            obvestilo->setPos(igra->mapToScene(400,visina/3));
            obvestilo->show();
        }
            break;

        case 6:{
            obvestilo->setPlainText(QString ("NIMAŠ RAKETOMETOV"));
            obvestilo->setPos(igra->mapToScene(450,visina/3));
            obvestilo->show();
        }
            break;

        case 7:{
            obvestilo->setPlainText(QString ("NIMAŠ LETAL"));
            obvestilo->setPos(igra->mapToScene(500,visina/3));
            obvestilo->show();
        }
            break;
        case 8:{
            obvestilo->setPlainText(QString ("TEGA TANKA NIMAŠ"));
            obvestilo->setPos(igra->mapToScene(440,visina/3));
            obvestilo->show();
        }
            break;
        case 9:{
            obvestilo->setPlainText(QString ("NE MOREŠ SE PREMAKNITI V TEM NAČINU"));
            obvestilo->setPos(igra->mapToScene(350,visina/3));
            obvestilo->show();
        }
            break;
    }
}

void Bitka::izbrisivseizbitke()
{
    delete podatek_moc;
    delete obvestilo;
    delete napadalec;
    delete topnapadalca;
    delete branilec;
    delete topbranilca;
    delete podatek_o_hpju1;
    delete podatek_o_hpju2;
    delete podatek_o_bencinu1;
    delete podatek_o_bencinu2;

    qDebug()<<"vse iz bitke zbrisano :)";
}

Bitka::~Bitka()
{
    qDebug()<<"bitka izbrisana :)";
}


