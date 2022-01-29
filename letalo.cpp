#include"letalo.h"
#include"metek.h"
#include"tank.h"
#include"igra.h"
#include<QGraphicsScene>
#include<QTimer>
#include<QDebug>

extern Igra *igra;
Letalo::Letalo(int ax,int ay,bool st)
{

    lposx=ax;
    lposy=ay;
    st_igralca=st;
    setPixmap(QPixmap(":slike/slike_bitka/letalo.png"));

    if(st_igralca==0){      

          setPos(lposx-300,lposy-500);
          za_nastavitev=70;
      }
    else{
          this->setTransform(QTransform::fromScale(-1,1));
          setPos(lposx+300,lposy-500);
          za_nastavitev=-70;
     }

     doseg_letala=5000;
     let=new QTimer;
     connect(let,SIGNAL(timeout()),this,SLOT(let_letala()));
     let->start(5);
}


void Letalo::spusti()
{
    Metek *metek=new Metek(x(),y(),za_nastavitev,+20,st_igralca,0,120);
    metek->vnos(0,130);
    scene()->addItem(metek);
    doseg_letala=1000;
    Tank::dovoli_premik=false;

}

void Letalo::let_letala()
{
    if(st_igralca==0)setPos(x()+2,y());
    else setPos(x()-2,y());
    if(((doseg_letala<0)||(x()>4900&&st_igralca==0))||(doseg_letala<0||((x()<0)&&(st_igralca==1)))){
        qDebug()<<"zbris letala :)";
        let->stop();
        delete let;
        igra->bitka->spremembaIgralca(st_igralca);
        igra->bitka->removeItem(this);
        Tank::nacin=0;
        Tank::dovoli_premik=true;
        delete this;
        return;
    }
    doseg_letala--;
    igra->centerOn(QPoint(x(),400));
}
