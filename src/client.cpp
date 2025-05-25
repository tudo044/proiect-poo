#include <utility>

#include "../include/client.h"
#include "idgenerator.h"
Client::Client(string  n, string  e)
    : id(IDGenerator::getInstance().getNextId()), nume(std::move(n)), email(std::move(e)) {}

Client::~Client() = default;

unsigned int Client::getId() const {
    return id;
}


void Client::afisare() const {
    cout << "[" << id << "] " << nume << " <" << email << ">\n";
}

double Client::getReducere() const {
    return 0;
}
