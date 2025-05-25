#include "../include/salariat.h"
#include "eroareaplicatie.h"
Salariat::Salariat(const string& n, const string& e, double s)
    : Client(n, e), salariu(s) {}

void Salariat::afisare() const {
    cout << "Salariat -> ";
    Client::afisare();
    cout << "Salariu: " << salariu << " RON\n";
}

Client* Salariat::clone() const {
    return new Salariat(*this);
}


void Salariat::plateste(double suma) {
    if (suma > salariu)
        throw EroareAplicatie("Salariul nu acopera comanda!");
    salariu -= suma;
}
