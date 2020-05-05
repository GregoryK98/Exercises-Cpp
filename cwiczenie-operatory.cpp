#include <iostream>
#include <cmath>

using namespace std;
/*klasa, która reprezentuje liczbe zespolona i posiada funkcje, takie jak:
a) konstruktor, ktory pobiera dwa argumenty rzeczywiste (oba maja wartosc domyslna 0)
i ustawia czesc rzeczywista na podstawie pierwszego parametru, a czesc urojona na podstawie drugiego
b) operatory +,-,*,/ wyznaczajace l. zespolona bedaca suma, roznica, iloczynem i ilorazem l. zespolonej
na rzecz ktorej wywolany jest operator i l, zespolonej bedacej parametrem operatora
c) operatory +=, -=
d) operatory <<,>> czytania i wypisywania ze/na standardowe(go) wejscia/wyjscia
e) operator ==
f) operator < porownujacy moduly liczb zespolonych
*/
class Zespolona{
private:
    double czesc_rzeczywista;
    double czesc_urojona;
public:
    Zespolona(double cz_rzecz=0, double cz_uroj=0);
    Zespolona operator+(Zespolona z);
    Zespolona operator-(Zespolona z);
    Zespolona operator*(Zespolona z);
    Zespolona operator/(Zespolona z);
    Zespolona &operator+=(Zespolona z);
    Zespolona &operator-=(Zespolona z);
    friend ostream &operator<<(ostream &wyj, Zespolona z);
    friend istream &operator>>(istream &wej, Zespolona &z);
    bool operator==(const Zespolona z);
    bool operator<(const Zespolona z);
};

Zespolona::Zespolona(double cz_rzecz, double cz_uroj){
    czesc_rzeczywista=cz_rzecz;
    czesc_urojona=cz_uroj;
}

Zespolona Zespolona::operator+(Zespolona z){
    Zespolona z5(czesc_rzeczywista+z.czesc_rzeczywista, czesc_urojona+z.czesc_urojona);
    return z5;
}

Zespolona Zespolona::operator-(Zespolona z){
    Zespolona z6(czesc_rzeczywista-z.czesc_rzeczywista, czesc_urojona-z.czesc_urojona);
    return z6;
}

Zespolona Zespolona::operator*(Zespolona z){
    Zespolona z7((czesc_rzeczywista*z.czesc_rzeczywista - czesc_urojona*z.czesc_urojona) + (czesc_rzeczywista*z.czesc_urojona+czesc_urojona*z.czesc_rzeczywista));
    return z7;
}

Zespolona Zespolona::operator/(Zespolona z){
    Zespolona z8((czesc_rzeczywista) * (z.czesc_rzeczywista)+(czesc_urojona) * (z.czesc_urojona)/((z.czesc_rzeczywista * (z.czesc_rzeczywista) + (z.czesc_urojona)*(z.czesc_urojona))) , ((czesc_urojona) * (z.czesc_rzeczywista) - (czesc_rzeczywista) * (z.czesc_urojona))/((z.czesc_rzeczywista) * (z.czesc_rzeczywista) + (z.czesc_urojona)*(z.czesc_urojona)));
    return z8;
}

Zespolona &Zespolona::operator+=(Zespolona z){
    czesc_rzeczywista+=z.czesc_rzeczywista;
    czesc_urojona+=z.czesc_urojona;
    return *this;
}

Zespolona &Zespolona::operator-=(Zespolona z){
    czesc_rzeczywista-=z.czesc_rzeczywista;
    czesc_urojona-=z.czesc_urojona;
    return *this;
}

bool Zespolona::operator==(const Zespolona z){
    if(czesc_rzeczywista == z.czesc_rzeczywista && czesc_urojona == z.czesc_urojona)
        return 1;
    else
        return 0;
}

ostream &operator<<(ostream &wyj, Zespolona z){
   wyj << z.czesc_rzeczywista <<" -rzeczywista "<< z.czesc_urojona <<" -urojona "<<endl;
   return wyj;
}


istream &operator>>(istream &wej, Zespolona &z) {
   cout<<"Podaj cz rzeczywista i urojona"<<endl;
   wej >>z.czesc_rzeczywista >>z.czesc_urojona;
   return wej;
}

bool Zespolona::operator<(const Zespolona z){
    double a=sqrt((czesc_rzeczywista * czesc_rzeczywista) + (czesc_urojona * czesc_urojona));
    double b=sqrt((z.czesc_rzeczywista * z.czesc_rzeczywista) + (z.czesc_urojona * z.czesc_urojona));
    if(a>b)
        return 1;
    else
        return 0;
}

int main()
{
    Zespolona z1(5,6);
    Zespolona z2(2,4);
    cout << z1 + z2 << endl;
    cout << z1 - z2 << endl;
    cout << z1 * z2 << endl;
    cout << z1 / z2 << endl;
    if(z1 < z2)
        cout<<"Modul pierwszej liczby zespolonej jest wiekszy"<<endl;
    else
        cout<<"Modul drugiej liczby zespolonej jest wiekszy"<<endl;
    if(z1==z2)
        cout<<"Obie liczby sa rowne"<<endl;
    else
        cout<<"Liczby nie sa rowne"<<endl;
    return 0;
}
