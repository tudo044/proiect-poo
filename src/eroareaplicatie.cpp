#include <utility>

#include "../include/eroareaplicatie.h"

EroareAplicatie::EroareAplicatie(string  m) : mesaj(std::move(m)) {}

const char* EroareAplicatie::what() const noexcept {
    return mesaj.c_str();
}
