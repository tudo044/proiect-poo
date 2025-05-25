#ifndef MAGAZIN_H
#define MAGAZIN_H

#include <iostream>
#include <vector>
#include <memory>
#include "Produs.h"
#include "Client.h"
#include "Comanda.h"

using std::vector;
using std::shared_ptr;

class Magazin {
private:
    vector<shared_ptr<Produs>> produse;
    vector<shared_ptr<Client>> clienti;
    vector<shared_ptr<Comanda>> comenzi;

public:
    void adaugaProdus(const Produs& p);
    void afiseazaProduse() const;
    const Produs* getProdus(unsigned int id) const;
    void modificaPret(unsigned int id, double nou);

    void adaugaClient(const Client& c);
    void afiseazaClienti() const;
    const Client* getClient(unsigned int id) const;

    void adaugaComanda(const Comanda& c);
    void afiseazaComenzi() const;
};

#endif // MAGAZIN_H
