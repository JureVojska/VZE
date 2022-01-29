#include "zemljevid.h"
#include"gumb.h"
#include "gumbzacrte.h"
#include"trgovina.h"
#include "gumbtrgovina.h"
#include "gumbzaizhod.h"
#include "opozorilo.h"
#include<QTimer>
#include<cmath>

#include"igra.h"
extern Igra *igra;

Zemljevid::Zemljevid()
{
    sirina=1180;
    visina=sirina*0.6153;
    setSceneRect(0,0,sirina,visina);

    igralec_na_potezi=0;
    st_polj=82;
    stanje=0;
    crtenarisane=0;

    mapa= new QGraphicsPixmapItem();
    mapa->setPixmap(QPixmap(":slike/slike_zemljevid/evropamap2.png"));
    mapa->setPos(180,0);
    mapa->setFocus();
    this->addItem(mapa);

    ustvari_obmocja();
    ustvari_trgovino();
    ustvari_informacije();
    ustvari_ostalo();

}


void Zemljevid::ustvari_trgovino()
{
    trgovina=new Trgovina;
    this->addItem(trgovina);
    trgovina->setZValue(1);
    trgovina->hide();

}

void Zemljevid::ustvari_ostalo()
{
      napadi = new Gumb(QString("NAPADI"));
        napadi->setPos(sirina-90,visina-90);
        this->addItem(napadi);
        connect(napadi,SIGNAL(aktiviraj()),this,SLOT(oznaci_ogrozene()));

      tovarna = new Gumb(QString("TOVARNA"));
        tovarna->setPos(sirina-170,visina-90);
        this->addItem(tovarna);
        connect(tovarna,SIGNAL(aktiviraj()),this,SLOT(stanje_na_2()));

      mesto= new Gumb(QString("MESTO"));
        mesto->setPos(sirina-250,visina-90);
        this->addItem(mesto);
        connect(mesto,SIGNAL(aktiviraj()),this,SLOT(stanje_na_1()));

      naslednji = new Gumb(QString("NASLEDNJI"));
        naslednji->setPos(100,visina-90);
        this->addItem(naslednji);
        connect(naslednji,SIGNAL(aktiviraj()),this,SLOT(nasledn()));

      preklici= new Gumb(QString("PREKLIC"));
        preklici->setPos(20,visina-90);
        this->addItem(preklici);
        connect(preklici,SIGNAL(aktiviraj()),this,SLOT(preklic()));


      pokazicrte= new GumbzaCrte(QString("i"));
          pokazicrte->setPos(670,20);
          this->addItem(pokazicrte);
          connect(pokazicrte,SIGNAL(aktiviraj()),this,SLOT(crte()));

      save = new Shrani(0);
        save->setPos(1060,10);
        this->addItem(save);

      nalozi=new Shrani(1);
          nalozi->setPos(1000,10);
          this->addItem(nalozi);

      warning=new Opozorilo;
           this->addItem(warning);

      Gumbtrgovina* shop= new Gumbtrgovina();                           //gumb za trgovino bo svoj klas
        shop->setPos(40,550);
        this->addItem(shop);

      Gumbzaizhod* exit= new Gumbzaizhod();                           //gumb za trgovino bo svoj klas
        exit->setPos(1120,10);
        this->addItem(exit);


}

