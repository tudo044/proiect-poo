#ifndef ELECTRONIC_H
#define ELECTRONIC_H

#include <iostream>
#include <string>
#include "Produs.h"
#include "EroareAplicatie.h"

using std::string;

class Electronic : public Produs {
private:
    string marca;
    int garantie;

public:
    Electronic(const string& den, double p, const string& mar, int g);
    void afisare() const override;
    Produs* clone() const override;
};

#endif // ELECTRONIC_H
