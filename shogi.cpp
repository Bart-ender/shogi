#include<bits/stdc++.h>
#include<ncurses.h>
#include "gra.cpp"
using namespace std;

int main(){

   // initscr();
    gra g = gra();
    //g.legenda();
    string inp;
    cin>>inp;
    while(inp[0]!='q'){
        cin>>inp;
        g.next_event(inp);
    }
  //  endwin();
    cout<<"Thaks for playing, have a nice day! :D";
}
