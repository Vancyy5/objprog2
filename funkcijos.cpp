#include "funkcijos.h"
#include "laikas.h"

double skaiciuotiVid(vector<int> nd) 
{
    if (nd.empty()) 
    {
        throw std::runtime_error("Namu darbu sarasas negali buti tuscias");
    }
    else
    {
        double suma = 0.0;
        for (int nd : nd) 
        {
            suma += nd;
        }
    return suma*1.00/ nd.size();
    }
    
}
//---
double skaiciuotiMed(vector<int> nd) 
{
    if (nd.empty())
     {
        throw std::runtime_error("Namu darbu sarasas negali buti tuscias");
    }
    else
    {
        sort(nd.begin(), nd.end());
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
bool sortByName(const Stud& a, const Stud& b) 
{
    return a.var < b.var; 
}
//---
bool sortBySurname(const Stud& a, const Stud& b) 
{
    return a.pav < b.pav; 
}
//---
bool sortByFinalGradeAvg(const Stud& a, const Stud& b)
 {
    double finalA = 0.4 * skaiciuotiVid(a.nd) + 0.6 * a.egz;
    double finalB = 0.4 * skaiciuotiVid(b.nd) + 0.6 * b.egz;
    return finalA > finalB; 
}
//---
bool sortByFinalGradeMed(const Stud& a, const Stud& b) 
{
    double finalA = 0.4 * skaiciuotiMed(a.nd) + 0.6 * a.egz;
    double finalB = 0.4 * skaiciuotiMed(b.nd) + 0.6 * b.egz;
    return finalA > finalB;
}
//---
void skaitytiIsFailo(vector<Stud>& grupe,const string& failoPavadinimas)
{
    Laikas failoNuskaitymas("Failo nuskaitymas");
    failoNuskaitymas.pradeti();
    std::ifstream inputFile(failoPavadinimas); 
    
    if (!inputFile.is_open()) 
    {
        std::cerr << "Nepavyko atidaryti failo" << endl; exit(1);
    }
    Stud laik;
    string line;
    
    getline(inputFile, line);

    while (getline(inputFile, line)) 
    {
        std::stringstream ss(line);
ss >> laik.var >> laik.pav; 

laik.nd.clear();  
int pazymys;
vector<int> scores;  

while (ss >> pazymys) 
{

            if (pazymys >= 1 && pazymys <= 10)  
            {
                scores.push_back(pazymys);
            }
            else 
            {
                std::cerr << "Klaida: Netinkamas pazymys studentui " << laik.var << " " << laik.pav << ": " << pazymys <<  endl; exit(1);
            }
}

if (ss.fail()&& !ss.eof()) 
            {
                std::cerr << "Klaida: Netinkamas pazymys (ne skaicius) studentui " << laik.var << " " << laik.pav << endl; exit(1);
            }
if (scores.size() > 0)
{
    laik.nd = vector<int>(scores.begin(), scores.end() - 1);  
    
    laik.egz = scores.back();
    
    grupe.push_back(laik); 
    }
}
    inputFile.close();
    failoNuskaitymas.baigti();
}
//---
double skaiciuotiGalutini(const Stud& stud, char metodas) 
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