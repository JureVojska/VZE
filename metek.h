#ifndef METEK_H
#define METEK_H
#include<QGraphicsRectItem>
#include<QObject>


class Metek: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    int stevec;
    int mposx,mposy;
    int zamik_x,zamik_y;
    int graf_x,graf_y;
    float m_x;
    bool smer;
    bool zadnjiMetek;
    float hitrost;
    int g;
    int moc;
    float kot_radiani;
    QTimer *casovnik;
    int skoda;
public:
    Metek(int x, int y, int z_x, int z_y, bool dir, bool zadnM, int damage);

    void vnos(float v_kot, int v_moc);
    void ustavi_metek(bool a);
    float f(int x);

    void rotiraj(int x);
public slots:
    void premakni_metek();
    void animacija();
};

#endif // METEK_H
