#ifndef LEGENDA_HPP
#define LEGENDA_HPP
#include<bits/stdc++.h>
using namespace std;

class legenda{

    string zasady;
    bool zasady_vis;

    string instrukcja;
    bool instrukcja_vis;

    string oznaczenia;
    bool oznaczenia_vis;
    public:

    legenda();
    void show_zasady();
    void hide_zasady();
    void show_instrukcja();
    void hide_instrukcja();
    void show_oznaczenia();
    void hide_oznaczenia();
    string wypisz();//zwaraca to co ma zostać wypisane w szczególności pusty string

};
#endif
