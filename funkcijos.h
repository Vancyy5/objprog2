#ifndef FUNKCIJOS_H      
#define FUNKCIJOS_H

#include "lib.h"

double skaiciuotiVid(vector <int> nd);
double skaiciuotiMed(vector <int> nd);
int readInteger();
int generuotiAtsitiktiniP(int min=1, int max=10) ;
string generuotiPavarde(bool berniukas);
string generuotiVarda(bool berniukas);
bool sortByName(const Stud& a, const Stud& b);
bool sortBySurname(const Stud& a, const Stud& b);
bool sortByFinalGradeAvg(const Stud& a, const Stud& b);
bool sortByFinalGradeMed(const Stud& a, const Stud& b);
void skaitytiIsFailo(vector<Stud>& grupe);
int pasirinktiVeiksma();
void readString(string& str);
double skaiciuotiGalutini(const Stud& stud, char metodas);

#endif // FUNKCIJOS_H