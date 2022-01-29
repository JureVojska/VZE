#include "trgovina.h"
#include<QBrush>
#include<QString>
#include"kupiprodaj.h"

#include"igra.h"
extern Igra *igra;

Trgovina::Trgovina()
{
    setRect(0,0,600,500);
    setPos(300,30);

    setAcceptHoverEvents(true);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(242, 230, 217));
    setBrush(brush);

    ustvari_napise();
    ustvari_slike();
    ustvari_gumbe();
}

void Trgovina::mousePressEvent(QGraphicsSceneMouseEvent *)
{

}

void Trgovina::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{

}

void Trgovina::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    igra->zemljevid->posodobi_informacije();
    hide();
}

void Trgovina::ustvari_napise()
{
    denar_st=new QGraphicsTextItem(this);
    denar_st->setPos(150,30);

    lahki_st=new QGraphicsTextItem(this);
    lahki_st->setPos(250,110);

    srednji_st=new QGraphicsTextItem(this);
    srednji_st->setPos(250,165);

    tezki_st=new QGraphicsTextItem(this);
    tezki_st->setPos(250,230);

    katyusha_st=new QGraphicsTextItem(this);
    katyusha_st->setPos(250,410);

    letala_st=new QGraphicsTextItem(this);
    letala_st->setPos(250,350);

    ladje_st=new QGraphicsTextItem(this);
    ladje_st->setPos(250,290);




}

void Trgovina::ustvari_slike()
{
    light_tank=new QGraphicsPixmapItem(this);
    light_tank->setPos(100,100);

    medium_tank=new QGraphicsPixmapItem(this);
    medium_tank->setPos(100,150);

    heavy_tank=new QGraphicsPixmapItem(this);
    heavy_tank->setPos(100,200);

    katyusha=new QGraphicsPixmapItem(this);
    katyusha->setPos(100,380);

    letalo=new QGraphicsPixmapItem(this);
    letalo->setPos(100,340);

    ladja=new QGraphicsPixmapItem(this);
    ladja->setPos(100,280);
}

void Trgovina::ustvari_gumbe()
{
    lahki_kupi=new Kupiprodaj(0,1,100,this);
    lahki_kupi->setPos(450,110);

    lahki_prodaj=new Kupiprodaj(0,0,100,this);
    lahki_prodaj->setPos(400,110);

    srednji_kupi=new Kupiprodaj(1,1,250,this);
    srednji_kupi->setPos(450,170);

    srednji_prodaj=new Kupiprodaj(1,0,250,this);
    srednji_prodaj->setPos(400,170);

    tezki_kupi=new Kupiprodaj(2,1,500,this);
    tezki_kupi->setPos(450,230);

    tezki_prodaj=new Kupiprodaj(2,0,500,this);
    tezki_prodaj->setPos(400,230);

    katyusha_kupi=new Kupiprodaj(3,1,300,this);
    katyusha_kupi->setPos(450,410);

    katyusha_prodaj=new Kupiprodaj(3,0,300,this);
    katyusha_prodaj->setPos(400,410);

    letalo_kupi=new Kupiprodaj(4,1,300,this);
    letalo_kupi->setPos(450,350);

    letalo_prodaj=new Kupiprodaj(4,0,300,this);
    letalo_prodaj->setPos(400,350);

    ladja_kupi=new Kupiprodaj(5,1,500,this);
    ladja_kupi->setPos(450,290);

    ladja_prodaj=new Kupiprodaj(5,0,500,this);
    ladja_prodaj->setPos(400,290);
}

void Trgovina::podatki_trgovine(int igralecnavrsti)
{
    igralecnavrst=igralecnavrsti;
    denar_st->setFont(QFont("times",20,QFont::Black));
    denar_st->setPlainText(QString ("Denar: "+QString::number(igra->igralec[igralecnavrst]->denar)));
    lahki_st->setFont(QFont("times",15));
    lahki_st->setPlainText(QString ("Lahki tanki: "+QString::number(igra->igralec[igralecnavrst]->st_tankov[0])));
    srednji_st->setFont(QFont("times",15));
    srednji_st->setPlainText(QString ("Srednji tanki: "+QString::number(igra->igralec[igralecnavrst]->st_tankov[1])));
    tezki_st->setFont(QFont("times",15));
    tezki_st->setPlainText(QString ("Težki tanki: "+QString::number(igra->igralec[igralecnavrst]->st_tankov[2])));
    katyusha_st->setFont(QFont("times",15));
    katyusha_st->setPlainText(QString ("Raketometi: "+QString::number(igra->igralec[igralecnavrst]->st_tankov[3])));
    letala_st->setFont(QFont("times",15));
    letala_st->setPlainText(QString ("Letala: "+QString::number(igra->igralec[igralecnavrst]->st_tankov[4])));
    ladje_st->setFont(QFont("times",15));
    ladje_st->setPlainText(QString ("Ladje: "+QString::number(igra->igralec[igralecnavrst]->st_tankov[5])));

    light_tank->setPixmap(QPixmap(igra->igralec[igralecnavrst]->za_v_shop[0]));
    medium_tank->setPixmap(QPixmap(igra->igralec[igralecnavrst]->za_v_shop[1]));
    heavy_tank->setPixmap(QPixmap(igra->igralec[igralecnavrst]->za_v_shop[2]));
    katyusha->setPixmap(QPixmap(igra->igralec[igralecnavrst]->za_v_shop[3]));
    letalo->setPixmap(QPixmap(":slike/slike_zemljevid/letalo.png"));
    ladja->setPixmap(QPixmap(":slike/slike_zemljevid/ladja.png"));
    katyusha->setScale(0.7);
}

void Trgovina::posodobi()
{
    lahki_st->setPlainText(QString ("Lahki tanki: "+QString::number(igra->igralec[igralecnavrst]->st_tankov[0])));
    srednji_st->setPlainText(QString ("Srednji tanki: "+QString::number(igra->igralec[igralecnavrst]->st_tankov[1])));
    tezki_st->setPlainText(QString ("Težki tanki: "+QString::number(igra->igralec[igralecnavrst]->st_tankov[2])));
    katyusha_st->setPlainText(QString ("Raketometi: "+QString::number(igra->igralec[igralecnavrst]->st_tankov[3])));
    letala_st->setPlainText(QString ("Letala: "+QString::number(igra->igralec[igralecnavrst]->st_tankov[4])));
    ladje_st->setPlainText(QString ("Ladje: "+QString::number(igra->igralec[igralecnavrst]->st_tankov[5])));
    denar_st->setPlainText(QString ("Denar: "+QString::number(igra->igralec[igralecnavrst]->denar)));
}

void Trgovina::izbrisivseiztrgovine()
{
    delete denar_st;
    delete lahki_st;
    delete srednji_st;
    delete tezki_st;
    delete katyusha_st;
    delete ladje_st;
    delete letala_st;
    delete light_tank;
    delete medium_tank;
    delete heavy_tank;
    delete katyusha;
    delete letalo;
    delete ladja;
    delete lahki_kupi;
    delete lahki_prodaj;
    delete srednji_kupi;
    delete srednji_prodaj;
    delete tezki_kupi;
    delete tezki_prodaj;
    delete katyusha_kupi;
    delete katyusha_prodaj;
    delete ladja_kupi;
    delete ladja_prodaj;
    delete letalo_kupi;
    delete letalo_prodaj;
}

