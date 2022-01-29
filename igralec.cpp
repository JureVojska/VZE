#include "igralec.h"

Igralec::Igralec()
{
    denar=2000;
    st_tankov[0]=5;
    st_tankov[1]=3;
    st_tankov[2]=1;
    st_tankov[3]=3;
    st_tankov[4]=3;
    st_tankov[5]=3 ;
//0 lahki tank, 1 srednji tank, 2 težki tank,3 katyushe,4 letala,5 ladje
}

void Igralec::american()
{
    za_v_shop[0]=":slike/slike_zemljevid/A_light_tank.png";
    za_v_shop[1]=":slike/slike_zemljevid/A_medium_tank.png";
    za_v_shop[2]=":slike/slike_zemljevid/A_heavy_tank.png";
    za_v_shop[3]=":slike/slike_bitka/american_katyusha.png";

    tanki[0]=":slike/slike_bitka/american_light_tank.png";
    tanki[1]=":slike/slike_bitka/american_medium_tank.png";
    tanki[2]=":slike/slike_bitka/american_heavy_tank.png";
    topi[0]=":slike/slike_bitka/american_light_top.png";
    topi[1]=":slike/slike_bitka/american_medium_top.png";
    topi[2]=":slike/slike_bitka/american_heavy_top.png";
    tanki[3]=":slike/slike_bitka/american_katyusha.png";

    zastava=":slike/slike_zemljevid/american_flag.png";

    primarnax[2]=121;
    primarnax[1]=111;
    primarnax[0]=98;
    primarnay[2]=28;
    primarnay[1]=26;
    primarnay[0]=12;
    vrtenje[0]=0;
    vrtenje[1]=4;
    vrtenje[2]=10;

    denar=3000;
    st_tankov[0]=5;
    st_tankov[1]=3;
    st_tankov[2]=1;
    st_tankov[3]=3;
    st_tankov[4]=3;
    st_tankov[5]=5 ;

}

void Igralec::nemec()
{
    za_v_shop[0]=":slike/slike_zemljevid/G_light_tank.png";
    za_v_shop[1]=":slike/slike_zemljevid/G_medium_tank.png";
    za_v_shop[2]=":slike/slike_zemljevid/G_heavy_tank.png";
    za_v_shop[3]=":slike/slike_bitka/german_katyusha.png";
    tanki[0]=":slike/slike_bitka/german_light_tank.png";
    tanki[1]=":slike/slike_bitka/german_medium_tank.png";
    tanki[2]=":slike/slike_bitka/german_heavy_tank.png";
    tanki[3]=":slike/slike_bitka/german_katyusha.png";
    topi[0]=":slike/slike_bitka/german_light_top.png";
    topi[1]=":slike/slike_bitka/german_medium_top.png";
    topi[2]=":slike/slike_bitka/german_heavy_top.png";
    zastava=":slike/slike_zemljevid/german_flag.png";
    primarnax[2]=108;
    primarnax[1]=100;
    primarnax[0]=94;
    primarnay[2]=31;
    primarnay[1]=8;
    primarnay[0]=2;
    vrtenje[0]=4;
    vrtenje[1]=5;
    vrtenje[2]=10;

    denar=4000;
    st_tankov[0]=5;
    st_tankov[1]=4;
    st_tankov[2]=3;
    st_tankov[3]=3;
    st_tankov[4]=3;
    st_tankov[5]=3 ;
}

void Igralec::soviet()
{

    za_v_shop[0]=":slike/slike_zemljevid/S_light_tank.png";
    za_v_shop[1]=":slike/slike_zemljevid/S_medium_tank.png";
    za_v_shop[2]=":slike/slike_zemljevid/S_heavy_tank.png";
    za_v_shop[3]=":slike/slike_bitka/soviet_katyusha.png";
    tanki[0]=":slike/slike_bitka/soviet_light_tank.png";
    tanki[1]=":slike/slike_bitka/soviet_medium_tank.png";
    tanki[2]=":slike/slike_bitka/soviet_heavy_tank.png";
    tanki[3]=":slike/slike_bitka/soviet_katyusha.png";
    topi[0]=":slike/slike_bitka/soviet_light_top.png";
    topi[1]=":slike/slike_bitka/soviet_medium_top.png";
    topi[2]=":slike/slike_bitka/soviet_heavy_top.png";
    zastava=":slike/slike_zemljevid/soviet_flag.png";
    primarnax[2]=117;
    primarnax[1]=111;
    primarnax[0]=98;
    primarnay[2]=13;
    primarnay[1]=3;
    primarnay[0]=12;
    vrtenje[0]=4;
    vrtenje[1]=0;
    vrtenje[2]=10;

    denar=2000;
    st_tankov[0]=5;
    st_tankov[1]=3;
    st_tankov[2]=2;
    st_tankov[3]=6;
    st_tankov[4]=3;
    st_tankov[5]=3 ;

}
