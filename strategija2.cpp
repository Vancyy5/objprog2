#include "strategija2.h"

template <typename Container>
void skirstytiStudentusantras(Container& grupe, Container& vargsai) 
{
    for (auto it = grupe.begin(); it != grupe.end(); ) 
    {
        if (it->galutinis >= 5.0) 
        {
            ++it; 
        } else
        {

            vargsai.push_back(*it);
            it = grupe.erase(it);  
        }
    }
}
//---
template <typename Container>
void testuotiDuomenuApdorojimaantras(const std::string& aplankas, int skaicius, const char& konteineris)
{
    srand(time(0));
    Stud<Container> laik;

    Container grupe;
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
    skirstytiStudentusantras(grupe, vargsai);
    skirstymas.baigti();
    
isvestiStudentusIFaila(grupe, "test_files/kietiakiai.txt", ats);

isvestiStudentusIFaila(vargsai, "test_files/vargsai.txt", ats);    

vargsai.clear();
}
//---
template void testuotiDuomenuApdorojimaantras<std::vector<Stud<std::vector<int>>>>(const std::string&, int, const char&);
template void testuotiDuomenuApdorojimaantras<std::list<Stud<std::list<int>>>>(const std::string&, int, const char&);
template void testuotiDuomenuApdorojimaantras<std::deque<Stud<std::deque<int>>>>(const std::string&, int, const char&);
//---