void Zemljevid::ustvari_informacije()
{

    flag=new QGraphicsPixmapItem;
    flag->setPixmap(QPixmap(":slike/slike_zemljevid/american_flag.png"));
    flag->setPos(10,10);
    this->addItem(flag);

    obm_tex=new QGraphicsTextItem;
    obm_tex->setPlainText(QString("21"));
    obm_tex->setPos(70,100);
    obm_tex->setFont(QFont("times",27));
    this->addItem(obm_tex);

    den=new QGraphicsPixmapItem;
    den->setPixmap(QPixmap(":slike/slike_zemljevid/denar.png"));
    den->setPos(20,240);
    this->addItem(den);

    den_tex=new QGraphicsTextItem;
    den_tex->setPlainText("3000");
    den_tex->setPos(70,230);
    den_tex->setFont(QFont("times",20));
    this->addItem(den_tex);

    tanki=new QGraphicsPixmapItem;
    tanki->setPixmap(QPixmap(":slike/slike_zemljevid/tank.png"));
    tanki->setPos(20,340);
    this->addItem(tanki);

    tanki_tex=new QGraphicsTextItem;
    tanki_tex->setPlainText(QString("9"));
    tanki_tex->setPos(70,330);
    tanki_tex->setFont(QFont("times",20));
    this->addItem(tanki_tex);

    ladje=new QGraphicsPixmapItem;
    ladje->setPixmap(QPixmap(":slike/slike_zemljevid/ladje.png"));
    ladje->setPos(20,290);
    this->addItem(ladje);

    ladje_tex=new QGraphicsTextItem;
    ladje_tex->setPlainText(QString("5"));
    ladje_tex->setPos(70,280);
    ladje_tex->setFont(QFont("times",20));
    this->addItem(ladje_tex);

    tov=new QGraphicsPixmapItem;
    tov->setPixmap(QPixmap(":slike/slike_zemljevid/tovarna.png"));
    tov->setPos(20,380);
    this->addItem(tov);

    tov_tex=new QGraphicsTextItem;
    tov_tex->setPlainText(QString::number(get_st_tovarn()));
    tov_tex->setPos(70,380);
    tov_tex->setFont(QFont("times",20));
    this->addItem(tov_tex);

    mes=new QGraphicsPixmapItem;
    mes->setPixmap(QPixmap(":slike/slike_zemljevid/mesto.png"));
    mes->setPos(20,430);
    this->addItem(mes);

    mes_tex=new QGraphicsTextItem;
    mes_tex->setPlainText(QString::number(get_st_mest()));
    mes_tex->setPos(70,430);
    mes_tex->setFont(QFont("times",20));
    this->addItem(mes_tex);
}

