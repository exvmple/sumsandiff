#ifndef LICZBY_H
#define LICZBY_H

#include <iostream>
using namespace std;

struct Box
{
    char val;
    Box *next;
    Box *prev;
    Box(char x) { this->val = x; this->next = NULL; this->prev = NULL;};
};

class Lista
{
    Box *poczatek;
    Box *koniec;
    int ileJest;
public:
    Lista();
    ~Lista();
    void Dodaj_lista(char x);
    void Dodaj_stos(char x);
    void Znormalizuj();
    void Wczytaj();

    Lista& absRoznica(const Lista& a, const Lista& b);
    friend const bool absWiekszy(const Lista& a, const Lista& b);
    friend const bool absRowny(const Lista& a, const Lista& b);
    friend ostream& operator<<(ostream& os, const Lista& lt);
    friend const bool operator<(const Lista& a,const Lista& b);
    friend const bool operator>(const Lista& a,const Lista& b);
    friend const bool operator==(const Lista& a,const Lista& b);
    Lista& absSuma(const Lista& a, const Lista& b);
    friend const Lista operator +(const Lista&,const Lista&);
    friend const Lista operator -(const Lista&,const Lista&);
};




#endif // LICZvBY_H

