#include "funkcijos.h"
#include "laikas.h"
#include "generuotif.h"
#include "skirstymas.h"
//---
int main() 
{
    try 
    {
        Laikas programa("Bendras programos vykdymas");
        programa.pradeti();

        string aplankas="test_files";
        string failoPavadinimas="kursiokai.txt"; 

        int skaicius;
        int pasirinktasDydis;

    cout << "Pasirinkite generacijai failo dydi:\n";
    cout << "1 - 1000 studentu\n";
    cout << "2 - 10000 studentu\n";
    cout << "3 - 100000 studentu\n";
    cout << "4 - 1000000 studentu\n";
    cout << "5 - 10000000 studentu\n";
    cout << "6 - Negeneruoti failo, naudoti sukurta faila\n";
    cout << "Pasirinkimas: ";
    cin >> pasirinktasDydis;

    switch (pasirinktasDydis) 
    {
        case 1:
            skaicius = 1000;
            break;
        case 2:
            skaicius = 10000;
            break;
        case 3:
            skaicius = 100000;
            break;
        case 4:
            skaicius = 1000000;
            break;
        case 5:
            skaicius = 10000000;
            break;
        case 6:
           cout<< "Pasirinkta failo negeneruoti"<<endl;
           skaicius = 0;
           break;
        default:
           cout<< "Neteisingas pasirinkimas"<<endl;
           return 1;
    }
    
    if (skaicius > 0) 
    {  
    Laikas laikoMatavimasGeneravimas("Failo kurimas su " + std::to_string(skaicius) + " studentais");
    laikoMatavimasGeneravimas.pradeti();
    generuotiFaila(skaicius, aplankas,failoPavadinimas); 
    laikoMatavimasGeneravimas.baigti();
    }

    /*srand(time(0));
    Stud laik;
    vector<Stud> grupe;
    int pasirinkimas;

    char testiStudentus, testiNd, generuoti;
    
    skaitytiIsFailo(grupe, failoPavadinimas);   


char ats ='v';
Laikas rikiavimas(std::to_string(skaicius)+" studentu failo rikiavimas mazejimo tvarka pagal vidurki");
rikiavimas.pradeti();
sort(grupe.begin(), grupe.end(), sortByFinalGradeAvg);
rikiavimas.baigti();

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
*/
programa.baigti();
return 0;
}
catch (const std::exception& e) 
    {
        std::cerr << "Ivyko klaida: " << e.what() << endl;
        return 1;
    }
    catch (...) 
    {
        std::cerr << "Nezinoma klaida." << endl;
        return 1;
    }

    return 0;
} 
//---