void Zemljevid::ustvari_obmocja()
{
        o[ 0 ] = new Obmocje(QString("München"), 617 , 444 ,1,0,1);
        o[ 1 ] = new Obmocje(QString("Rejkjavik"), 380 , 165 ,0, 1 ,1);
        o[ 2 ] = new Obmocje(QString("Atlantski ocean"), 223 , 254 ,0, 2 ,4);
        o[ 3 ] = new Obmocje(QString("Atlantski ocean"), 504 , 181 ,0, 3 ,4);
        o[ 4 ] = new Obmocje(QString("Atlantski ocean"), 375 , 301 ,0, 4 ,4);
        o[ 5 ] = new Obmocje(QString("Dublin"), 465 , 365 ,0, 5 ,2);
        o[ 6 ] = new Obmocje(QString("Liverpool"), 507 , 349 ,0, 6 ,2);
        o[ 7 ] = new Obmocje(QString("London"), 529 , 402 ,0, 7 ,2);
        o[ 8 ] = new Obmocje(QString("Normandija"), 527 , 436 ,0, 8 ,2);
        o[ 9 ] = new Obmocje(QString("Dunkirk"), 567 , 401 ,1, 9 ,2);
        o[ 10 ] = new Obmocje(QString("Agadir"), 440 , 451 ,0, 10 ,4);
        o[ 11 ] = new Obmocje(QString("Atlantski ocean"), 289 , 540 ,0, 11 ,4);
        o[ 12 ] = new Obmocje(QString("Atlantski ocean"), 213 , 404 ,0, 12 ,4);
        o[ 13 ] = new Obmocje(QString("Atlantski ocean"), 307 , 686 ,0, 13 ,4);
        o[ 14 ] = new Obmocje(QString("Casablanca"), 431 , 636 ,0, 14 ,3);
        o[ 15 ] = new Obmocje(QString("Gibraltar"), 463 , 601 ,0, 15 ,3);
        o[ 16 ] = new Obmocje(QString("Madrid"), 477 , 556 ,0, 16 ,2);
        o[ 17 ] = new Obmocje(QString("Marseille"), 571 , 505 ,1, 17 ,2);
        o[ 18 ] = new Obmocje(QString("Sardinija"), 606 , 564 ,1, 18 ,2);
        o[ 19 ] = new Obmocje(QString("Alžir"), 542 , 603 ,0, 19 ,3);
        o[ 20 ] = new Obmocje(QString("Sicilija"), 655 , 590 ,1, 20 ,2);
        o[ 21 ] = new Obmocje(QString("Tripoli"), 633 , 656 ,1, 21 ,3);
        o[ 22 ] = new Obmocje(QString("Sredozemsko morje"), 694 , 632 ,1, 22 ,4);
        o[ 23 ] = new Obmocje(QString("Hamburg"), 630 , 377 ,1, 23 ,2);
        o[ 24 ] = new Obmocje(QString("Köln"), 608 , 403 ,1, 24 ,2);
        o[ 25 ] = new Obmocje(QString("Varšava"), 741 , 405 ,1, 25 ,2);
        o[ 26 ] = new Obmocje(QString("Pariz"), 566 , 440 ,1, 26 ,2);
        o[ 27 ] = new Obmocje(QString("Milano"), 616 , 495 ,1, 27 ,2);
        o[ 28 ] = new Obmocje(QString("Rim"), 654 , 535 ,1, 28 ,2);
        o[ 29 ] = new Obmocje(QString("Trst"), 664 , 486 ,1, 29 ,2);
        o[ 30 ] = new Obmocje(QString("Sarajevo"), 701 , 524 ,1, 30 ,2);
        o[ 31 ] = new Obmocje(QString("Bukarešta"), 765 , 509 ,1, 31 ,2);
        o[ 32 ] = new Obmocje(QString("Budinpešta"), 726 , 471 ,1, 32 ,2);
        o[ 33 ] = new Obmocje(QString("Krakov"), 693 , 431 ,1, 33 ,2);
        o[ 34 ] = new Obmocje(QString("Berlin"), 658 , 396 ,1, 34 ,2);
        o[ 35 ] = new Obmocje(QString("Gdansk"), 717 , 369 ,1, 35 ,2);
        o[ 36 ] = new Obmocje(QString("Köbenhavn"), 649 , 340 ,1, 36 ,1);
        o[ 37 ] = new Obmocje(QString("Stockholm"), 694 , 278 ,2, 37 ,1);
        o[ 38 ] = new Obmocje(QString("Oslo"), 641 , 260 ,0, 38 ,1);
        o[ 39 ] = new Obmocje(QString("Trondheim"), 648 , 194 ,0, 39 ,1);
        o[ 40 ] = new Obmocje(QString("Norrbotten"), 704 , 178 ,2, 40 ,1);
        o[ 41 ] = new Obmocje(QString("Torino"), 786 , 148 ,2, 41 ,1);
        o[ 42 ] = new Obmocje(QString("Atene"), 732 , 587 ,1, 42 ,2);
        o[ 43 ] = new Obmocje(QString("Kreta"), 755 , 633 ,1, 43 ,3);
        o[ 44 ] = new Obmocje(QString("Carigrad"), 798 , 564 ,1, 44 ,3);
        o[ 45 ] = new Obmocje(QString("Ankara"), 832 , 593 ,1, 45 ,3);
        o[ 46 ] = new Obmocje(QString("Tobruk"), 735 , 667 ,1, 46 ,3);
        o[ 47 ] = new Obmocje(QString("El Alamein"), 789 , 686 ,1, 47 ,3);
        o[ 48 ] = new Obmocje(QString("Damask"), 873 , 662 ,1, 48 ,3);
        o[ 49 ] = new Obmocje(QString("Batumi"), 918 , 569 ,1, 49 ,3);
        o[ 50 ] = new Obmocje(QString("Baku"), 982 , 578 ,2, 50 ,3);
        o[ 51 ] = new Obmocje(QString("Atyrau"), 1052 , 547 ,2, 51 ,3);
        o[ 52 ] = new Obmocje(QString("Bordeaux"), 519 , 501 ,0, 52 ,2);
        o[ 53 ] = new Obmocje(QString("Stalingrad"), 926 , 484 ,2, 53,2);
        o[ 54 ] = new Obmocje(QString("Harkov"), 853 , 430 ,2, 54,2 );
        o[ 55 ] = new Obmocje(QString("Severno morje"), 551 , 304 ,0, 55 ,4);
        o[ 56 ] = new Obmocje(QString("Kursk"), 838 , 388 ,2, 56 ,2);
        o[ 57 ] = new Obmocje(QString("Moskva"), 879 , 352 ,2, 57 ,2);
        o[ 58 ] = new Obmocje(QString("Vologda"), 889 , 278 ,2, 58 ,1);
        o[ 59 ] = new Obmocje(QString("Minsk"), 784 , 388 ,2, 59 ,2);
        o[ 60 ] = new Obmocje(QString("Kijev"), 778 , 438 ,1, 60 ,2);
        o[ 61 ] = new Obmocje(QString("Ostrov"), 817 , 333 ,2, 61 ,2);
        o[ 62 ] = new Obmocje(QString("Leningrad"), 845 , 277 ,2, 62 ,1);
        o[ 63 ] = new Obmocje(QString("Helsinki"), 795 , 260 ,2, 63 ,1);
        o[ 64 ] = new Obmocje(QString("Komi"), 1018 , 164 ,2, 64 ,1);
        o[ 65 ] = new Obmocje(QString("Bereznik"), 946 , 256 ,2, 65 ,1);
        o[ 66 ] = new Obmocje(QString("Jaroslavl"), 946 , 319 ,2, 66 ,1);
        o[ 67 ] = new Obmocje(QString("Uljanovsk"), 1024 , 331 ,2, 67 ,1);
        o[ 68 ] = new Obmocje(QString("Novogorod"), 1023 , 270 ,2, 68 ,1);
        o[ 69 ] = new Obmocje(QString("Komi"), 1129 , 239 ,2, 69 ,1);
        o[ 70 ] = new Obmocje(QString("Samara"), 1064 , 370 ,2, 70 ,1);
        o[ 71 ] = new Obmocje(QString("Saratov"), 980 , 426 ,2, 71 ,2);
        o[ 72 ] = new Obmocje(QString("Tambov"), 924 , 399 ,2, 72 ,2);
        o[ 73 ] = new Obmocje(QString("Kišinjev"), 800 , 477 ,1, 73 ,2);
        o[ 74 ] = new Obmocje(QString("Turkistain"), 1123 , 470 ,2, 74 ,1);
        o[ 75 ] = new Obmocje(QString("Astana"), 1125 , 400 ,2, 75 ,1);
        o[ 76 ] = new Obmocje(QString("Krim"), 851 , 505 ,1, 76 ,2);
        o[ 77 ] = new Obmocje(QString("Kuopio"), 823 , 209 ,2, 77 ,1);
        o[ 78 ] = new Obmocje(QString("Murmansk"), 852 , 83 ,2, 78 ,1);
        o[ 79 ] = new Obmocje(QString("Ural"), 1119 , 144 ,2, 79 ,1);
        o[ 80 ] = new Obmocje(QString("Riga"), 761 , 329 ,2, 80 ,2);
        o[ 81 ] = new Obmocje(QString("Gijon"), 449 , 510 ,0, 81 ,2);


        for(int i=0;i<st_polj;i++){
            addItem(o[i]);
        }
        povej_sosede();

}



