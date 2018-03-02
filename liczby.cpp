#include "liczby.h"
#include <iostream>
using namespace std;

Lista::Lista()
{
    this->poczatek = NULL;
    this->koniec = NULL;
    ileJest=0;
}

Lista::~Lista()
{
    Box *lazik;

    while(this->poczatek)
    {
        lazik = poczatek;
        poczatek = lazik->next;
        delete lazik;
    }
    cout << "Pamiec zwolniona" << endl;
}

void Lista::Dodaj_lista(char x)
{
    Box *temp = new Box(x);

    if(!this->poczatek)
    {
        this->poczatek = temp;
        this->poczatek->prev = NULL;
        this->koniec = temp;
    }
    else
    {
        Box* tmp = this->koniec;

        this->koniec->next = temp;
        this->koniec = temp;
        this->koniec->prev = tmp;
    }
    ileJest++;
}

void Lista::Znormalizuj()
{
    bool done=false;
    while(!done)
    {
        Box* tmp;
        tmp = this->poczatek;
        if(tmp->val=='0')
        {
            this->poczatek = tmp->next;
            delete tmp;
        }
        else
        {
            done = true;
        }
    }
}

void Lista::Dodaj_stos(char x)
{
    Box* temp = new Box(x);

    if(this->poczatek == NULL)
    {
        this->poczatek = temp;
        this->poczatek->prev = NULL;
        this->koniec = temp;
    }
    else
    {
        Box* tmp = this->poczatek;
        this->poczatek = temp;
        this->poczatek->next = tmp;
        this->poczatek->prev = NULL;
    }
    ileJest++;
}

void Lista::Wczytaj()
{
    string input;
    bool wczytane=false;
    while(!wczytane)
    {
        cin >> input;

        for(unsigned int i=0;i<input.length();i++)
        {
            if(input[i]!='X' && input[i]!='x')
            {
                if(input[i]!='(' && input[i]!=')' && input[i]!='\n' &&((input[i]=='+' || input[i]=='-')||(input[i]-'0'>=0 && input[i]-'0'<=9)))
                {
                    Dodaj_lista(input[i]);
                }
            }
            else wczytane=true;
        }
    }
}

ostream& operator<<(ostream& os, const Lista& lt)
{
    Box *lazik = lt.poczatek;


    if(lazik->val!='0')
    {
        os<<"("<<lazik->val;
        lazik=lazik->next->next;

        while(lazik)
        {
            os<<lazik->val;
            lazik=lazik->next;
        }

        os<<") ";
        return os;
    }
    else
    {
        os<<lazik->val;
        return os;
    }
}

