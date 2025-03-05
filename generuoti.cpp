#include "generuotif.h"

#include <filesystem>

namespace fs=std::filesystem;

void generuotiFaila(int skaicius, const string& aplankas) 
{
    if (!fs::exists(aplankas)) 
    {
        fs::create_directory(aplankas);
    }

    string failoPavadinimas=aplankas + "/studentai_" + std::to_string(skaicius) + ".txt";
    std::ofstream outFile(failoPavadinimas);
    
    if (!outFile.is_open()) 
    {
        std::cerr << "Klaida: nepavyko sukurti failo " << failoPavadinimas << endl;
        return;
    }

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> pazymysDist(1, 10); 
    std::uniform_int_distribution<int> pazymiuskaicius(5, 20); 
    std::uniform_int_distribution<int> vardasNrDist(1, 10000); 

    int pazymiaisk=pazymiuskaicius(mt);

    outFile << std::left << setw(15) << "Vardas" << setw(15) << "Pavarde";
    for (int i = 0; i < pazymiaisk; ++i) 
    {
        outFile << "ND" << i << " ";
    }
    outFile << "Egz." << endl;

    for (int i = 1; i <= skaicius; ++i) 
    {
        outFile << std::left << setw(15) << "Vardas" + std::to_string(i) << setw(15) << "Pavarde" + std::to_string(i);

        for (int j = 0; j < pazymiaisk; ++j) 
        {
            outFile << setw(3) << pazymysDist(mt);
        }
        outFile << setw(3) << pazymysDist(mt) << endl; 
    }

    outFile.close();
    cout << "Failas " << failoPavadinimas << " su " << skaicius << " irasais sukurtas sekmingai" << endl;
}