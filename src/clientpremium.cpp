#include "../include/clientpremium.h"

ClientPremium::ClientPremium(const string& n, const string& e, double r)
    : Client(n, e), reducere(r) {}

void ClientPremium::afisare() const {
    cout << "Client Premium -> ";
    Client::afisare();
    cout << "Reducere: " << reducere << "%\n";
}

Client* ClientPremium::clone() const {
    return new ClientPremium(*this);
}

double ClientPremium::getReducere() const {
    return reducere;
}
