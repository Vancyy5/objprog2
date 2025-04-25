#include "funkcijos.h"
#include "laikas.h"
#include "zmogus.h"
//---
int main() 
{
    try {
        
        char testChoice;
        std::cout << "Ar norite vykdyti Studentas klases metodu testa? (t/n): ";
        std::cin >> testChoice;

        if (tolower(testChoice) == 't') 
        {
            testuotiStudentoMetodus();
            return 0;
        }
        
        std::string aplankas = "test_files";
        int skaicius;
        int pasirinktasDydis;

        std::cout << "Pasirinkite failo dydi testavimui:\n";
        std::cout << "1 - 1000 studentu\n";
        std::cout << "2 - 10000 studentu\n";
        std::cout << "3 - 100000 studentu\n";
        std::cout << "4 - 1000000 studentu\n";
        std::cout << "5 - 10000000 studentu\n";
        std::cout << "Kitas- programos pabaiga\n";
        std::cout << "Pasirinkimas: ";
        std::cin >> pasirinktasDydis;

        switch (pasirinktasDydis) {
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
                std::cout << "Neteisingas pasirinkimas" << std::endl;
                return 1;
        }
        
        testuotiDuomenuApdorojima(aplankas, skaicius);
        
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Ivyko klaida: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Nezinoma klaida." << std::endl;
        return 1;
    }

    return 0;
}