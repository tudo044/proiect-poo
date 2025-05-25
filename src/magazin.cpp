#include "../include/magazin.h"
#include <memory>

void Magazin::adaugaProdus(const Produs& p) {
    produse.push_back(shared_ptr<Produs>(p.clone()));
}

void Magazin::afiseazaProduse() const {
    for (const auto& p : produse)
        p->afisare();
}

const Produs* Magazin::getProdus(unsigned int id) const {
    for (const auto& p : produse)
        if (p->getId() == id)
            return p.get();
    return nullptr;
}

void Magazin::modificaPret(unsigned int id, double nou) {
    for (auto& p : produse)
        if (p->getId() == id)
            p->setPret(nou);
}

void Magazin::adaugaClient(const Client& c) {
    clienti.push_back(shared_ptr<Client>(c.clone()));
}

void Magazin::afiseazaClienti() const {
    for (const auto& c : clienti)
        c->afisare();
}

const Client* Magazin::getClient(unsigned int id) const {
    for (const auto& c : clienti)
        if (c->getId() == id)
            return c.get();
    return nullptr;
}

void Magazin::adaugaComanda(const Comanda& c) {
    comenzi.push_back(std::make_shared<Comanda>(c));
}

void Magazin::afiseazaComenzi() const {
    for (const auto& c : comenzi)
        c->afisare();
}
