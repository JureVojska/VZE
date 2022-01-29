#ifndef KATYUSHA_H
#define KATYUSHA_H
#include<QGraphicsPixmapItem>

#include<QObject>

class Katyusha: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
private:
     int koncnaposx,koncnaposy,st_igralca,st_iztrelkov;
     int zacetnaposx;
     int moc;
     //int nakljucno;
     short za_nastavitev;
     float dolzina;
     QGraphicsRectItem *pom;
     QTimer *voznja1;
     QTimer *voznja2;
     QTimer *iztrel;
     QTimer *sled;
public:
    Katyusha(int ax, bool st_igral, int a);
    void pelji();
    void rafal();
    void sledi();
    void sprememba_moci(int a);

public slots:
    void pripelji();
    void odpelji();
    void ustreli();
    void fokusiraj();
};

#endif // KATYUSHA_H
