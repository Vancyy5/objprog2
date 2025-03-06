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

    for (const auto& a : studentai)
     {
        double galutinis = skaiciuotiGalutini(a, ats);
        outFile << std::left << setw(15) << a.var << setw(15) << a.pav << std::fixed << std::setprecision(2) << galutinis << std::endl;
    }
}
//---
void testuotiDuomenuApdorojimas(const string& aplankas, int skaicius)
{
    srand(time(0));
    Stud laik;
    vector<Stud> grupe;

    cout << "Ar galutinio balo skaiciavimui norite naudoti vidurki ar mediana? (v/m): ";
char ats;
cin >> ats;

while (ats != 'v' && ats != 'V' && ats != 'm' && ats != 'M') 
{
    cout << "Netinkama ivestis. Bandykite dar karta: ";
    cin >> ats;
}

cout << "Kaip norite surusiuoti studentus? (v/vardas, p/pavarde, g/galutinis): ";
char sortingOption;
cin >> sortingOption;
while (sortingOption != 'v' && sortingOption != 'V' && sortingOption != 'p' && sortingOption != 'P' && sortingOption != 'g') {
    cout << "Netinkama ivestis. Bandykite dar karta: ";
    cin >> sortingOption;
}

Laikas programa("Bendras programos vykdymas");
programa.pradeti();
string failoPavadinimas=aplankas + "/studentai_" + std::to_string(skaicius) + ".txt";
skaitytiIsFailo(grupe, failoPavadinimas);   

if (sortingOption == 'v' || sortingOption == 'V') 
{
    Laikas rikiavimas(std::to_string(skaicius)+" studentu failo rikiavimas pagal vardus abeceliskai");
rikiavimas.pradeti();
sort(grupe.begin(), grupe.end(), sortByName);
rikiavimas.baigti();

} else if (sortingOption == 'p' || sortingOption == 'P') 
{
    Laikas rikiavimas(std::to_string(skaicius)+" studentu failo rikiavimas pagal pavardes abeceliskai");
rikiavimas.pradeti();
sort(grupe.begin(), grupe.end(), sortBySurname);
rikiavimas.baigti();
} else if (sortingOption == 'g') {
    if (ats == 'v' || ats == 'V') 
    {
        Laikas rikiavimas(std::to_string(skaicius)+" studentu failo rikiavimas mazejimo tvarka pagal vidurki");
rikiavimas.pradeti();
sort(grupe.begin(), grupe.end(), sortByFinalGradeAvg);
rikiavimas.baigti();
    } else 
    {
        Laikas rikiavimas(std::to_string(skaicius)+" studentu failo rikiavimas mazejimo tvarka pagal mediana");
rikiavimas.pradeti();
sort(grupe.begin(), grupe.end(), sortByFinalGradeMed);
rikiavimas.baigti();
    }
}

vector<Stud> kietiakiai;
vector<Stud> vargsai;

Laikas skirstymas(std::to_string(skaicius)+" studentu failo skirstymas i du konteinerius, panaikinant vector");
    skirstymas.pradeti();
    skirstytiStudentus(grupe, kietiakiai, vargsai, ats);
    skirstymas.baigti();
    
    
        Laikas rezultatuIsvedimaskietekai("Kieteku rezultatu isvedimas");
        rezultatuIsvedimaskietekai.pradeti();
        isvestiStudentusIFaila(kietiakiai, "test_files/kietiakiai.txt", ats);
        rezultatuIsvedimaskietekai.baigti();
    
        Laikas rezultatuIsvedimasvargsai("Vargsu rezultatu isvedimas");
        rezultatuIsvedimasvargsai.pradeti();
        isvestiStudentusIFaila(vargsai, "test_files/vargsai.txt", ats);        
        rezultatuIsvedimasvargsai.baigti();

programa.baigti();
}