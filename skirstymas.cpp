#include "skirstymas.h"

void skirstytiStudentus(vector<Stud>& grupe, vector<Stud>& kietiakiai, vector<Stud>& vargsai, char ats) 
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
    grupe.clear();
}
//---
void isvestiStudentusIFaila(const vector<Stud>& studentai, const string& failoPavadinimas, char ats) 
{
    std::ofstream outFile(failoPavadinimas);
    if (!outFile.is_open()) {
        std::cerr << "Nepavyko atidaryti failo: " << failoPavadinimas << std::endl;
        return;
    }
    outFile << std::left << setw(15) << "Vardas" << setw(15) << "Pavarde";
    if (ats == 'v' || ats == 'V') {
        outFile << std::left << "Galutinis (Vid.)" << std::endl;
    } else if (ats == 'm' || ats == 'M') {
        outFile << std::left << "Galutinis (Med.)" << std::endl;
    }
    outFile << string(50, '-') << std::endl;

    for (const auto& a : studentai) {
        double galutinis = skaiciuotiGalutini(a, ats);
        outFile << std::left << setw(15) << a.var << setw(15) << a.pav << std::fixed << std::setprecision(2) << galutinis << std::endl;
    }
}