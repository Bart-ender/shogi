#include<bits/stdc++.h>
#include "gra.hpp"
#include "legenda.hpp"
#include "rozgrywka.hpp"
#include "plansza.hpp"
#include "gracz.hpp"
#include "bledy.hpp"
#include "pionek.hpp"
#include "pozycja.hpp"
using namespace std;

gra::gra(){
    g1 = gracz(false) ;
    g2 = gracz(true) ;
    l = legenda();
    p = plansza();
    komunikat = "";
    r = rozgrywka(&p,&g1,&g2);
    update();
}

vector<string> split(string s, string del = " "){
    vector<string> v;
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        v.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    v.push_back(s.substr(start, end - start));
    return v;
}

void gra::next_event(string inp){ //switch przyjmuje inta lub chara nie stringa
    if(p.koniec) {komunikat="Koniec gry wciśnij q by zakończyć\n."; update(); return;}
    komunikat = "";
    switch (inp[0]){

        case 'i':{ //widzialnosc instrukcji
            if(inp[2]=='0') l.hide_instrukcja();
            else if(inp[2]=='1') l.show_instrukcja();
            else komunikat =  "błedna komenda\n"; break;
        }
        case 'l':{ //widzialnosc oznaczen
            if(inp[2]=='0') l.hide_oznaczenia();
            else if(inp[2]=='1') l.show_oznaczenia();
            else komunikat =  "błedna komenda\n"; break;
        }
        case 'z':{//widzialnosc zasad
            if(inp[2]=='0') l.hide_zasady();
            else if(inp[2]=='1') l.show_zasady();
            else komunikat =  "błedna komenda\n"; break;
        }
        case 's':{// s num poz - przywołaj zbitego pionka o numerze num na pozycje poz
            vector<string>pomi;
            pomi=split(inp);
            if(pomi.size()!=3) komunikat = "zły format komendy";
            else komunikat=r.wstaw(pomi[1],pomi[2]);
        }
        case 'm':{//m poz1 poz2 (p)- przesun pionek z pozycje poz1 na pozycje poz2, opcjonalnie p by zrobić promocje
            vector<string>pomi;
            pomi=split(inp);
            if(pomi.size()==3) komunikat = r.przesun(pomi[1],pomi[2],"n");
            else if (pomi.size()==4) komunikat = r.przesun(pomi[1],pomi[2],pomi[3]);
            else komunikat = "zły format komendy";
            //if(pomi.size()!=3) komunikat = "zły format komendy\n";
           // else komunikat=r.przesun(pomi[1],pomi[2]);
        }
        default:{
            komunikat = "prosze podaj komende\n";
        }
    }
    update();
}

void gra::update(){
   // clear();
    string leg=l.wypisz();
    string pl1="gracz2 "+g1.wypisz();
    string pl=p.wypisz();
    string pl2="gracz1 "+g2.wypisz();
    string wyp= leg+pl1+pl+pl2+komunikat;
    cout<<wyp;
   // refresh()
}
