#include<bits/stdc++.h>
#include "bledy.hpp"
#include "pozycja.hpp"
#include "plansza.hpp"
#include "pionek.hpp"
#include "gracz.hpp"

using namespace std;

bledy::bledy(){last_error="";}

bool bledy::czy_pozycja(string s){
    if(s.size()!=2) return false;
    if(s[0]<'a' || s[0]>'i' ) return false;
    if(s[1]<'1' || s[1]>'9') return false;
    return true;
}

bool bledy::numer(string s){
    for(int i=0; i<s.size();i++)
        if(s[i]<'0' || s[i]>'9') return false;
    return true;
}

bool bledy::sprawdz_wstawienie(gracz *g, int n, pozycja poz, plansza *b){
    n--;
    if( n > g->ile_pionkow()){ last_error= "nie masz tylu zbitych figór\n"; return false; }
    pionek p = g->get_pionek(n);
    if((b->get_pionek(poz)).get_symbol()!='⬜') {last_error= "nie można wstawic figury na zajęte pole\n"; return false;}
    if(!p.can_move(poz)) {last_error="nie można wstawić figury na te pozycje\n"; return false;}
    if(p.get_symbol()=='p'){
        if(b->czy_pion(poz)){last_error="nie można wstwaic pionka gdy już jeden jest w kolumnie\n"; return false;}
        if(p.check_move(b->ruch(poz,b->krol(!p.g) ))){last_error="nie można wstawić pionka tak by szachował króla\n"; return false;}
    }
    last_error="";
    return true;
}

bool bledy::sprawdz_ruch(bool g,pozycja poz1, pozycja poz2,plansza *b){
    pionek p1=b->get_pionek(poz1);
    pionek p2=b->get_pionek(poz2);
    if(g!=p1.g) {last_error="Próba ruszenia nie swojego pionka\n"; return false;}
    if(!p1.check_move(b->ruch(poz1,poz2))){last_error="Ta figura nie może przejść na to pole\n"; return false;}
    if(p2.get_symbol()!='⬜'){
        if(p2.g==p1.g){last_error="Nie można bić swoich pionków\n"; return false;}
    }
    if(p1.get_symbol()=='l'){
        if(b->pion(poz1,poz2)){last_error="Nie można przeskakiwać przez figury\n"; return false;}
    }
    if(p1.get_symbol()=='g'){
        if(b->skos(poz1,poz2)) {last_error="Nie można przeskakiwać przez figury\n"; return false;}
    }
    if(p1.get_symbol()=='w'){
        if(b->pion(poz1,poz2) || b->poziom(poz1,poz2)){last_error="Nie można przeskakiwać przez figury\n"; return false;}
    }
    return true;
}

bool bledy::promocja(bool g, pozycja poz){
    if(g) return poz.x>5;
    return poz.x<3;
}

string bledy::wypisz_blad() {string ret= last_error; last_error=""; return ret;}
