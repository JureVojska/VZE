#ifndef KONEC_H
#define KONEC_H
#include<QGraphicsRectItem>

class Konec:public QObject, public QGraphicsRectItem
{
public:
    Konec(short a, int st_a, short b, int st_b, short c);
};

#endif // KONEC_H
