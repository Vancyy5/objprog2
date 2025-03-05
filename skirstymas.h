#ifndef SKIRSTYMAS_H    
#define SKIRSTYMAS_H

#include "lib.h"
#include "funkcijos.h"

void skirstytiStudentus(const vector<Stud>& grupe, vector<Stud>& kietiakiai, vector<Stud>& vargsai, char ats);
void isvestiStudentusIFaila(const vector<Stud>& studentai, const string& failoPavadinimas, char ats);

#endif // SKIRSTYMAS_H