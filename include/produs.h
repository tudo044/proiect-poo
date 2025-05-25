#ifndef PRODUS_H
#define PRODUS_H

#include <iostream>
#include <string>


using std::string;
using std::ostream;
using std::cout;

class Produs {
protected:
    unsigned int id;
    string denumire;
    double pret;

public:
    Produs(string  den, double p);
    virtual ~Produs();

    [[nodiscard]] unsigned int getId() const;
    [[nodiscard]] const string& getDenumire() const;
    [[nodiscard]] double getPret() const;
    void setPret(double p);

    virtual void afisare() const;
    [[nodiscard]] virtual Produs* clone() const = 0;
};

bool operator==(const Produs& p1, const Produs& p2);
ostream& operator<<(ostream& os, const Produs& p);
#endif // PRODUS_H

