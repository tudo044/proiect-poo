#ifndef COMANDA_H
#define COMANDA_H

#include <iostream>
#include <vector>
#include <memory>
#include "IDGenerator.h"
#include "Produs.h"

using std::vector;
using std::shared_ptr;
using std::cout;

class Comanda {
private:
    unsigned int id;
    unsigned int idClient;
    vector<shared_ptr<Produs>> produse;

public:
    Comanda(unsigned int cid);
    void adaugaProdus(const Produs& p);
    void afisare() const;
    double total() const;
};

#endif // COMANDA_H