void Zemljevid::povej_sosede()
{
    //o[0]->nastej_sosede();
    o[0]->nastej_sosede(29,24,33,26,27);
    o[1]->nastej_sosede(2,3,4,101,2);
    o[2]->nastej_sosede(1,4,12,101,3);
    o[3]->nastej_sosede(1,4,55,39,101);
    o[4]->nastej_sosede(1,2,3,5,12);
    o[5]->nastej_sosede(4,6,10,101,8);
    o[6]->nastej_sosede(5,7,55,101,2);
    o[7]->nastej_sosede(8,9,6,101,10);
    o[8]->nastej_sosede(7,26,52,10,101);
    o[9]->nastej_sosede(7,24,26,101,0);
    o[10]->nastej_sosede(5,8,81,101,5);
    o[11]->nastej_sosede(12,13,81,101,2);
    o[12]->nastej_sosede(2,4,11,101,3);
    o[13]->nastej_sosede(11,14,101,101,3);
    o[14]->nastej_sosede(13,15,101,8,9);
    o[15]->nastej_sosede(14,16,19,101,8);
    o[16]->nastej_sosede(81,15,52,101,19);
    o[17]->nastej_sosede(26,27,18,52,101);
    o[18]->nastej_sosede(19,20,28,101,3);
    o[19]->nastej_sosede(15,18,21,101,0);
    o[20]->nastej_sosede(18,28,21,22,101);
    o[21]->nastej_sosede(19,20,22,46,101);
    o[22]->nastej_sosede(21,20,42,43,46);
    o[23]->nastej_sosede(24,34,36,101,3);
    o[24]->nastej_sosede(9,34,0,23,101);
    o[25]->nastej_sosede(33,25,59,60,101);
    o[26]->nastej_sosede(8,17,9,0,101);
    o[27]->nastej_sosede(17,29,28,0,101);
    o[28]->nastej_sosede(18,27,29,20,30);
    o[29]->nastej_sosede(28,27,0,30,32);
    o[30]->nastej_sosede(29,28,32,31,42);
    o[31]->nastej_sosede(32,30,44,73,101);
    o[32]->nastej_sosede(60,33,29,30,31);
    o[33]->nastej_sosede(35,34,0,32,25);
    o[34]->nastej_sosede(23,24,33,35,101);
    o[35]->nastej_sosede(80,33,34,25,101);
    o[36]->nastej_sosede(38,37,23,101,0);
    o[37]->nastej_sosede(38,40,36,101,10);
    o[38]->nastej_sosede(37,39,55,36,101);
    o[39]->nastej_sosede(3,40,38,101,5);
    o[40]->nastej_sosede(39,41,37,101,4);
    o[41]->nastej_sosede(40,78,77,101,2);
    o[42]->nastej_sosede(30,22,43,44,101);
    o[43]->nastej_sosede(42,22,46,101,3);
    o[44]->nastej_sosede(31,45,42,101,9);
    o[45]->nastej_sosede(44,49,48,101,8);
    o[46]->nastej_sosede(22,43,47,21,101);
    o[47]->nastej_sosede(46,48,101,8,10);
    o[48]->nastej_sosede(45,47,49,101,3);
    o[49]->nastej_sosede(76,50,53,45,48);
    o[50]->nastej_sosede(49,51,101,101,4);
    o[51]->nastej_sosede(50,74,101,6,2);
    o[52]->nastej_sosede(81,16,17,8,101);
    o[53]->nastej_sosede(54,71,76,49,101);
    o[54]->nastej_sosede(72,53,56,60,73);
    o[55]->nastej_sosede(6,38,3,101,8);
    o[56]->nastej_sosede(59,57,61,54,101);
    o[57]->nastej_sosede(66,62,61,56,72);
    o[58]->nastej_sosede(62,65,66,101,3);
    o[59]->nastej_sosede(80,56,60,25,101);
    o[60]->nastej_sosede(59,54,32,73,25);
    o[61]->nastej_sosede(80,57,56,63,101);
    o[62]->nastej_sosede(63,58,57,101,3);
    o[63]->nastej_sosede(77,80,61,62,101);
    o[64]->nastej_sosede(78,79,69,65,68);
    o[65]->nastej_sosede(64,68,58,66,101);
    o[66]->nastej_sosede(65,68,67,57,101);
    o[67]->nastej_sosede(66,68,70,101,10);
    o[68]->nastej_sosede(65,67,69,64,101);
    o[69]->nastej_sosede(79,64,68,101,5);
    o[70]->nastej_sosede(67,75,71,101,4);
    o[71]->nastej_sosede(72,70,53,101,2);
    o[72]->nastej_sosede(57,71,54,101,0);
    o[73]->nastej_sosede(31,60,76,54,101);
    o[74]->nastej_sosede(75,51,101,8,9);
    o[75]->nastej_sosede(70,74,101,9,8);
    o[76]->nastej_sosede(73,53,49,101,2);
    o[77]->nastej_sosede(41,63,101,8,10);
    o[78]->nastej_sosede(41,64,101,3,3);
    o[79]->nastej_sosede(64,69,101,5,5);
    o[80]->nastej_sosede(63,61,59,35,101);
    o[81]->nastej_sosede(10,52,11,16,101);

}

