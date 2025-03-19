#ifndef FUNKCIJOS_H      
#define FUNKCIJOS_H

#include "lib.h"

double skaiciuotiVid(vector <int> nd);
double skaiciuotiMed(vector <int> nd);
bool sortByName(const Stud& a, const Stud& b);
bool sortBySurname(const Stud& a, const Stud& b);
bool sortByFinalGradeAvg(const Stud& a, const Stud& b);
bool sortByFinalGradeMed(const Stud& a, const Stud& b);
void skaitytiIsFailo(Container& grupe,const string& failoPavadinimas);
double skaiciuotiGalutini(const Stud& stud, char metodas);

#endif // FUNKCIJOS_H