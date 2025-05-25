#ifndef ADMIN_H
#define ADMIN_H

#include <string>

using std::string;

class Admin {
private:
    string email;
    string parola;

public:
    Admin(string  e, string  p);
    [[nodiscard]] bool autentificare(const string& e, const string& p) const;
};

#endif // ADMIN_H
