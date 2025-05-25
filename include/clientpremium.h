#ifndef CLIENTPREMIUM_H
#define CLIENTPREMIUM_H

#include "client.h"

class ClientPremium : public Client {
private:
    double reducere;

public:
    ClientPremium(const string& n, const string& e, double r);
    void afisare() const override;
    [[nodiscard]] Client* clone() const override;
    [[nodiscard]] double getReducere() const override;
};

#endif // CLIENTPREMIUM_H

