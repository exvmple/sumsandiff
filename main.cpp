#include <iostream>
#include "liczby.h"
using namespace std;

int main()
{
    bool done = false;
    while(!done)
    {
        Lista a,b;
        cout <<"Remember to input numbers in this way : (+1)xxxxxxxxxxxxxxxx"<<endl;
        cout<<"Please input number a= ";
        a.Wczytaj();
        cout<<endl;
        cout<<"Please input number b= ";
        b.Wczytaj();
        cout <<endl;
        cout << a <<" + "<<b<<"= "<<a+b<<endl;
        cout << a <<" - "<<b<<"= "<<a-b<<endl;
        cout <<"Press any key to continue or press x to quit: ";
        char x;
        cin >> x;
        if(x=='x' || x =='X')
        {
            done = true;
        }
    }


    return 0;
}
