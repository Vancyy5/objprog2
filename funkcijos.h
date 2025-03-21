#ifndef FUNKCIJOS_H      
#define FUNKCIJOS_H

#include "lib.h"

template <typename Container>
double skaiciuotiVid(const Container& nd);

template <typename Container>
double skaiciuotiMed(const Container& nd);

template <typename Container>
void skaitytiIsFailo(Container& grupe, const std::string& failoPavadinimas);

template <typename Container>
void isvestiStudentusIFaila(const Container& studentai, const std::string& failoPavadinimas, char ats);

template <typename Container>
void sortByChoice(Container& grupe, char sortingOption);

#endif // FUNKCIJOS_H