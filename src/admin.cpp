#include "../include/admin.h"

Admin::Admin(const string& e, const string& p)
    : email(e), parola(p) {}

bool Admin::autentificare(const string& e, const string& p) const {
    return e == email && p == parola;
}
