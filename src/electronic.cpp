#include <utility>

#include "../include/electronic.h"
#include "eroareaplicatie.h"
Electronic::Electronic(const string& den, double p, string  mar, int g)
    : Produs(den, p), marca(std::move(mar)), garantie(g) {
    if (garantie < 0)
        throw EroareAplicatie("Garantia trebuie sa fie pozitiva.");
}

void Electronic::afisare() const {
    cout << "Electronic -> ";
    Produs::afisare();
    cout << "  Marca: " << marca << ", Garantie: " << garantie << " luni\n";
}

Produs* Electronic::clone() const {
    return new Electronic(*this);
}
