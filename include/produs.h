#ifndef PRODUS_H
#define PRODUS_H

#include <iostream>
#include <string>
#include <cmath>
#include "IDGenerator.h"
#include "EroareAplicatie.h"

using std::string;
using std::ostream;
using std::cout;

class Produs {
protected:
    unsigned int id;
    string denumire;
    double pret;

public:
    Produs(const string& den, double p);
    virtual ~Produs();

    unsigned int getId() const;
    string getDenumire() const;
    double getPret() const;
    void setPret(double p);

    virtual void afisare() const;
    virtual Produs* clone() const = 0;
};

ostream& operator<<(ostream& os, const Produs& p);
bool operator==(const Produs& p1, const Produs& p2);

#endif // PRODUS_H

