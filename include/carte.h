#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include <string>
#include "produs.h"


using std::string;
using std::ostream;
using std::istream;

class Carte : public Produs {
private:
    string autor;
    int nrPagini;

public:
    Carte(const string& den, double p, string  aut, int nrP);
    void afisare() const override;
    [[nodiscard]] Produs* clone() const override;

     [[nodiscard]] const string& getAutor() const;
     [[nodiscard]] int getNrPagini() const;
};

ostream& operator<<(ostream& os, const Carte& c);
istream& operator>>(istream& is, Carte& c);
bool operator>(const Carte& c1, const Carte& c2);

#endif // CARTE_H
