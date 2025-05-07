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

/**
 * @class Studentas
 * @brief Student class that inherits from Zmogus (Person) abstract class
 * 
 * This class represents a student with homework grades, exam score and final grade.
 * It inherits from the abstract Zmogus class and implements its pure virtual methods.
 */
class Studentas : public Zmogus 
{
// realizacija
private:
    std::vector<int> nd_;        ///< Vector of homework (namų darbų) scores
    int egzaminas_;              ///< Exam score
    double galutinis_;           ///< Final grade

// interfeisas
public:
    /// Static counter for tracking destructor calls (for testing)
    static int destruktoriuSk;

    /**
     * @brief Default constructor
     * Initializes a student with default values
     */
    Studentas() : Zmogus(), egzaminas_(0), galutinis_(0) { }
    
    /**
     * @brief Constructor that initializes a student from input stream
     * @param is Input stream to read from
     */
    Studentas(std::istream& is);
    
    /**
     * @brief Constructor with name and surname
     * @param vardas Student's first name
     * @param pavarde Student's last name
     */
    Studentas(const std::string& vardas, const std::string& pavarde) 
        : Zmogus(vardas, pavarde), egzaminas_(0), galutinis_(0) { }
    
    // Rule of Five
    /**
     * @brief Copy constructor
     * @param other Another student to copy from
     */
    Studentas(const Studentas& other); 
    
    /**
     * @brief Copy assignment operator
     * @param other Another student to copy from
     * @return Reference to this student after assignment
     */
    Studentas& operator=(const Studentas& other);
    
    /**
     * @brief Move constructor
     * @param other Another student to move from
     */
    Studentas(Studentas&& other) noexcept;
    
    /**
     * @brief Move assignment operator
     * @param other Another student to move from
     * @return Reference to this student after assignment
     */
    Studentas& operator=(Studentas&& other) noexcept;
    
    /**
     * @brief Virtual destructor
     * Overrides the pure virtual destructor from Zmogus
     */
    ~Studentas() override;
    
    // Implementation of pure virtual methods
    /**
     * @brief Prints student information to output stream
     * @param os Output stream to print to
     */
    void print(std::ostream& os) const override;
    
    /**
     * @brief Reads student information from input stream
     * @param is Input stream to read from
     */
    void read(std::istream& is) override;
    
    // Getteriai
    /**
     * @brief Get homework grades
     * @return Vector of homework grades
     */
    inline std::vector<int> nd() const { return nd_; }
    
    /**
     * @brief Get exam grade
     * @return Exam grade
     */
    inline int egzaminas() const { return egzaminas_; }
    
    /**
     * @brief Get final grade
     * @return Final grade
     */
    inline double galutinis() const { return galutinis_; }

    // Setteriai
    /**
     * @brief Set exam grade
     * @param egzaminas Exam grade to set
     */
    inline void setEgzaminas(int egzaminas) { egzaminas_ = egzaminas; }
    
    /**
     * @brief Set final grade
     * @param galutinis Final grade to set
     */
    inline void setGalutinis(double galutinis) { galutinis_ = galutinis; }

    // Metodai
    /**
     * @brief Read student data from input stream
     * @param is Input stream to read from
     * @return Reference to the input stream
     */
    std::istream& readStudent(std::istream& is);
    
    /**
     * @brief Add a homework grade
     * @param pazymys Grade to add
     * @throw std::invalid_argument If grade is not between 1 and 10
     */
    void addND(int pazymys);
    
    /**
     * @brief Clear all homework grades
     */
    void clearND();
    
    /**
     * @brief Calculate average of homework grades
     * @return Average of homework grades
     * @throw std::runtime_error If there are no homework grades
     */
    double skaiciuotiVid() const;
    
    /**
     * @brief Calculate median of homework grades
     * @return Median of homework grades
     * @throw std::runtime_error If there are no homework grades
     */
    double skaiciuotiMed() const;
    
    /**
     * @brief Calculate final grade
     * @param naudotiVidurki Whether to use average (true) or median (false)
     * @return Final grade calculated as 0.4*homework + 0.6*exam
     */
    double galBalas(bool naudotiVidurki = true) const;
    
    /**
     * @brief Static method for reading students from file
     * @param grupe Vector to store students
     * @param failoPavadinimas Filename to read from
     */
    static void nuskaitymasFile(std::vector<Studentas>& grupe, const std::string& failoPavadinimas);
};

/**
 * @brief Compare students by first name
 * @param a First student
 * @param b Second student
 * @return True if a's name comes before b's
 */
bool compareByVardas(const Studentas& a, const Studentas& b);

/**
 * @brief Compare students by last name
 * @param a First student
 * @param b Second student
 * @return True if a's surname comes before b's
 */
bool compareByPavarde(const Studentas& a, const Studentas& b);

/**
 * @brief Compare students by final grade (descending)
 * @param a First student
 * @param b Second student
 * @return True if a's final grade is higher than b's
 */
bool compareByGalutinis(const Studentas& a, const Studentas& b);

/**
 * @brief Read students from file
 * @param grupe Vector to store students
 * @param failoPavadinimas Filename to read from
 */
void skaitytiIsFailo(std::vector<Studentas>& grupe, const std::string& failoPavadinimas);

/**
 * @brief Write students to file
 * @param studentai Students to write
 * @param failoPavadinimas Filename to write to
 * @param ats Whether to use average ('v') or median ('m') for final grade
 */
void isvestiStudentusIFaila(const std::vector<Studentas>& studentai, const std::string& failoPavadinimas, char ats);

/**
 * @brief Sort students by specified criterion
 * @param grupe Students to sort
 * @param sortingOption Sorting criterion: 'v' (name), 'p' (surname), 'g' (final grade)
 */
void sortStudentai(std::vector<Studentas>& grupe, char sortingOption);

/**
 * @brief Split students into two groups based on final grade
 * @param grupe Input vector of students
 * @param kietiakiai Output vector for students with final grade >= 5.0
 * @param vargsai Output vector for students with final grade < 5.0
 */
void skirstytiStudentus(std::vector<Studentas>& grupe, std::vector<Studentas>& kietiakiai, std::vector<Studentas>& vargsai);

/**
 * @brief Test data processing performance
 * @param aplankas Directory for files
 * @param skaicius Number of students
 */
void testuotiDuomenuApdorojima(const std::string& aplankas, int skaicius);

/**
 * @brief Test Studentas class methods
 */
void testuotiStudentoMetodus();

/**
 * @brief Test Zmogus class
 */
void testuotiZmogausKlase();

#endif // FUNKCIJOS_H