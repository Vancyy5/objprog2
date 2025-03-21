#ifndef SKIRSTYMAS_H    
#define SKIRSTYMAS_H

#include "lib.h"
#include "funkcijos.h"
#include "laikas.h"

template <typename Container>
void skirstytiStudentus(Container& grupe, Container& kietiakiai, Container& vargsai);
template <typename Container>
void isvestiStudentusIFaila(const Container& studentai, const std::string& failoPavadinimas, char ats);
template <typename Container>
void testuotiDuomenuApdorojima(const std::string& aplankas, int skaicius, const char& konteineris);
template <typename Container>
void sortByChoice(Container& grupe, char sortingOption);

#endif // SKIRSTYMAS_H