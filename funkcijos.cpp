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
int readInteger() 
{
    int value;
    while (true) {
        cin >> value;
        if (cin.fail()  || value < 1 || value > 10) 
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: " << endl;
        }
        else 
        {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return value;
}
//---
int generuotiAtsitiktiniP(int min, int max) 
{
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}
//---
string generuotiVarda(bool berniukas) 
{
    vector<string> berniukuVardai = {"Jokubas", "Jonas", "Petras", "Lukas", "Mantas", "Tomas"};
    vector<string> mergaiciuVardai = {"Simona", "Vakare", "Greta", "Laura", "Egle"};

    if (berniukas) {
        return berniukuVardai[rand() % berniukuVardai.size()];
    } else {
        return mergaiciuVardai[rand() % mergaiciuVardai.size()];
    }
}
//---
string generuotiPavarde(bool berniukas) 
{
    vector<string> berniukuPavardes = {"Jonaitis", "Petraitis", "Lukaitis", "Mantaitis", "Tomaitis"};
    vector<string> mergaiciuPavardes = {"Jonaite", "Petraite", "Lukaite", "Mantaite", "Tomaite"};

    if (berniukas) {
        return berniukuPavardes[rand() % berniukuPavardes.size()];
    } else {
        return mergaiciuPavardes[rand() % mergaiciuPavardes.size()];
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
void skaitytiIsFailo(vector<Stud>& grupe)
{
    Laikas failoNuskaitymas("Failo nuskaitymas");
    failoNuskaitymas.pradeti();
    std::ifstream inputFile("kursiokai.txt"); 
    
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
int pasirinktiVeiksma() {
    int pasirinkimas;
    while (true) {
        cout << "Pasirinkite veiksma:\n";
        cout << "1 - Ivesti duomenis ranka\n";
        cout << "2 - Generuoti tik pazymius\n";
        cout << "3 - Generuoti vardus, pavardes ir pazymius\n";
        cout << "4 - Baigti darba\n";
        cout << "Pasirinkimas: ";
        try {
            cin >> pasirinkimas;
            if (cin.fail() || (pasirinkimas < 1 || pasirinkimas > 4)) {
                throw std::runtime_error("Neteisingai pasirinktas meniu variantas.");
            }
            break;
        } catch (const std::runtime_error& e) 
        {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return pasirinkimas;
}
//---
void readString(string& str) 
{
    while (true) {
        cin >> str;
        if (str.empty() || str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos) {
            cout << "Klaida! Vardas arba pavarde turi buti tik raides: ";
        } else {
            break;
        }
    }
}
//---
double skaiciuotiGalutini(const Stud& stud, char metodas) {
    double galutinis = 0.0;
    if (tolower(metodas) == 'v') {
        galutinis = 0.4 * skaiciuotiVid(stud.nd) + 0.6 * stud.egz;
    } else {
        galutinis = 0.4 * skaiciuotiMed(stud.nd) + 0.6 * stud.egz;
    }
    return galutinis;
}
//---