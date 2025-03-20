#include "funkcijos.h"
#include "laikas.h"

template <typename Container>
double skaiciuotiVid(const Container& nd) 
{
    if (nd.empty()) 
    {
        throw std::runtime_error("Namu darbu sarasas negali buti tuscias");
    }
    else
    {
        double suma = 0.0;
        for (auto nd_elem : nd)  
        {
            suma += nd_elem;
        }
        return suma / nd.size();
    }
}
//---
template <typename Container>
double skaiciuotiMed(Container& nd)
{
    if (nd.empty())
     {
        throw std::runtime_error("Namu darbu sarasas negali buti tuscias");
    }
    else
    {
        vector<typename Container::value_type> sorted(nd.begin(), nd.end());
        std::sort(nd.begin(), nd.end());
    int dydis = nd.size();
    if (dydis % 2 == 0) 
    {
        return (nd[dydis / 2 - 1] + nd[dydis / 2]) / 2.0;
    } 
    else 
    {
        return nd[dydis / 2];
    }
   }  
}
//---
template <typename Container>
void skaitytiIsFailo(Container& grupe,const string& failoPavadinimas)
{
    Laikas failoNuskaitymas("Failo nuskaitymas");
    failoNuskaitymas.pradeti();
    std::ifstream inputFile(failoPavadinimas); 
    
    if (!inputFile.is_open()) 
    {
            throw std::runtime_error("Nepavyko atidaryti failo: " + failoPavadinimas);
    }
    Stud<Container> laik;
    string line;
    
    getline(inputFile, line);

    while (getline(inputFile, line)) 
    {
        std::stringstream ss(line);
ss >> laik.var >> laik.pav; 

laik.nd.clear();  
int pazymys;
Container scores;

while (ss >> pazymys) 
{

            if (pazymys >= 1 && pazymys <= 10)  
            {
                scores.push_back(pazymys);
            }
            else 
            {
                throw std::invalid_argument("Klaida: Netinkamas pazymys studentui " + laik.var + " " + laik.pav);
            }
}

if (ss.fail()&& !ss.eof()) 
            {
                throw std::invalid_argument("Klaida: Netinkamas pazymys (ne skaicius) studentui " + laik.var + " " + laik.pav);
            }
if (!scores.empty())
{
    laik.egz = scores.back();
    scores.pop_back();
    laik.nd = std::move(scores);
    grupe.push_back(laik);
}

    inputFile.close();
    failoNuskaitymas.baigti();
}
}

//---
template <typename Container>
double skaiciuotiGalutini(const Stud<Container>& stud, char metodas) 
{
    double galutinis = 0.0;
    if (tolower(metodas) == 'v') 
    {
        galutinis = 0.4 * skaiciuotiVid(stud.nd) + 0.6 * stud.egz;
    } else {
        galutinis = 0.4 * skaiciuotiMed(stud.nd) + 0.6 * stud.egz;
    }
    return galutinis;
}
//---