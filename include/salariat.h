#ifndef SALARIAT_H
#define SALARIAT_H

#include "Client.h"
#include "EroareAplicatie.h"

class Salariat : public Client {
private:
    double salariu;

public:
    Salariat(const string& n, const string& e, double s);
    void afisare() const override;
    Client* clone() const override;

    double getSalariu() const;
    void plateste(double suma);
};

#endif // SALARIAT_H
