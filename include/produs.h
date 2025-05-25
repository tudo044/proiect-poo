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
    [[nodiscard]] string& getDenumire();
    [[nodiscard]] double getPret() const;
    void setPret(double p);

    virtual void afisare() const;
    [[nodiscard]] virtual Produs* clone() const = 0;
};

ostream& operator<<(ostream& os,  Produs& p);
bool operator==(const Produs& p1,  Produs& p2);

#endif // PRODUS_H

