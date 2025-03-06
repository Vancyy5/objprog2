#ifndef SKIRSTYMAS_H    
#define SKIRSTYMAS_H

#include "lib.h"
#include "funkcijos.h"
#include "laikas.h"

void skirstytiStudentus(vector<Stud>& grupe, vector<Stud>& kietiakiai, vector<Stud>& vargsai, char ats);
void isvestiStudentusIFaila(const vector<Stud>& studentai, const string& failoPavadinimas, char ats);
void testuotiDuomenuApdorojimas(const string& aplankas, int skaicius);

#endif // SKIRSTYMAS_H