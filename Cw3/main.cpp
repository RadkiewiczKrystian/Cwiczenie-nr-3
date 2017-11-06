
#include "struktura.hpp"
#include "funkcje.hpp"
#include <iomanip>

int main ()
{
    string o_nazwa, z_nazwa;
    cout << "Podaj nazwe pliku do odczytu ( wraz z rozszerzeniem ): "; cin >> o_nazwa;
    cout << "Podaj nazwe pliku do zapisau ( wraz z rozszerzeniem ): "; cin >> z_nazwa;
    wyswietl(wczytaj(o_nazwa));
    cout << "Srednia wartosc t: " << setprecision(6) << srednia(wczytaj(o_nazwa)) << endl;
    cout << "Minimum wartosci t: " << setprecision(6) << minimum(wczytaj(o_nazwa)) << ", Maksimum wartosci t: " << setprecision(6) << maksimum(wczytaj(o_nazwa)) << endl;
    cout << "Dlugosc wartosci t: " << setprecision(6) << dlugosc(minimum(wczytaj(o_nazwa)), maksimum(wczytaj(o_nazwa))) << endl;
    zapisz(wczytaj(o_nazwa), z_nazwa);
    cout << "Calka metoda trapezow: " << setprecision(6) << calkuj(wczytaj(o_nazwa));
}
