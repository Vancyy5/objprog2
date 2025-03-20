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
double skaiciuotiGalutini(const Stud<Container>& stud, char metodas);

#endif // FUNKCIJOS_H