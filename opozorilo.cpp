#include "opozorilo.h"
#include <QDebug>

#include"igra.h"
extern Igra *igra;

Opozorilo::Opozorilo()
{
    setRect(0,0,390,35);
    setPos(200,20);

    setAcceptHoverEvents(true);
    setZValue(4);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(242, 230, 217));
    setBrush(brush);
    napis=new QGraphicsTextItem("Vojna za Evropo",this);
    napis->setFont(QFont("times",15,QFont::Bold));
    napis->setPos(100,0);
}


void Opozorilo::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    hide();
}

void Opozorilo::prikazsporocila(int o)
{
    igra->zemljevid->preklic();
    show();
    napis->setPos(0,0);
    switch (o) {
        case 1:{
            napis->setPlainText(QString ("Nimaš tankov!!"));
        }break;
        case 2:{
            napis->setPlainText(QString ("Glavnega mesta še ne moreš napasti!"));

        }break;
        case 3:{
            napis->setPlainText(QString ("Nimaš ladij!"));
        }break;
        case 4:{
            napis->setPlainText(QString ("Nimaš dovolj denarja!"));
        }break;
        case 5:{
            napis->setPlainText(QString ("Ne moreš prodati!"));
        }break;
        case 6:{
            napis->setPlainText(QString ("Tovarne ne moreš postaviti tukaj!"));
        }break;
        case 7:{
            napis->setPlainText(QString ("Mesta ne moreš postaviti tukaj!"));
        }break;
        case 8:{
            napis->setPlainText(QString ("Tega območja ne moreš napasti!"));
        }break;
        case 9:{
            napis->setPlainText(QString ("Igra shranjena!"));
        }break;
        case 10:{
            napis->setPlainText(QString ("Igre ni bilo moč shraniti!"));
        }break;
        case 11:{
            napis->setPlainText(QString ("Igre ni bilo moč naložiti!"));
        }break;

    }
}
