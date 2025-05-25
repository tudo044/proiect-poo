#include "../include/eroareaplicatie.h"

EroareAplicatie::EroareAplicatie(const string& m) : mesaj(m) {}

const char* EroareAplicatie::what() const noexcept {
    return mesaj.c_str();
}
