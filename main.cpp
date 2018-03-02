#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "functions.h"
#define endl '\n'


using namespace std;


int main()
{
    int bank=0;
    int rockX=0;
    int rockY=0;
    char polec='0';
    int licznik=0;
    string polecenia_line;
    bool KoniecGry=false;
    int wykonanePolecenia=0;

    char plansza[N][N];
    wczytajPlansze(plansza);
    Witam();
    drawbox(plansza);

    cout << endl;

    znajdzRockforda(plansza,rockX,rockY);
    obliczBank(plansza,bank);


    while(KoniecGry==false and polec!='q')
    {
            //dzialania wewnetrzne
            sprawdzGrawitacje(plansza,KoniecGry);
            polec=getch();
            kolejnyKrok(plansza,polec,licznik,bank,rockX,rockY,KoniecGry);
            wykonanePolecenia++;
            sprawdzGrawitacje(plansza,KoniecGry);

            //dzialania zewnetrzne
            system("cls");
            drawbox(plansza);
            cout<<" Score: "<<licznik<<"("<<bank<<")"<<endl;
    }
    if(KoniecGry==true)
    {
            cout << "** CONGRATULATIONS :) **"<<endl;
            cout <<"Press Q to quit"<<endl;

    }
    char quit='0';
    while(quit!='q' && quit != 'Q')
    {
            quit=getch();
    }
    return 0;
}
