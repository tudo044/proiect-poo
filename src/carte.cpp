#include <utility>

#include "../include/carte.h"
#include "eroareaplicatie.h"
Carte::Carte(const string& den, double p, string  aut, int nrP)
    : Produs(den, p), autor(std::move(aut)), nrPagini(nrP) {
    if (nrPagini <= 0)
        throw EroareAplicatie("Numarul de pagini trebuie sa fie pozitiv.");
}

void Carte::afisare() const {
    cout << "Carte -> ";
    Produs::afisare();
    cout << "  Autor: " << autor << ", Pagini: " << nrPagini << "\n";
}

Produs* Carte::clone() const {
    return new Carte(*this);
}

string Carte::getAutor() const {
    return autor;
}

int Carte::getNrPagini() const {
    return nrPagini;
}

ostream& operator<<(ostream& os, Carte& c) {
    os << static_cast< Produs&>(c) << ", Autor: " << c.getAutor() << ", Pagini: " << c.getNrPagini();
    return os;
}

istream& operator>>(istream& is, Carte& c) {
    string denumire, autor;
    double pret;
    int pagini;
    cout << "Denumire carte: "; getline(is, denumire);
    cout << "Autor: "; getline(is, autor);
    cout << "Pret: "; is >> pret;
    cout << "Nr. pagini: "; is >> pagini;
    is.ignore();
    if (pret < 0 || pagini <= 0)
        throw EroareAplicatie("Date carte invalide!");
    c = Carte(denumire, pret, autor, pagini);
    return is;
}

bool operator>(const Carte& c1, const Carte& c2) {
    return c1.getNrPagini() > c2.getNrPagini();
}
