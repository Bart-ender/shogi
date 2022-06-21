#include "legenda.hpp"
using namespace std;

legenda::legenda(){

    oznaczenia_vis=true;
    zasady_vis=true;
    instrukcja_vis=true;

    oznaczenia = "placeholder oznaczenia\n";

    zasady  =   "placeholder zasady\n";

    instrukcja =
        "q - wyjscie\ni 1 - pokaż instrukcje\nz 0 -schowaj zasady\nz 1 - pokaż zasady\ni 0 - schowaj instrukcje\nl 1 - pokaż legende\nl 0 - schowaj legende\ns num poz - przywołaj zbitego pionka o numerze num na pozycje poz\nm poz1 poz2 - przesun pionek z pozycje poz1 na pozycje poz2\n";
}

void legenda::show_zasady(){ zasady_vis=true; }
void legenda::hide_zasady(){ zasady_vis=false;}
void legenda::show_instrukcja(){ instrukcja_vis=true;}
void legenda::hide_instrukcja(){ instrukcja_vis=false;}
void legenda::show_oznaczenia(){ oznaczenia_vis=true;}
void legenda::hide_oznaczenia(){ oznaczenia_vis=false;}

string legenda::wypisz(){

    string wypisz   =   "";
    if(zasady_vis) wypisz   =  zasady;
    if(instrukcja_vis) wypisz = wypisz + instrukcja;
    if(oznaczenia_vis) wypisz = wypisz + oznaczenia;

    return wypisz;
}