void Zemljevid::napad(short drzava_branilca, int id_branilca)
{
    if(o[id_branilca]->geo!=4){      //kopenska bitka
        if((id_branilca!=7&&id_branilca!=34&&id_branilca!=57)||(get_st_obmocij(drzava_branilca)<15)){
            if(get_st_tankov(igralec_na_potezi)!=0){
                if(get_st_tankov(drzava_branilca)!=0){
                    igra->nabitko(id_branilca, drzava_branilca, igralec_na_potezi);
                    return;
                }
                else {
                    igra->nazemljevid(id_branilca,igralec_na_potezi);
                    return;
                }

            }
            else {
                warning->prikazsporocila(1);
                return;
            }
        }
        else{
            warning->prikazsporocila(2);
            return;
        }
    }
    else{            //morska bitka

            if(get_st_ladij(igralec_na_potezi)!=0){
                if(get_st_ladij(drzava_branilca)!=0){
                    igra->nabitko(id_branilca, drzava_branilca, igralec_na_potezi);
                    return;
                }
                else {
                    igra->nazemljevid(id_branilca,igralec_na_potezi);
                    return;
                }

            }
            else {
                warning->prikazsporocila(3);
                return;
            }
        }
}

void Zemljevid::oznaci_moznosti_grajenja()
{
    for(int i=0;i<st_polj;i++){
        if(igralec_na_potezi==o[i]->get_drzava()){
            o[i]->oznaci_za_grajenje();
        }
    }
}

