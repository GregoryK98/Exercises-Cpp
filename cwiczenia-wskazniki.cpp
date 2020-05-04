#include <iostream>

using namespace std;
//funkcja, ktorej parametrami sa: wskaznik do zmiennej typu char(wskaznik do pierwszego elementu tablicy znakow)oraz zmienna typu char
//wystapienie znaku '\0' w tablicy oznacza koniec ciagu znakow. Funkcja zwraca ilosc wystapien znaku podanego jako parametr.
int ileZ(char *p, char x) //(char *p, char *k, char x)
{
    int ile=0;
    while(*p!='\0')       //(p<=k)
    {
        if(*p==x)
            ile++;

        p++;
    }

    return ile;
}

//funkcja, ktorej zadaniem jest znalezienie w tablicy elementu maksymalnego i zwrocenie jego adresu. 
//Parametry funkcji to: wskaznik do zmiennej typu int
//(wskaznik do pierwszego elementu tablicy, wskaznik do zmiennej typu int(adres ostatniego el. tablicy))
int *funkcja(int *p, int *k){
    int *najW=p;
    while(p <= k){
        if(*p > *najW)
            najW = p;

        p++;
    }
    return najW;

}

//Funkcja zerujWieksze typu void, ktorej parametrami sa wskaznik do zmiennej typu int(wsk. do pierwszego el tablicy),
//wskaznik do zmiennej typu int(adres ostatniego elementu tablicy)
//oraz zmienna typu int. Funkcja ma wyzerowac te elementy tablicy które sa wieksze od wartosci podanej jako trzeci parametr
void ZerujWieksze(int *pocz, int *kon, int a){
    while(pocz <= kon){
        if(*pocz>a)
            *pocz=0;
        pocz++;
    }
}

//Funkcja, ktora zwraca wskaznik do pierwszego el. w tablicy podzielnego przez 3. Jezeli taki element nie wystepuje, funkcja zwraca NULL. 
//Parametry to wskaznik do zmiennej tpyu int-wsk. do pierwszego el. tablicy
//oraz wskaznik do zmiennej typu int(adres ostatniego el. tablicy)
int *fun(int *p, int *k){
    while(p <= k){
        if(*p%3==0)
            return p;
        p++;
    }
    return NULL;
}


//Funkcja zwraca wskaznik na najmniejsza liczbe z tablicy. W parametrach jest wskaznik na pierwszy i ostatni element tablicy
int *najmniejsza(int *p,int *k){
    int *a=p;
    while(p <= k){
        if(*p<*a)
            a=p;
    p++;
    }
    return a;
}

//funkcja ma zwrocic adres liczby nadanej jako parametr, np. adres znalezionej liczba=2
int *ZnajdzLiczbe(int *p, int *k, int liczba){
    while(p <= k){
        if(*p==liczba)
            return p;
        p++;
    }
    return NULL;
}

//Funkcja zwraca ilosc trojek w tablicy, jako parametry mamy tylko pierwszy el. tablicy, a 0 jest koncem tablicy
int iloscTrojek(int *pierwszy){
    int a=0;
    while(*pierwszy != 0){
        if(*pierwszy==3)
            a++;
        pierwszy++;
    }
    return a;
}

//Funkcja zamienia liczby ujemne na 1, 0 oznacza koniec tablicy
void funkcja1(int *p){
    while(*p != 0){
        if(*p < 0)
            *p=1;
        p++;
    }
}

//funkcja zwraca ilosc 0 w tablicy i zamienia liczby dodatnie na -1, a ujemne na 1
int iloscZer(int *poczatek, int *koniec){
    int licznik=0;
    while(poczatek <= koniec){
            if(*poczatek>0)
                *poczatek=-1;
            else if(*poczatek<0)
                *poczatek=1;
                else
                    licznik++;

            poczatek++;
    }
    return licznik;
}