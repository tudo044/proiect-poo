#ifndef SALARIAT_H
#define SALARIAT_H

#include "client.h"


class Salariat : public Client {
private:
    double salariu;

public:
    Salariat(const string& n, const string& e, double s);
    void afisare() const override;
    [[nodiscard]] Client* clone() const override;

    void plateste(double suma);
};

#endif // SALARIAT_H
