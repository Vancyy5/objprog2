#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
#include <iostream>

/**
 * @class Zmogus
 * @brief Abstract base class representing a person
 * 
 * This class serves as an abstract base class for all person types.
 * It implements common attributes (name, surname) and declares pure virtual methods.
 */
class Zmogus 
{
protected:
    std::string vardas_;    ///< First name of the person
    std::string pavarde_;   ///< Last name of the person

public:
    /**
     * @brief Default constructor
     */
    Zmogus() = default;
    
    /**
     * @brief Constructor with name and surname
     * @param vardas First name
     * @param pavarde Last name
     */
    Zmogus(const std::string& vardas, const std::string& pavarde) 
        : vardas_(vardas), pavarde_(pavarde) {}
    
    // Rule of Five
    /**
     * @brief Copy constructor
     * @param other Another person to copy from
     */
    Zmogus(const Zmogus& other) : vardas_(other.vardas_), pavarde_(other.pavarde_) {}
    
    /**
     * @brief Copy assignment operator
     * @param other Another person to copy from
     * @return Reference to this person after assignment
     */
    Zmogus& operator=(const Zmogus& other);
    
    /**
     * @brief Move constructor
     * @param other Another person to move from
     */
    Zmogus(Zmogus&& other) noexcept;
    
    /**
     * @brief Move assignment operator
     * @param other Another person to move from
     * @return Reference to this person after assignment
     */
    Zmogus& operator=(Zmogus&& other) noexcept;

    /**
     * @brief Virtual destructor
     * Pure virtual destructor makes this class abstract
     */
    virtual ~Zmogus() = 0;
    
    /**
     * @brief Print person information to output stream
     * @param os Output stream to print to
     * 
     * Pure virtual method that derived classes must implement
     */
    virtual void print(std::ostream& os) const = 0;
    
    /**
     * @brief Read person information from input stream
     * @param is Input stream to read from
     * 
     * Pure virtual method that derived classes must implement
     */
    virtual void read(std::istream& is) = 0;
    
    // Getters and setters
    /**
     * @brief Get first name
     * @return First name of the person
     */
    inline std::string vardas() const { return vardas_; }
    
    /**
     * @brief Get last name
     * @return Last name of the person
     */
    inline std::string pavarde() const { return pavarde_; }
    
    /**
     * @brief Set first name
     * @param vardas First name to set
     */
    inline void setVardas(const std::string& vardas) { vardas_ = vardas; }
    
    /**
     * @brief Set last name
     * @param pavarde Last name to set
     */
    inline void setPavarde(const std::string& pavarde) { pavarde_ = pavarde; }
};

/**
 * @brief Output operator for Zmogus class
 * @param os Output stream
 * @param zmogus Person to output
 * @return Reference to output stream
 */
std::ostream& operator<<(std::ostream& os, const Zmogus& zmogus);

/**
 * @brief Input operator for Zmogus class
 * @param is Input stream
 * @param zmogus Person to input to
 * @return Reference to input stream
 */
std::istream& operator>>(std::istream& is, Zmogus& zmogus);

#endif // ZMOGUS_H