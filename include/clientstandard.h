#ifndef CLIENTSTANDARD_H
#define CLIENTSTANDARD_H

#include "client.h"

class ClientStandard : public Client {
public:
    ClientStandard(const string& n, const string& e);
    void afisare() const override;
    [[nodiscard]] Client* clone() const override;
};

#endif // CLIENTSTANDARD_H

