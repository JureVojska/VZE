#include "top.h"
#include<QGraphicsPathItem>
#include<QDebug>
Top::Top(bool st)
{
    st_igralca=st;
    this->setZValue(-1);
}

void Top::nastaviTop(int tankposx,int tankposy,int zx,int zy,QString slika,int tockavrtenja)
{
    topposx=zx;
    topposy=zy;
    QPixmap *pom=new QPixmap(slika);
    dolzinatopa=pom->width();
    setPixmap(*pom);
    delete pom;

    if(st_igralca==0)
        setPos(tankposx+topposx,tankposy+topposy);
    else{
        topposx=-topposx;
        this->setTransform(QTransform::fromScale(-1,1));
    }
    setPos(tankposx+topposx,tankposy+topposy);
    this->setTransformOriginPoint(tockavrtenja,10);
    this->setRotation(0);

}


void Top::postavi(int x,int y)
{
    setPos(x+topposx,y+topposy);
    qDebug()<<this->x();
}

int Top::get_dolzina()
{
    return dolzinatopa;
}
