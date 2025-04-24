#include "zmogus.h"

// Copy assignment operator
Zmogus& Zmogus::operator=(const Zmogus& other) {
    if (this != &other) {
        vardas_ = other.vardas_;
        pavarde_ = other.pavarde_;
    }
    return *this;
}

// Move constructor
Zmogus::Zmogus(Zmogus&& other) noexcept 
    : vardas_(std::move(other.vardas_)), 
      pavarde_(std::move(other.pavarde_)) {
}

// Move assignment operator
Zmogus& Zmogus::operator=(Zmogus&& other) noexcept 
{
    if (this != &other) {
        vardas_ = std::move(other.vardas_);
        pavarde_ = std::move(other.pavarde_);
    }
    return *this;
}

// Global operators
std::ostream& operator<<(std::ostream& os, const Zmogus& zmogus) {
    zmogus.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Zmogus& zmogus) {
    zmogus.read(is);
    return is;
}