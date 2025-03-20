#include "skirstymas.h"

template <typename Container>
void skirstytiStudentus(Container& grupe, Container& kietiakiai, Container& vargsai, char ats) 
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
template <typename Container>
void isvestiStudentusIFaila(const Container& studentai, const std::string& failoPavadinimas, char ats)
{
    std::ofstream outFile(failoPavadinimas);
    if (!outFile.is_open()) {
        throw std::runtime_error("Nepavyko atidaryti failo: " + failoPavadinimas);
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
template <typename Container>
void testuotiDuomenuApdorojima(const std::string& aplankas, int skaicius, const char& konteineris)
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

Laikas programa("Bendras programos vykdymas");
programa.pradeti();
string failoPavadinimas=aplankas + "/studentai_" + std::to_string(skaicius) + ".txt";
skaitytiIsFailo(grupe, failoPavadinimas);   

Laikas rikiavimas(std::to_string(skaicius) + " studentų failo rūšiavimas");
rikiavimas.pradeti();

sortByChoice(grupe, ats, sortingOption);
rikiavimas.baigti();

Laikas skirstymas(std::to_string(skaicius)+" studentu failo skirstymas i du konteinerius");
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
//---
template void testuotiDuomenuApdorojima<std::vector<Stud<std::vector<int>>>>(const std::string&, int, const char&);
template void testuotiDuomenuApdorojima<std::list<Stud<std::list<int>>>>(const std::string&, int, const char&);
template void testuotiDuomenuApdorojima<std::deque<Stud<std::deque<int>>>>(const std::string&, int, const char&);
//---
template <typename Container>
void sortByChoice(Container& grupe, char ats, char sortingOption) {
    if (sortingOption == 'v' || sortingOption == 'V') {
        if constexpr (std::is_same_v<Container, std::list<typename Container::value_type>>) {
            grupe.sort(sortByName<typename Container::value_type>);
        } else {
            std::sort(grupe.begin(), grupe.end(), sortByName<typename Container::value_type>);
        }
    } else if (sortingOption == 'p' || sortingOption == 'P') {
        if constexpr (std::is_same_v<Container, std::list<typename Container::value_type>>) {
            grupe.sort(sortBySurname<typename Container::value_type>);
        } else {
            std::sort(grupe.begin(), grupe.end(), sortBySurname<typename Container::value_type>);
        }
    } else if (sortingOption == 'g') {
        if (ats == 'v' || ats == 'V') {
            if constexpr (std::is_same_v<Container, std::list<typename Container::value_type>>) {
                grupe.sort(sortByFinalGradeAvg<typename Container::value_type>);
            } else {
                std::sort(grupe.begin(), grupe.end(), sortByFinalGradeAvg<typename Container::value_type>);
            }
        } else {
            if constexpr (std::is_same_v<Container, std::list<typename Container::value_type>>) {
                grupe.sort(sortByFinalGradeMed<typename Container::value_type>);
            } else {
                std::sort(grupe.begin(), grupe.end(), sortByFinalGradeMed<typename Container::value_type>);
            }
        }
    }
}
//---