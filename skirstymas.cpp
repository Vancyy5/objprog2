#include "skirstymas.h"

void skirstytiStudentus(const vector<Stud>& grupe, vector<Stud>& kietiakiai, vector<Stud>& vargsai, char ats) 
{
    for (const auto& a : grupe) 
    {
        double galutinis = skaiciuotiGalutini(a, ats);
        if (galutinis >= 5.0) {
            kietiakiai.push_back(a);
        } else {
            vargsai.push_back(a);
        }
    }
}