const bool operator<(const Lista& a,const Lista& b)
{
    if(a.poczatek->val==b.poczatek->val)
    {
        if(a.poczatek->val=='+')
        {
            if(a.ileJest>b.ileJest)
            {
                return false;
            }
            else
            {
                if(a.ileJest==b.ileJest)
                {
                    Box* alazik;
                    Box* blazik;
                    alazik = a.poczatek;
                    blazik = b.poczatek;
                    while(alazik && blazik)
                    {
                        if(alazik->val-'0'>blazik->val-'0')
                        {
                            return false;
                        }
                        if(alazik->val-'0'<blazik->val-'0')
                        {
                            return true;
                        }
                        alazik=alazik->next;
                        blazik=blazik->next;
                    }
                }
                else
                {
                    return true;
                }
            }
        }
        else
        {
            if(a.poczatek->val=='-')
            {
                if(a.ileJest>b.ileJest)
                {
                    return true;
                }
                else
                {
                    if(a.ileJest==b.ileJest)
                    {
                        Box* alazik;
                        Box* blazik;
                        alazik = a.poczatek;
                        blazik = b.poczatek;
                        while(alazik && blazik)
                            {
                                if(alazik->val-'0'<blazik->val-'0')
                                {
                                    return false;
                                }
                                if(alazik->val-'0'>blazik->val-'0')
                                {
                                    return true;
                                }
                                alazik=alazik->next;
                                blazik=blazik->next;
                            }
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }
    else
    {
        if(a.poczatek->val=='+' && b.poczatek->val=='-')
        {
            return false;
        }
        else
        {
            return true;
        }
    }

}

const bool operator>(const Lista& a,const Lista& b)
{
    if(a.poczatek->val==b.poczatek->val)
    {
        if(a.poczatek->val=='+')
        {
            if(a.ileJest>b.ileJest)
            {
                return true;
            }
            else
            {
                if(a.ileJest==b.ileJest)
                {
                    Box* alazik;
                    Box* blazik;
                    alazik = a.poczatek;
                    blazik = b.poczatek;
                    while(alazik && blazik)
                    {
                        if(alazik->val-'0'>blazik->val-'0')
                        {
                            return true;
                        }
                        if(alazik->val-'0'<blazik->val-'0')
                        {
                            return false;
                        }
                        alazik=alazik->next;
                        blazik=blazik->next;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            if(a.poczatek->val=='-')
            {
                if(a.ileJest>b.ileJest)
                {
                    return false;
                }
                else
                {
                    if(a.ileJest==b.ileJest)
                    {
                        Box* alazik;
                        Box* blazik;
                        alazik = a.poczatek;
                        blazik = b.poczatek;
                        while(alazik && blazik)
                            {
                                if(alazik->val-'0'<blazik->val-'0')
                                {
                                    return true;
                                }
                                if(alazik->val-'0'>blazik->val-'0')
                                {
                                    return false;
                                }
                                alazik=alazik->next;
                                blazik=blazik->next;
                            }
                    }
                    else
                    {
                        return true;
                    }
                }
            }
        }
    }
    else
    {
        if(a.poczatek->val=='+' && b.poczatek->val=='-')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

const bool operator==(const Lista& a,const Lista& b)
{
    if(a.ileJest!=b.ileJest)
    {
        return false;
    }
    else
    {
        Box *alazik,*blazik;
        alazik = a.poczatek;
        blazik = b.poczatek;
        while(alazik && blazik)
        {
            if(alazik->val!=blazik->val)
            {
                return false;
            }
            else
            {
                alazik = alazik->next;
                blazik = blazik->next;
            }

        }
        return true;
    }
}

Lista& Lista::absSuma(const Lista& a,const Lista& b)
{
    Box *alazik,*blazik;
    alazik = a.koniec;
    blazik = b.koniec;
    bool dodjeden = false;

    while(alazik!=a.poczatek->next && blazik!=b.poczatek->next)
    {
        int sum = ((alazik->val - '0') + (blazik->val - '0') + dodjeden);
        dodjeden = false;
        if(sum>9)
        {
            dodjeden=true;
            sum-=10;
        }
        this->Dodaj_stos(sum+'0');
        alazik=alazik->prev;
        blazik=blazik->prev;
    }
    if(alazik==a.poczatek->next && blazik==b.poczatek->next && dodjeden==true)
    {
        this->Dodaj_stos('1');
    }
    else
    {
        while(alazik!=a.poczatek->next)
        {
            if(alazik->val-'0'+dodjeden>10)
            {
                this->Dodaj_stos((10 -(alazik->val-'0')+dodjeden)+'0');
                dodjeden=true;
            }
            else
            {
                this->Dodaj_stos(((alazik->val-'0') + dodjeden)+'0');
                dodjeden=false;
            }
            alazik=alazik->prev;
        }
        while(blazik!=b.poczatek->next)
        {
            if(blazik->val-'0'+dodjeden>10)
            {
                this->Dodaj_stos((10 -(blazik->val-'0')+dodjeden)+'0');
                dodjeden=true;
            }
            else
            {
                this->Dodaj_stos(((blazik->val-'0') + dodjeden)+'0');
                dodjeden=false;
            }
            blazik=blazik->prev;
        }
    }

    return *this;

}

Lista& Lista::absRoznica(const Lista& a,const Lista& b)
{
    Box *alazik,*blazik;
    alazik = a.koniec;
    blazik= b.koniec;


    bool odjeden = false;

    while(alazik!=a.poczatek->next && blazik!=b.poczatek->next)
    {
        int sum = (alazik->val - '0') - (blazik->val - '0') - odjeden;
        odjeden = false;
        if(sum<0)
        {
            sum=10+sum;
            odjeden=true;
        }
        if(sum>=0)this->Dodaj_stos(sum+'0');
        alazik=alazik->prev;
        blazik=blazik->prev;
    }
    while(alazik!=a.poczatek->next)
    {
        if(((alazik->val -'0')-odjeden)>0)
        {
            this->Dodaj_stos((alazik->val-'0'-odjeden)+'0');
            odjeden=false;
        }
        else
        {
            if(alazik->prev!=a.poczatek->next)
            {
                if(alazik->val-'0'-odjeden<0)this->Dodaj_stos((10+(alazik->val-'0'-odjeden))+'0');
                odjeden=true;
            }
        }
        alazik=alazik->prev;
    }
    while(blazik!=b.poczatek->next)
    {
        if(((blazik->val -'0')-odjeden)>0)
        {
            this->Dodaj_stos((blazik->val-'0'-odjeden)+'0');
            odjeden=false;
        }
        else
        {
            if(blazik->prev!=b.poczatek->next)
            {
                if(blazik->val-'0'-odjeden<0)this->Dodaj_stos((10+(blazik->val-'0'-odjeden))+'0');
                odjeden=true;
            }
        }
        blazik=blazik->prev;
    }

    this->Znormalizuj();
    return *this;
}

const bool absWiekszy(const Lista& a,const Lista& b)
{
    if(a.ileJest>b.ileJest)
    {
        return true;
    }
    else
    {
        if(a.ileJest<b.ileJest)
        {
            return false;
        }
        else
        {
            Box *alazik,*blazik;
            alazik = a.poczatek->next;
            blazik = b.poczatek->next;

            while(alazik && blazik)
            {
                if(alazik->val-'0' > blazik->val - '0')
                {
                    return true;
                }
                if(alazik->val-'0' < blazik->val - '0')
                {
                    return false;
                }
                alazik=alazik->next;
                blazik=blazik->next;
            }
            return false;
        }
    }
}

const bool absRowny(const Lista& a,const Lista& b)
{
    if(a.ileJest!=b.ileJest)
    {
        return false;
    }
    else
    {
        Box *alazik,*blazik;
        alazik = a.poczatek->next;
        blazik = b.poczatek->next;

        while(alazik && blazik)
        {
            if(alazik->val != blazik->val)
            {
                return false;
            }
            alazik = alazik->next;
            blazik = blazik->next;
        }
        return true;
    }

}

const Lista operator+(const Lista& a,const Lista& b)
{
    string znaki;
    znaki+=a.poczatek->val;
    znaki+=b.poczatek->val;
    Lista tmp;
    if(znaki=="++")
    {
        tmp.absSuma(a,b);
        tmp.Dodaj_stos('1');
        tmp.Dodaj_stos('+');
    }
    else
    {
        if(znaki=="--")
        {
            tmp.absSuma(a,b);
            tmp.Dodaj_stos('1');
            tmp.Dodaj_stos('-');
        }
        else
        {
            if(znaki=="+-")
            {
                if(absRowny(a,b))
                {
                    tmp.Dodaj_stos('0');
                }
                else
                {
                    if(absWiekszy(a,b))
                    {
                        tmp.absRoznica(a,b);
                        tmp.Dodaj_stos('1');
                        tmp.Dodaj_stos('+');
                    }
                    else
                    {
                        tmp.absRoznica(b,a);
                        tmp.Dodaj_stos('1');
                        tmp.Dodaj_stos('-');
                    }

                }
            }
            else
            {
                if(znaki=="-+")
                {
                    if(absRowny(a,b))
                    {
                        tmp.Dodaj_stos('0');
                    }
                    else
                    {
                        if(absWiekszy(a,b))
                        {
                            tmp.absRoznica(a,b);
                            tmp.Dodaj_stos('1');
                            tmp.Dodaj_stos('-');
                        }
                        else
                        {
                            tmp.absRoznica(b,a);
                            tmp.Dodaj_stos('1');
                            tmp.Dodaj_stos('+');
                        }
                    }
                }
            }
        }
    }

    return tmp;
}



const Lista operator-(const Lista& a,const Lista& b)
{
    string znaki;
    znaki+=a.poczatek->val;
    znaki+=b.poczatek->val;
    Lista tmp;
    if(znaki=="++")
    {
        if(absRowny(a,b))
        {
            tmp.Dodaj_stos('0');
        }
        else
        {
            if(absWiekszy(a,b))
            {   tmp.absRoznica(a,b);
                tmp.Dodaj_stos('1');
                tmp.Dodaj_stos('+');
            }
            else
            {
                tmp.absRoznica(b,a);
                tmp.Dodaj_stos('1');
                tmp.Dodaj_stos('-');
            }
        }
    }
    else
    {
        if(znaki=="--")
        {
            if(absRowny(a,b))
            {
                tmp.Dodaj_stos('0');
            }
            else
            {
                tmp.absRoznica(a,b);
                tmp.Dodaj_stos('1');
                if(absWiekszy(a,b))
                {
                    tmp.Dodaj_stos('-');
                }
                else
                {
                    tmp.Dodaj_stos('+');
                }
            }
        }
        else
        {
            if(znaki=="+-")
            {
                tmp.absSuma(a,b);
                tmp.Dodaj_stos('1');
                tmp.Dodaj_stos('+');
            }
            else
            {
                if(znaki=="-+")
                {
                    tmp.absSuma(a,b);
                    tmp.Dodaj_stos('1');
                    tmp.Dodaj_stos('-');
                }
            }
        }
    }

    return tmp;
}



