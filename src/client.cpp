#include "../include/client.h"

Client::Client(const string& n, const string& e)
    : id(IDGenerator::getInstance().getNextId()), nume(n), email(e) {}

Client::~Client() = default;

unsigned int Client::getId() const {
    return id;
}

string Client::getNume() const {
    return nume;
}

void Client::afisare() const {
    cout << "[" << id << "] " << nume << " <" << email << ">\n";
}

double Client::getReducere() const {
    return 0;
}
