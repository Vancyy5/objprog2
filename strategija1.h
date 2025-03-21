#ifndef STRATEGIJA1_H    
#define STRATEGIJA1_H 

#include "lib.h"
#include "funkcijos.h"
#include "laikas.h"

template <typename Container>
void skirstytiStudentus(Container& grupe, Container& kietiakiai, Container& vargsai);
template <typename Container>
void testuotiDuomenuApdorojimapirma(const std::string& aplankas, int skaicius, const char& konteineris);
template <typename Container>
void sortByChoice(Container& grupe, char sortingOption);

#endif // STRATEGIJA1_H 