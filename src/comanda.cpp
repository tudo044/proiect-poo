#include "../include/comanda.h"
#include "idgenerator.h"
Comanda::Comanda(unsigned int cid)
    : id(IDGenerator::getInstance().getNextId()), idClient(cid) {}

void Comanda::adaugaProdus(const Produs& p) {
    produse.push_back(shared_ptr<Produs>(p.clone()));
}

void Comanda::afisare() const {
    cout << "Comanda ID: " << id << ", Client ID: " << idClient << "\nProduse:\n";
    for (const auto& p : produse) {
        p->afisare();
    }
}

double Comanda::total() const {
    double sum = 0;
    for (const auto& p : produse)
        sum += p->getPret();
    return sum;
}
