#include "strategija1.h"

template <typename Container>
void skirstytiStudentustrecias(Container& grupe, Container& kietiakiai, Container& vargsai) 
{
    auto it = std::partition(grupe.begin(), grupe.end(), [](const auto& a) { return a.galutinis >= 5.0; });

    // Kopijuojame duomenis į naujus konteinerius
    std::copy(grupe.begin(), it, std::back_inserter(kietiakiai));
    std::copy(it, grupe.end(), std::back_inserter(vargsai));

    grupe.clear();
}
//---
template <typename Container>
void testuotiDuomenuApdorojimatrecias(const std::string& aplankas, int skaicius)
{
    srand(time(0));
    Stud<Container> laik;

    Container grupe;
    Container kietiakiai;
    Container vargsai;

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

string failoPavadinimas=aplankas + "/studentai_" + std::to_string(skaicius) + ".txt";

Laikas nuskaitymas("Failo nuskaitymas");
nuskaitymas.pradeti();
skaitytiIsFailo(grupe, failoPavadinimas);   
nuskaitymas.baigti();

ats = tolower(ats);
if (ats == 'v' or ats == 'V') 
    {
        std::transform(std::execution::par, grupe.begin(), grupe.end(), grupe.begin(),
        [](auto a) {
            a.galutinis = 0.4 * skaiciuotiVid(a.nd) + 0.6 * a.egz;
            return a;
        });
        
    } else 
    {
        std::transform(std::execution::par, grupe.begin(), grupe.end(), grupe.begin(),
        [](auto a) {
            a.galutinis = 0.4 * skaiciuotiMed(a.nd) + 0.6 * a.egz;
            return a;
        });
    }

Laikas rikiavimas(std::to_string(skaicius) + " studentu failo rusiavimas didejimo tvarka");
rikiavimas.pradeti();
if (sortingOption == 'v' || sortingOption == 'V') 

{
    std::sort(std::execution::par, grupe.begin(), grupe.end(),
              [](const auto& a, const auto& b) { return a.var < b.var; });
} else if (sortingOption == 'p' || sortingOption == 'P') {
    std::sort(std::execution::par, grupe.begin(), grupe.end(),
              [](const auto& a, const auto& b) { return a.pav < b.pav; });
} else if (sortingOption == 'g' || sortingOption == 'G') {
    std::sort(std::execution::par, grupe.begin(), grupe.end(),
              [](const auto& a, const auto& b) { return a.galutinis > b.galutinis; });
}
rikiavimas.baigti();

Laikas skirstymas(std::to_string(skaicius)+" studentu failo skirstymas i du konteinerius");
    skirstymas.pradeti();
    skirstytiStudentustrecias(grupe, kietiakiai, vargsai);
    skirstymas.baigti();
    
isvestiStudentusIFaila(kietiakiai, "test_files/kietiakiai.txt", ats);

isvestiStudentusIFaila(vargsai, "test_files/vargsai.txt", ats);    

kietiakiai.clear();
vargsai.clear();

}
//---
template void testuotiDuomenuApdorojimatrecias<std::vector<Stud<std::vector<int>>>>(const std::string&, int);