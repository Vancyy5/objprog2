#ifndef FUNKCIJOS_H      
#define FUNKCIJOS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <execution>
#include <numeric>
#include <cassert>
#include "zmogus.h"

class Studentas : public Zmogus 
{
// realizacija
private:
    std::vector<int> nd_;
    int egzaminas_;
    double galutinis_;

// interfeisas
public:
    // Tracking destructor calls for testing
    static int destruktoriuSk;

    // Konstruktoriai
    Studentas() : Zmogus(), egzaminas_(0), galutinis_(0) { }  // default konstruktorius
    Studentas(std::istream& is);
    Studentas(const std::string& vardas, const std::string& pavarde) 
        : Zmogus(vardas, pavarde), egzaminas_(0), galutinis_(0) { }
    
    // Rule of Five
    Studentas(const Studentas& other); // Copy constructor
    Studentas& operator=(const Studentas& other); // Copy assignment operator
    Studentas(Studentas&& other) noexcept; // Move constructor
    Studentas& operator=(Studentas&& other) noexcept; // Move assignment operator
    ~Studentas() override; // Destructor
    
    // Implementation of pure virtual methods
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    // Getteriai
    inline std::vector<int> nd() const { return nd_; }
    inline int egzaminas() const { return egzaminas_; }
    inline double galutinis() const { return galutinis_; }

    // Setteriai
    inline void setEgzaminas(int egzaminas) { egzaminas_ = egzaminas; }
    inline void setGalutinis(double galutinis) { galutinis_ = galutinis; }

    // Metodai
    std::istream& readStudent(std::istream& is);
    void addND(int pazymys);
    void clearND();
    double skaiciuotiVid() const;
    double skaiciuotiMed() const;
    double galBalas(bool naudotiVidurki = true) const;
    
    // Static method for file reading
    static void nuskaitymasFile(std::vector<Studentas>& grupe, const std::string& failoPavadinimas);
};

//---
bool compareByVardas(const Studentas& a, const Studentas& b);
bool compareByPavarde(const Studentas& a, const Studentas& b);
bool compareByGalutinis(const Studentas& a, const Studentas& b);

//---
void skaitytiIsFailo(std::vector<Studentas>& grupe, const std::string& failoPavadinimas);
void isvestiStudentusIFaila(const std::vector<Studentas>& studentai, const std::string& failoPavadinimas, char ats);
void sortStudentai(std::vector<Studentas>& grupe, char sortingOption);
void skirstytiStudentus(std::vector<Studentas>& grupe, std::vector<Studentas>& kietiakiai, std::vector<Studentas>& vargsai);
void testuotiDuomenuApdorojima(const std::string& aplankas, int skaicius);
void testuotiStudentoMetodus();
void testuotiZmogausKlase(); //testavimas zmogaus objekto sukurimui
#endif // FUNKCIJOS_H