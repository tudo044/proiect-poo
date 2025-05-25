#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "IDGenerator.h"

using std::string;
using std::cout;

class Client {
protected:
    unsigned int id;
    string nume;
    string email;

public:
    Client(const string& n, const string& e);
    virtual ~Client();

    unsigned int getId() const;
    string getNume() const;

    virtual void afisare() const;
    virtual Client* clone() const = 0;
    virtual double getReducere() const;
};

#endif // CLIENT_H
