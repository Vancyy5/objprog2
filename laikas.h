#ifndef LAIKAS_H
#define LAIKAS_H

#include <chrono>
#include <iostream>

/**
 * @class Laikas
 * @brief Class for measuring execution time
 * 
 * This class provides functionality to measure and report the execution time
 * of code segments using high-resolution clock.
 */
class Laikas 
{
private:
    std::chrono::high_resolution_clock::time_point start; ///< Start time point
    std::chrono::high_resolution_clock::time_point end;   ///< End time point
    std::string veiksmoPavadinimas;                       ///< Name of the operation being timed

public:
    /**
     * @brief Constructor
     * @param pavadinimas Name of the operation to time
     */
    Laikas(const std::string& pavadinimas);

    /**
     * @brief Start the timer
     * Records the starting time point
     */
    void pradeti();

    /**
     * @brief Stop the timer and print the elapsed time
     * Records the ending time point and outputs the time difference
     */
    void baigti();

    /**
     * @brief Get the elapsed time in seconds
     * @return Time difference between start and end in seconds
     */
    double gautiLaikoSkirtuma();
};

#endif