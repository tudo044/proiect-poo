#include <utility>

#include "../include/admin.h"

Admin::Admin(string  e, string  p)
    : email(std::move(e)), parola(std::move(p)) {}

bool Admin::autentificare(const string& e, const string& p) const {
    return e == email && p == parola;
}
