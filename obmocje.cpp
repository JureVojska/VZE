#include "obmocje.h"
#include"igra.h"
extern Igra *igra;

Obmocje::Obmocje(QString ime,int x,int y, short od, short id,short povrsje, QGraphicsItem *parent): QGraphicsEllipseItem(parent)
{
    setRect(0,0,13,13);
    setPos(x,y);
    setAcceptHoverEvents(true);
    setZValue(1);


    ime_kraja= new QGraphicsTextItem(ime,this);
    ime_kraja->setPos(30,0);
    ime_kraja->setFont(QFont("times",15,QFont::Bold));
    ime_kraja->hide();

    dovoli_napad=false;
    dovoli_grajenje=false;
    drzava=od;
    stevilka=id;
    geo=povrsje;
    mes_tov=0;
    st_sosedov=0;

    if(stevilka==7)mes_tov=4;
    if(stevilka==34)mes_tov=4;
    if(stevilka==57)mes_tov=4;

    pobarvaj();

    infrastruktura =new QGraphicsPixmapItem(this);
    if(mes_tov==4){
        infrastruktura->setPixmap(QPixmap(":slike/slike_zemljevid/glavnomesto.png"));
    }
    infrastruktura->setPos(-5,25);
    infrastruktura->hide();
}

void Obmocje::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    if(igra->zemljevid->stanje==1){
        if(dovoli_napad==true){
            igra->zemljevid->napad(drzava,stevilka);
        }else igra->zemljevid->warning->prikazsporocila(8);
    }
    if(igra->zemljevid->stanje==2){
        if(dovoli_grajenje==true)
            postavitovarno();
        else igra->zemljevid->warning->prikazsporocila(6);
    }


    if(igra->zemljevid->stanje==3){
        if(dovoli_grajenje==true)
            postavimesto();
    else igra->zemljevid->warning->prikazsporocila(7);
    }
}



void Obmocje::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    ime_kraja->show();
    if(mes_tov!=0)infrastruktura->show();
    if(dovoli_napad==false&&dovoli_grajenje==false){
        this->setBrush(QColor(red+100,green+100,blue+100));
    }

}



void Obmocje::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    ime_kraja->hide();
    infrastruktura->hide();

    if(dovoli_napad==false&&dovoli_grajenje==false){
        this->pobarvaj2();
    }

}



void Obmocje::pobarvaj()
{

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);


    switch(drzava){
        case 0:{red=5;green=63;blue=128;}break;
    case 1:{red=54;green=61;blue=35;}break;
    case 2:{red=129;green=22;blue=7;} break;
    case 3:{red=0;green=0;blue=0;}break;
}
brush.setColor(QColor(red,green,blue));
setBrush(brush);

}

void Obmocje::pobarvaj2()
{
    this->setBrush(QColor(red,green,blue));

}

void Obmocje::nastej_sosede(int a, int b, int c,int d,int e)
{

    //qDebug()<<a;
    sosedi[0]=a;
    sosedi[1]=b;
    sosedi[2]=c;
    sosedi[3]=d;
    sosedi[4]=e;

}

void Obmocje::oznaci_sosednja_obmocja()
{
    for(int i=0;i<5;i++){
        if(sosedi[i]==101){
            break;  //ce ima polje manj kot 5 sosedov vpises 101
        }
        if(igra->zemljevid->o[sosedi[i]]->get_drzava()!=drzava){
            igra->zemljevid->o[sosedi[i]]->setBrush(Qt::yellow);
            igra->zemljevid->o[sosedi[i]]->dovoli_napad=true;
        }
    }


}

void Obmocje::oznaci_za_grajenje()
{

    dovoli_grajenje=true;
    this->setBrush(Qt::yellow);
}

void Obmocje::crtaj(bool a)
{
    if(a==0){
        st_sosedov=0;
        QLineF linija;
        QPen pen;
        for(int i=0;i<5;i++){
            if(this->sosedi[i]==101)return;
                linija.setLine(this->x()+6,this->y()+6,igra->zemljevid->o[sosedi[i]]->x()+6,igra->zemljevid->o[sosedi[i]]->y()+6);
                crta[i] =new QGraphicsLineItem(linija);
                if(drzava==igra->zemljevid->o[sosedi[i]]->drzava&&drzava==0)pen.setColor(QColor(5,63,128));;
                if(drzava==igra->zemljevid->o[sosedi[i]]->drzava&&drzava==1)pen.setColor(QColor(54,61,35));
                if(drzava==igra->zemljevid->o[sosedi[i]]->drzava&&drzava==2)pen.setColor(QColor(129,22,7));
                if(drzava!=igra->zemljevid->o[sosedi[i]]->drzava)pen.setColor(QColor(204, 204, 0));
                pen.setWidth(3);
                crta[i]->setPen(pen);
                igra->zemljevid->addItem(crta[i]);
                st_sosedov++;
        }
    }
    else {

        for(int i=0;i<st_sosedov;i++){
            delete crta[i];
        }
    }

}

void Obmocje::postavitovarno()
{

    if(igra->igralec[drzava]->denar>=1000&&mes_tov!=4){
        if(geo==4)
            infrastruktura->setPixmap(QPixmap(":slike/slike_zemljevid/tovarna2.png"));
        else
            infrastruktura->setPixmap(QPixmap(":slike/slike_zemljevid/tovarna.png"));
        mes_tov=1;
        infrastruktura->show();
        igra->zemljevid->preklic();
        igra->igralec[drzava]->denar-=1000;
        igra->zemljevid->posodobi_informacije();
    }else igra->zemljevid->warning->prikazsporocila(6);

}

void Obmocje::postavimesto()
{
    if(geo!=4&&mes_tov!=4){
        if(igra->igralec[drzava]->denar>=1000){
            mes_tov=2;
            infrastruktura->setPixmap(QPixmap(":slike/slike_zemljevid/mesto.png"));
            infrastruktura->show();
            igra->zemljevid->preklic();
            igra->igralec[drzava]->denar-=1000;
            igra->zemljevid->posodobi_informacije();
        }else igra->zemljevid->warning->prikazsporocila(7);
    }else igra->zemljevid->warning->prikazsporocila(7);
}


int Obmocje::get_drzava()
{
    return drzava;
}
