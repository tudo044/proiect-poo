#include "../include/clientstandard.h"

ClientStandard::ClientStandard(const string& n, const string& e)
    : Client(n, e) {}

void ClientStandard::afisare() const {
    cout << "Client Standard -> ";
    Client::afisare();
}

Client* ClientStandard::clone() const {
    return new ClientStandard(*this);
}
