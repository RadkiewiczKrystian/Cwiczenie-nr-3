#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

struct Probka
{
    double t, x;
    Probka();
    Probka(double t2, double x2)
    {
        t = t2;
        x = x2;
    }
};

using namespace std;
typedef vector <Probka> Dane;
vector <Probka> wczytaj (const string& nazwa_pliku)
{
    vector<Probka> dane;
    ifstream plik;
    plik.open(nazwa_pliku.c_str(), ios::in);
    string linia;
    while (getline (plik, linia))
    {
        stringstream ss (linia);
        double liczba1, liczba2;
        ss >> liczba1;
        ss.ignore();
        ss >> liczba2;
        Probka nowa_probka(liczba1, liczba2);
        dane.push_back(nowa_probka);

    }
    plik.close();
    return dane;
}

void wyswietlanie (const vector<Probka>& dane) {
    for (int i = 1; i < dane.size(); ++i) {
        cout << dane[i].t << ", " << dane[i].x << endl;
    }
}
void zapisywanie (const vector<Probka>& dane, const string& nazwa_pliku) {
    ofstream plik;
    plik.open(nazwa_pliku.c_str(), ios::out);
    for (int i = 1; i < dane.size(); ++i) {
        plik << dane[i].t << ", " << dane[i].x << endl;
    }
    plik.close();
}
double srednia (const vector<Probka>& dane) {
    double m = 0.0;
    for (int i = 1; i < dane.size(); ++i) {
        m += dane[i].x;
    }
    if (dane.size() > 0) {
        m = m / dane.size()-1;
    }
    return m;
}
double minimum(const vector <Probka>& dane) {
    double _min = dane[1].x;
    for ( int i=1; i<dane.size(); i++) {
        if (dane[i].x < _min)
            _min = dane[i].x;
    }
    return _min;
}
double maksimum(const vector <Probka>& dane) {
    double _max = dane[1].x;
    for ( int i=1; i<dane.size(); i++) {
        if (dane[i].x > _max)
            _max = dane[i].x;
    }
    return _max;
}
double dlugosc(double _min, double _max) {
    return _max - _min;
}
double calkuj(const vector <Probka>& dane) {
    double calka = 0, dt = 0, dpole = 0;
    for (int i=1; i < dane.size(); i++)
    {
        dt = dane[i+1].t - dane[i].t;
        dpole = (dane[i].x + dane[i+1].x) * dt / 2;
        calka = calka + dpole;
    }
    return calka;
}

#include <iomanip>

int main ()
{
    string o_nazwa, z_nazwa;
    cout << "Podaj nazwe pliku i po kropce rozszerzenie: "; cin >> o_nazwa;
    cout << "Podaj nazwe pliku i po kropce rozszerzenie gdzie ma zapisac dane: "; cin >> z_nazwa;
    wyswietlanie(wczytaj(o_nazwa));
    cout << "Srednia wartosc t: " << setprecision(6) << srednia(wczytaj(o_nazwa)) << endl;
    cout << "Maksimum wartosci t: " << setprecision(6) << maksimum(wczytaj(o_nazwa)) << endl;
    cout << "Minimum wartosci t: " << setprecision(6) << minimum(wczytaj(o_nazwa)) <<endl;
    cout << "Dlugosc wartosci t: " << setprecision(6) << dlugosc(minimum(wczytaj(o_nazwa)), maksimum(wczytaj(o_nazwa))) << endl;
    zapisywanie(wczytaj(o_nazwa), z_nazwa);
    cout << "Calka metoda trapezow: " << setprecision(6) << calkuj(wczytaj(o_nazwa));
}
