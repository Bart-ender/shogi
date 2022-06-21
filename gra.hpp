#ifndef GRA_HPP
#define GRA_HPP
#include<bits/stdc++.h>
#include<ncurses.h>
#include "legenda.hpp"
#include "rozgrywka.hpp"
#include "plansza.hpp"
#include "gracz.hpp"
#include "bledy.hpp"
#include "pionek.hpp"
#include "pozycja.hpp"
//using namespace std;

class gra{

    bool numer(std::string s);
    bool koniec;
    legenda l;
    rozgrywka r;//robi updaty na planszy i depozyty graczy
    gracz g1;
    gracz g2;
    plansza p;
    std::string komunikat;

    void update();//updatuje wyglad ekranu
    public:

    gra();
    void next_event(std::string inp);
};
#endif
