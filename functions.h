#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define endl '\n'
using namespace std;
const int N=15;

void wczytajPlansze(char (&plansza)[N][N])
{
        // wczyt plika plansza.txt
        FILE *in=fopen("plansza.txt", "rt");//plik do wczytania
           for(int i=0;i<N-1;i++)
            {
             for(int j=0;j<N;j++)
              {
               fscanf(in,"%c",&plansza[i][j]);
              }
            }
}


void obliczBank (char (&plansza)[N][N], int &bank)
{
    for(int i=0;i<N-1;++i)
    {
        for(int j=0;j<N-1;++j)
        {
            if(plansza[i][j]=='$')
            {
                bank=bank+1;
            }
        }
    }
}



void sprawdzGrawitacje(char (&plansza)[N][N], bool &KoniecGry)
{
    for(int i=1;i<N-1;i++)
    {
        for(int j=1;j<N-1;j++)
        {
            if(plansza[i][j]=='0' && plansza[i+1][j]==' ')
            {
                    plansza[i][j]=' ';
                    plansza[i+1][j]='0';
            }
        }
    }
}


void kolejnyKrok(char (&plansza)[N][N],char &polec ,int &licznik,int &bank,int &rockX, int &rockY,bool &KoniecGry)
{
        if(polec=='w'||polec=='W')
        {
                switch(plansza[rockX-1][rockY])
                        {
                        case '.':
                                plansza[rockX-1][rockY]='&';
                                plansza[rockX][rockY]=' ';
                                rockX--;
                                break;
                        case ' ':
                                plansza[rockX-1][rockY]='&';
                                plansza[rockX][rockY]=' ';
                                rockX--;
                                break;
                        case '$':
                                plansza[rockX-1][rockY]='&';
                                plansza[rockX][rockY]=' ';
                                rockX--;
                                licznik++;
                                break;
                        case 'X':
                                if(licznik==bank)
                                {
                                        plansza[rockX-1][rockY]='X';
                                        plansza[rockX][rockY]=' ';
                                        rockX--;
                                        KoniecGry=true;
                                }
                                break;
                        }


        }
        if(polec=='s'||polec=='S')
        {
                switch(plansza[rockX+1][rockY])
                        {
                        case '.':
                                plansza[rockX+1][rockY]='&';
                                plansza[rockX][rockY]=' ';
                                rockX++;
                                break;
                        case ' ':
                                plansza[rockX+1][rockY]='&';
                                plansza[rockX][rockY]=' ';
                                rockX++;
                                break;
                        case '$':
                                plansza[rockX+1][rockY]='&';
                                plansza[rockX][rockY]=' ';
                                rockX++;
                                licznik++;
                                break;
                        case 'X':
                                if(licznik==bank)
                                {
                                        plansza[rockX+1][rockY]='X';
                                        plansza[rockX][rockY]=' ';
                                        rockX++;
                                        KoniecGry=true;
                                }
                                break;
                        }

        }
        if(polec=='a'||polec=='A')
                {
                        switch(plansza[rockX][rockY-1])
                                {
                                case '.':
                                        plansza[rockX][rockY-1]='&';
                                        plansza[rockX][rockY]=' ';
                                        rockY--;
                                        break;
                                case ' ':
                                        plansza[rockX][rockY-1]='&';
                                        plansza[rockX][rockY]=' ';
                                        rockY--;
                                        break;
                                case '$':
                                        plansza[rockX][rockY-1]='&';
                                        plansza[rockX][rockY]=' ';
                                        rockY--;
                                        licznik++;
                                        break;
                                case 'X':
                                        if(licznik==bank)
                                        {
                                                plansza[rockX][rockY-1]='X';
                                                plansza[rockX][rockY]=' ';
                                                rockY--;
                                                KoniecGry=true;
                                        }
                                        break;
                                }

                }
        if(polec=='d'||polec=='D')
                {
                        switch(plansza[rockX][rockY+1])
                                {
                                case '.':
                                        plansza[rockX][rockY+1]='&';
                                        plansza[rockX][rockY]=' ';
                                        rockY++;
                                        break;
                                case ' ':
                                        plansza[rockX][rockY+1]='&';
                                        plansza[rockX][rockY]=' ';
                                        rockY++;
                                        break;
                                case '$':
                                        plansza[rockX][rockY+1]='&';
                                        plansza[rockX][rockY]=' ';
                                        rockY++;
                                        licznik++;
                                        break;
                                case 'X':
                                        if(licznik==bank)
                                        {
                                                plansza[rockX][rockY+1]='X';
                                                plansza[rockX][rockY]=' ';
                                                rockY++;
                                                KoniecGry=true;
                                        }
                                        break;
                                }

                }
}




void znajdzRockforda(char (&plansza)[N][N],int &rockX, int &rockY)
{

                for(int i=0;i<N-1;i++)
                {
                        for(int j=0;j<N-1;j++)
                        {
                                if(plansza[i][j]=='&')
                                {
                                        rockX=i;
                                        rockY=j;
                                }
                        }
                }
}


void wypiszPlansze(char (&plansza)[N][N])
{
        for(int i=0;i<N-1;i++)
        {
                for(int j=0;j<N;j++)
                {
                        cout<<plansza[i][j];
                }
        }
        cout <<endl;
}

void drawbox(char (&plansza)[N][N])
{
        //korzystalem w tej funkcji z jezyka C, bo I/O w C jest szybszy
    string str = "";
    str.reserve(15 * 15);

    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N;j++)
        {
            str+=char(plansza[i][j]);
        }
    }

    cout << str <<flush;
}

void Witam()
{
    HANDLE screen = GetStdHandle( STD_OUTPUT_HANDLE );

    COORD max_size = GetLargestConsoleWindowSize( screen );

    char first[] = "A generic arcade (really)";
    char second[] = "W,A,S,D - controls ";
    char third[] = "Press X to start";

    COORD pos;
    pos.X = (max_size.X - sizeof(first) ) / 3 ;
    pos.Y = max_size.Y / 2 -15;
    SetConsoleCursorPosition( screen, pos );

    LPDWORD written;
    WriteConsole( screen, first, sizeof(first), written, 0 );

    COORD pos2;
    pos2.X = pos.X ;
    pos2.Y = pos.Y +5;
    SetConsoleCursorPosition( screen, pos2 );

    LPDWORD written2;
    WriteConsole( screen, second, sizeof(second), written2, 0 );

    COORD pos3;
    pos3.X = pos2.X ;
    pos3.Y = pos2.Y +5;
    SetConsoleCursorPosition( screen, pos3 );

    LPDWORD written3;
    WriteConsole( screen, third, sizeof(third), written3, 0 );

    char b = '0';
    while(b!='X' && b!='x')
    {
            b=getch();
    }
    system("cls");
}
