#include <utility>

#include "../include/produs.h"
#include "eroareaplicatie.h"
#include "idgenerator.h"
Produs::Produs(string  den, double p) : id(IDGenerator::getInstance().getNextId()), denumire(std::move(den)), pret(p) {
    if (pret < 0)
        throw EroareAplicatie("Pretul nu poate fi negativ.");
}

Produs::~Produs() = default;

unsigned int Produs::getId() const {
    return id;
}

const string& Produs::getDenumire() const {
    return denumire;
}

double Produs::getPret() const {
    return pret;
}

void Produs::setPret(double p) {
    if (p >= 0)
        pret = p;
}


ostream& operator<<(ostream& os, const Produs& p) {
    os << "[" << p.getId() << "] " << p.getDenumire() << " - " << p.getPret() << " RON";
    return os;
}
 void Produs::afisare() const {
    cout << *this;
}
bool operator==(const Produs& p1,const Produs& p2) {
    return p1.getDenumire() == p2.getDenumire() && std::abs(p1.getPret() - p2.getPret()) < 1e-6;
}
