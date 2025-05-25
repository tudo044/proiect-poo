#ifndef CLIENTPREMIUM_H
#define CLIENTPREMIUM_H

#include "Client.h"

class ClientPremium : public Client {
private:
    double reducere;

public:
    ClientPremium(const string& n, const string& e, double r);
    void afisare() const override;
    Client* clone() const override;
    double getReducere() const override;
};

#endif // CLIENTPREMIUM_H

