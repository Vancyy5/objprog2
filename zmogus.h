#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
#include <iostream>

class Zmogus {
protected:
    std::string vardas_;
    std::string pavarde_;

public:
    // Constructors
    Zmogus() = default;
    Zmogus(const std::string& vardas, const std::string& pavarde) 
        : vardas_(vardas), pavarde_(pavarde) {}
    
    // Rule of Five
    Zmogus(const Zmogus& other) : vardas_(other.vardas_), pavarde_(other.pavarde_) {}
    Zmogus& operator=(const Zmogus& other);
    Zmogus(Zmogus&& other) noexcept;
    Zmogus& operator=(Zmogus&& other) noexcept;
    virtual ~Zmogus() = default;
    
    // Pure virtual methods (make the class abstract)
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    
    // Getters and setters
    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }
    
    inline void setVardas(const std::string& vardas) { vardas_ = vardas; }
    inline void setPavarde(const std::string& pavarde) { pavarde_ = pavarde; }
};

std::ostream& operator<<(std::ostream& os, const Zmogus& zmogus);
std::istream& operator>>(std::istream& is, Zmogus& zmogus);

#endif // ZMOGUS_H