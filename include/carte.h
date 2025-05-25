#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include <string>
#include "Produs.h"
#include "EroareAplicatie.h"

using std::string;
using std::ostream;
using std::istream;

class Carte : public Produs {
private:
    string autor;
    int nrPagini;

public:
    Carte(const string& den, double p, const string& aut, int nrP);
    void afisare() const override;
    Produs* clone() const override;

     string getAutor() const;
     int getNrPagini() const;
};

ostream& operator<<(ostream& os, const Carte& c);
istream& operator>>(istream& is, Carte& c);
bool operator>(const Carte& c1, const Carte& c2);

#endif // CARTE_H
