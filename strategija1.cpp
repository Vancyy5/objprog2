#include "strategija1.h"

template <typename Container>
void skirstytiStudentus(Container& grupe, Container& kietiakiai, Container& vargsai) 
{
    
    for (const auto& a : grupe) 
    {
        if (a.galutinis >= 5.0) {
            kietiakiai.push_back(a);
        } else {
            vargsai.push_back(a);
        }
    }
    grupe.clear();
}
//---
template <typename Container>
void testuotiDuomenuApdorojimapirma(const std::string& aplankas, int skaicius, const char& konteineris)
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
        for (auto& a : grupe) 
        {
            a.galutinis = 0.4 * skaiciuotiVid(a.nd) + 0.6 * a.egz;
        }
        
    } else 
    {
        for (auto& a : grupe) 
        {
        a.galutinis = 0.4 * skaiciuotiMed(a.nd) + 0.6 * a.egz;
        }
    }

Laikas rikiavimas(std::to_string(skaicius) + " studentu failo rusiavimas didejimo tvarka");
rikiavimas.pradeti();
sortByChoice(grupe, sortingOption);
rikiavimas.baigti();

Laikas skirstymas(std::to_string(skaicius)+" studentu failo skirstymas i du konteinerius");
    skirstymas.pradeti();
    skirstytiStudentus(grupe, kietiakiai, vargsai);
    skirstymas.baigti();
    
isvestiStudentusIFaila(kietiakiai, "test_files/kietiakiai.txt", ats);

isvestiStudentusIFaila(vargsai, "test_files/vargsai.txt", ats);    

kietiakiai.clear();
vargsai.clear();

}
//---
template void testuotiDuomenuApdorojimapirma<std::vector<Stud<std::vector<int>>>>(const std::string&, int, const char&);
template void testuotiDuomenuApdorojimapirma<std::list<Stud<std::list<int>>>>(const std::string&, int, const char&);
template void testuotiDuomenuApdorojimapirma<std::deque<Stud<std::deque<int>>>>(const std::string&, int, const char&);
//---
template <typename Container>
void sortByChoice(Container& grupe, char sortingOption) 
{
    if constexpr (std::is_same_v<Container, std::list<typename Container::value_type>>) 
    { 
        if (sortingOption == 'v' || sortingOption == 'V') {
            grupe.sort([](const auto& a, const auto& b) { return a.var < b.var; }); 
        } else if (sortingOption == 'p' || sortingOption == 'P') {
            grupe.sort([](const auto& a, const auto& b) { return a.pav < b.pav; });
        } else if (sortingOption == 'g' || sortingOption == 'G') {
            grupe.sort([](const auto& a, const auto& b) { return a.galutinis > b.galutinis; });
        }
    }
    else 
    {
        if (sortingOption == 'v' || sortingOption == 'V') {
            std::sort(std::execution::par, grupe.begin(), grupe.end(),
                      [](const auto& a, const auto& b) { return a.var < b.var; });
        } else if (sortingOption == 'p' || sortingOption == 'P') {
            std::sort(std::execution::par, grupe.begin(), grupe.end(),
                      [](const auto& a, const auto& b) { return a.pav < b.pav; });
        } else if (sortingOption == 'g' || sortingOption == 'G') {
            std::sort(std::execution::par, grupe.begin(), grupe.end(),
                      [](const auto& a, const auto& b) { return a.galutinis > b.galutinis; });
        }
    }
}

//---