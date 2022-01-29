#ifndef TOP_H
#define TOP_H
#include<QGraphicsPixmapItem>
#include<QString>


class Top:public QGraphicsPixmapItem{
private:
    bool st_igralca;
    int topposx,topposy;
    int dolzinatopa;

public:
    Top(bool st);
    void nastaviTop(int tankposx, int tankposy, int zx, int zy, QString slika, int tockavrtenja);
    void postavi(int x, int y);
    int get_dolzina();

};

#endif // TOP_H
