#ifndef EROAREAPLICATIE_H
#define EROAREAPLICATIE_H

#include <exception>
#include <string>

using std::string;
using std::exception;

class EroareAplicatie : public exception {
private:
    string mesaj;

public:
    explicit EroareAplicatie(const string& m);
    const char* what() const noexcept override;
};

#endif // EROAREAPLICATIE_H
