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

class Studentas 
{
// realizacija
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> nd_;
    int egzaminas_;
    double galutinis_;

// interfeisas
public:
    // Konstruktoriai
    Studentas() : egzaminas_(0), galutinis_(0) { }  // default konstruktorius
    Studentas(std::istream& is);
    
    // Rule of Five
    Studentas(const Studentas& other); // Copy constructor
    Studentas& operator=(const Studentas& other); // Copy assignment operator
    Studentas(Studentas&& other) noexcept; // Move constructor
    Studentas& operator=(Studentas&& other) noexcept; // Move assignment operator
    ~Studentas(); // Destruktor
    
    // Getteriai
    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }
    inline std::vector<int> nd() const { return nd_; }
    inline int egzaminas() const { return egzaminas_; }
    inline double galutinis() const { return galutinis_; }

    // Setteriai
    inline void setVardas(const std::string& vardas) { vardas_ = vardas; }
    inline void setPavarde(const std::string& pavarde) { pavarde_ = pavarde; }
    inline void setEgzaminas(int egzaminas) { egzaminas_ = egzaminas; }
    inline void setGalutinis(double galutinis) { galutinis_ = galutinis; }

    // Metodai
    std::istream& readStudent(std::istream& is);
    void addND(int pazymys);
    void clearND();
    double skaiciuotiVid() const;
    double skaiciuotiMed() const;
    double galBalas(bool naudotiVidurki = true) const;
    
    // Input/Output operators
    friend std::ostream& operator<<(std::ostream& os, const Studentas& stud);
    friend std::istream& operator>>(std::istream& is, Studentas& stud);
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

#endif // FUNKCIJOS_H