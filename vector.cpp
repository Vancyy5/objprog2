#include "funkcijos.h"
#include "laikas.h"
#include "generuotif.h"
#include "skirstymas.h"
//---
int main() 
{
    try 
    {
        string aplankas="test_files";
        string failoPavadinimas="kursiokai.txt"; 

        int skaicius;
        int pasirinktasDydis;

    cout << "Pasirinkite failo dydi:\n";
    cout << "1 - 1000 studentu\n";
    cout << "2 - 10000 studentu\n";
    cout << "3 - 100000 studentu\n";
    cout << "4 - 1000000 studentu\n";
    cout << "5 - 10000000 studentu\n";
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
        default:
           cout<< "Neteisingas pasirinkimas"<<endl;
           return 1;
    }
    
    cout << "Ar norite generuoti nauja faila? (t/n)" ;
    char atts;
    cin>>atts;
    while (atts != 't' && atts != 'T' && atts != 'n' && atts != 'N') 
{
    cout << "Netinkama ivestis. Bandykite dar karta: ";
    cin >> atts;
}
    if(atts == 'T' or atts == 't') generuotiFaila(skaicius, aplankas); 

    else testuotiDuomenuApdorojimas(aplankas,skaicius);

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