void Zemljevid::posodobi_informacije()
{
    mes_tex->setPlainText(QString::number(get_st_mest()));
    tov_tex->setPlainText(QString::number(get_st_tovarn()));
    den_tex->setPlainText(QString::number(igra->igralec[igralec_na_potezi]->denar));
    tanki_tex->setPlainText(QString::number(get_st_tankov(igralec_na_potezi)));
    obm_tex->setPlainText(QString::number(get_st_obmocij(igralec_na_potezi)));
    ladje_tex->setPlainText(QString::number(get_st_ladij(igralec_na_potezi)));


}

void Zemljevid::izbrisivseizzemljevida()
{
    trgovina->izbrisivseiztrgovine();
    delete trgovina;
    for(int i=0;i<st_polj;i++)
    {
        delete o[i];
    }
    st_polj=0;
    delete den;
    delete den_tex;
    delete flag;
    delete obm_tex;
    delete mapa;
    delete tanki;
    delete tanki_tex;
    delete tov;
    delete tov_tex;
    delete mes;
    delete mes_tex;
    delete ladje;
    delete ladje_tex;
    delete napadi;
    delete preklici;
    delete naslednji;
    delete mesto;
    delete tovarna;
    delete pokazicrte;

    //clear();
}


int Zemljevid::get_igralec_na_potezi()
{
    return igralec_na_potezi;

}

