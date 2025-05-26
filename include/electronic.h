#ifndef ELECTRONIC_H
#define ELECTRONIC_H


#include <string>
#include "produs.h"


using std::string;

class Electronic : public Produs {
private:
    string marca;
     int garantie;

public:
    Electronic(const string& den, double p, string  mar, int g);
    void afisare() const override;
    [[nodiscard]] Produs* clone() const override;
};

#endif // ELECTRONIC_H
