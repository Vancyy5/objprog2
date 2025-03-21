#include "funkcijos.h"
#include "laikas.h"
#include "strategija1.h"
#include "strategija2.h"
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

cout << "Kuria strategija norite naudoti? (1/2/3)" ;
char strategija;
cin>>strategija;
while (strategija != '1' && strategija != '2' && strategija != '3') 
{
cout << "Netinkama ivestis. Bandykite dar karta: ";
cin >> strategija;
}

if(strategija == '1')
{
    if (konteineris == 'v' || konteineris == 'V') 
    {
        testuotiDuomenuApdorojimapirma<vector<Stud<vector<int>>>>(aplankas, skaicius, konteineris);
    } 
    else if (konteineris == 'l' || konteineris == 'L') 
    {
        testuotiDuomenuApdorojimapirma<list<Stud<list<int>>>>(aplankas, skaicius, konteineris);
    } 
    else if (konteineris == 'd' || konteineris == 'D') 
    {
        testuotiDuomenuApdorojimapirma<deque<Stud<deque<int>>>>(aplankas, skaicius, konteineris);
    } 

}
    else if(strategija == '2')
    {
        if (konteineris == 'v' || konteineris == 'V') 
        {
            testuotiDuomenuApdorojimaantras<vector<Stud<vector<int>>>>(aplankas, skaicius, konteineris);
        } 
        else if (konteineris == 'l' || konteineris == 'L') 
        {
            testuotiDuomenuApdorojimaantras<list<Stud<list<int>>>>(aplankas, skaicius, konteineris);
        } 
        else if (konteineris == 'd' || konteineris == 'D') 
        {
            testuotiDuomenuApdorojimaantras<deque<Stud<deque<int>>>>(aplankas, skaicius, konteineris);
        } 
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
