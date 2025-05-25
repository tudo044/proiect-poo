#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>


using std::string;
using std::cout;

class Client {
protected:
    unsigned int id;
    string nume;
    string email;

public:
    Client(string  n, string  e);
    virtual ~Client();

    [[nodiscard]] unsigned int getId() const;
    [[nodiscard]] string getNume() const;

    virtual void afisare() const;
    [[nodiscard]] virtual Client* clone() const = 0;
    [[nodiscard]] virtual double getReducere() const;
};

#endif // CLIENT_H
