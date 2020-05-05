#include <iostream>

using namespace std;
/*
klasa TOsoba, ktora posiada pola: imie, nazwisko, wiek i
adres(obiekt niezaleznej klasy o polach: miasto, ulica, numer z konstruktorem ustaw. pola na podst. param, destruktorem i metoda Wyswietl)
Klasa ma metody:
-konstruktor,
-Wyswietl-wyswietla informacje o osobie,
-PodajImie- zwraca imie,
-PodajNazwisko-zwraca nazwisko,
-destruktor
Definiujemy klase TStudent dziedziczaca po klasie TOsoba. Klasa TStudent posiada dodatkowo pola:
-kierunek
-rok
oraz metody:
-konstruktor,
-Wyswietl-wyswietla informacje o studencie
-PodajKierunek-zwraca kierunek,
-destruktor
Funkcja testuj, ktora:
-definiuje zm. lokalna st typu TStudent, wyswietla dane studenta
-tworzy zmienna dynamiczna typu TStudent, wysw. dane studenta
-def. zm. refer. typu TOsoba, inicjalizuje ja zmienna st,wyswietla wart. pol
-wyswietla nazw. i kier. studentow
*/
class Adres{
protected:
    string miasto;
    string ulica;
    int numer;
public:
    Adres(string m, string u, int nr);
    ~Adres(){cout<<" Destruktor klasy Adres "<<endl;}
    void Wyswietl();
};

Adres::Adres(string m, string u, int nr){
    miasto = m;
    ulica = u;
    numer = nr;
    cout<<"Konstruktor klasy Adres"<<endl;
}

void Adres::Wyswietl(){
    cout<<"Miasto: "<<miasto<<endl;
    cout<<"Ulica: "<<ulica<<endl;
    cout<<"Numer: "<<numer<<endl;
}

class TOsoba{
protected:
    string imie;
    string nazwisko;
    int wiek;
    Adres ad;
public:
    TOsoba(string i, string n, int w, string m, string u, int nr);
    TOsoba(string i, string n, int w, Adres ad);
    string PodajImie();
    string PodajNazwisko();
    ~TOsoba(){cout<<"Destruktor klasy TOsoba"<<endl;}
    virtual void Wyswietl();
};

TOsoba::TOsoba(string i, string n, int w, string m, string u, int nr) :ad(m, u, nr){
    imie=i;
    nazwisko=n;
    wiek=w;
    cout<<" Konstruktor klasy TOsoba "<<endl;
}

void TOsoba::Wyswietl(){
    cout<<"Dane Osoby: "<<endl;
    cout<<" Imie: "<<imie<<endl;
    cout<<" Nazwisko: "<<nazwisko<<endl;
    cout<<" Wiek: "<<wiek<<endl;
    ad.Wyswietl();
}

string TOsoba::PodajImie(){
    return imie;
}

string TOsoba::PodajNazwisko(){
    return nazwisko;
}

class TStudent:public TOsoba{
protected:
    string kierunek;
    int rok;
public:
    TStudent(string i, string n, int w, string m, string u, int nr, string k, int r);
    virtual void Wyswietl();
    string PodajKierunek();
    ~TStudent(){cout<<" Destruktor klasy TStudent "<<endl;}
    void Testuj();
};

TStudent::TStudent(string i, string n, int w, string m, string u, int nr, string k, int r):TOsoba(i, n, w, m, u, nr){
    kierunek = k;
    rok = r;
    cout<<"Konstruktor klasy TStudent"<<endl;
}

void TStudent::Wyswietl(){
    cout<<"Dane Studenta: "<<endl;
    TOsoba::Wyswietl();
    cout<<" Kierunek: "<<kierunek<<endl;
    cout<<" Rok: "<<rok<<endl;
}

string TStudent::PodajKierunek(){
    return kierunek;
}

void TStudent::Testuj(){
    TStudent st;
    st.Wyswietl();
    TStudent *s=new TStudent;
    *s.Wyswietl();
    }

int main()
{

    cout << "Hello world!" << endl;
    return 0;
}
