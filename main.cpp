#include "funkcijos.h"
#include "laikas.h"
#include "skirstymas.h"
//---
int main() 
{
    try 
    {
        string aplankas="test_files";

        int skaicius;
        int pasirinktasDydis;

    cout << "Pasirinkite failo dydi testavimui:\n";
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
    
cout << "Koki konteineri norite naudoti? (vector - 'v'/ list - 'l' / deque - 'd')" ;
char konteineris;
cin>>konteineris;
while (konteineris != 'v' && konteineris != 'V' && konteineris != 'l' && konteineris != 'L' && konteineris != 'd' && konteineris != 'D') 
{
cout << "Netinkama ivestis. Bandykite dar karta: ";
cin >> konteineris;
}

if (konteineris == 'v' || konteineris == 'V') 
        {
            using ContainerType = vector<Stud<vector<int>>>;
            testuotiDuomenuApdorojima<ContainerType>(aplankas, skaicius, konteineris);
        } 
        else if (konteineris == 'l' || konteineris == 'L') 
        {
            using ContainerType = list<Stud<list<int>>>;
            testuotiDuomenuApdorojima<ContainerType>(aplankas, skaicius, konteineris);
        } 
        else if (konteineris == 'd' || konteineris == 'D') 
        {
            using ContainerType = deque<Stud<deque<int>>>;
            testuotiDuomenuApdorojima<ContainerType>(aplankas, skaicius, konteineris);
        }

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