void Zemljevid::set_igralec_na_potezi(short a)
{
    igralec_na_potezi=a-1;

    nasledn();
    igra->igralec[igralec_na_potezi]->denar-=100;
}

int Zemljevid::get_st_tovarn()
{
    int vsota=0;
    for(int i=0;i<st_polj;i++){
        if(igralec_na_potezi==o[i]->get_drzava()&&o[i]->mes_tov==1){
            vsota++;
        }

    }
    return vsota;

}

int Zemljevid::get_st_mest()
{
    int vsota=0;
    for(int i=0;i<st_polj;i++){
        if(igralec_na_potezi==o[i]->get_drzava()&&o[i]->mes_tov==2){
            vsota++;
        }

    }
    return vsota;

}

int Zemljevid::get_st_obmocij(short drz)
{
    int stevec=0;
    for(int i=0;i<st_polj;i++){
        if(o[i]->drzava==drz)stevec++;
    }
    return stevec;

}

int Zemljevid::get_st_tankov(short n)
{
    int vsota=0;
    vsota+=igra->igralec[n]->st_tankov[0];
    vsota+=igra->igralec[n]->st_tankov[1];
    vsota+=igra->igralec[n]->st_tankov[2];
    return vsota;
}

int Zemljevid::get_st_ladij(short n)
{
    return igra->igralec[n]->st_tankov[5];
}

//=============public slots===============
void Zemljevid::oznaci_ogrozene()
{
    preklic();
    stanje=1;
        for(int i=0;i<st_polj;i++){
            if(igralec_na_potezi==o[i]->get_drzava()){
                //qDebug()<<"polje "<<i;
                o[i]->oznaci_sosednja_obmocja();
            }
        }
}

void Zemljevid::stanje_na_2()
{
    preklic();
    stanje=2;
    oznaci_moznosti_grajenja();
}

void Zemljevid::stanje_na_1()
{
    preklic();
    stanje=3;
    oznaci_moznosti_grajenja();
}

void Zemljevid::izrisi_trgovino()
{

    trgovina->podatki_trgovine(igralec_na_potezi);
    trgovina->show();

}


void Zemljevid::nasledn()
{

    preklic();
    igralec_na_potezi++;

    if(igralec_na_potezi==3)igralec_na_potezi=0;
    int manjsa;
    if(get_st_mest()>get_st_tovarn())manjsa=get_st_tovarn();
    else manjsa=get_st_mest();

    flag->setPixmap(igra->igralec[igralec_na_potezi]->zastava);
    igra->pobarvajmapo(igralec_na_potezi);
    igra->igralec[igralec_na_potezi]->denar+=(100*manjsa)+50;
    posodobi_informacije();
}

void Zemljevid::preklic()
{
    trgovina->hide();
    warning->hide();
    for(int i=0;i<st_polj;i++){
        o[i]->dovoli_napad=false;
        o[i]->dovoli_grajenje=false;
        o[i]->pobarvaj();
        stanje=0;
    }

}

void Zemljevid::crte()
{
    if(crtenarisane==0){
        for(int i=0;i<st_polj;i++){
            o[i]->crtaj(crtenarisane);
            o[i]->infrastruktura->show();
        }
    }
    else {
        for(int i=0;i<st_polj;i++){
            o[i]->crtaj(crtenarisane);
            o[i]->infrastruktura->hide();
        }
    }
    if(crtenarisane==0)crtenarisane=1;
    else crtenarisane=0;
}

