#ifndef LETALO_H
#define LETALO_H
#include<QGraphicsRectItem>

#include<QObject>
class Letalo: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
private:
     int lposx,lposy,st_igralca;
     short za_nastavitev;
     int doseg_letala;

public:
    Letalo(int ax, int ay, bool st);
    QTimer *let;
    void spusti();
public slots:
    void let_letala();

};

#endif // LETALO_H
