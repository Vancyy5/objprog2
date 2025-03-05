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

        cout << "Pasirinkite failo dydį:\n";
    cout << "1 - 1000 studentu\n";
    cout << "2 - 10000 studentu\n";
    cout << "3 - 100000 studentu\n";
    cout << "4 - 1000000 studentu\n";
    cout << "5 - 10000000 studentu\n";
    cout << "6 - Negeneruoti failo\n";
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
        Laikas laikoMatavimasGeneravimas("Failo kurimas");
    laikoMatavimasGeneravimas.pradeti();
    generuotiFaila(skaicius, aplankas,failoPavadinimas); 
    laikoMatavimasGeneravimas.baigti();
    }

    srand(time(0));
    Stud laik;
    vector<Stud> grupe;
    int pasirinkimas;

    char testiStudentus, testiNd, generuoti;

    Laikas programa("Bendras programos vykdymas");
    programa.pradeti();

    cout << "Ar norite nuskaityti studentu duomenis is failo? (t/n): ";
    char readFromFile;
    cin >> readFromFile;

    while (readFromFile != 't' && readFromFile != 'T' && readFromFile != 'n' && readFromFile != 'N') 
{
    cout << "Netinkama ivestis. Bandykite dar karta: ";
    cin >> readFromFile;
}

    if (readFromFile == 't'  || readFromFile == 'T') 
   {
    skaitytiIsFailo(grupe, failoPavadinimas);
   }
        else if (readFromFile == 'n' || readFromFile == 'N')
    {
        int pasirinkimas;
        int i=0;
        pasirinkimas=pasirinktiVeiksma();

    if (pasirinkimas!=4)
    {
        if(pasirinkimas==1)
        {
          int i=0;
          do
          {
            i++;
            cout << "Iveskite "<< i << "-ojo studento varda: ";
            readString(laik.var);
            cout << "Iveskite "<< i << "-ojo studento pavarde: ";
            readString(laik.pav);
    
            laik.nd.clear();
            int j=0;
            do 
            {
            int paz;
            j++;
            cout << "Iveskite "<< i << "-ojo studento "<< j << "-ojo namu darbo rezultata: ";
            paz=readInteger();
            laik.nd.push_back(paz);

            cout << "Ar norite ivesti dar viena namu darba? (t/n): ";
            cin >> testiNd;
            while (testiNd != 't' && testiNd != 'T' && testiNd != 'n' && testiNd != 'N') 
            {
                cout << "Netinkama ivestis. Bandykite dar karta: ";
                cin >> testiNd;
            }
            } while (testiNd == 't' || testiNd == 'T');
            
           cout << "Iveskite "<< i << "-ojo studento egzamino rezultata: ";
           laik.egz=readInteger();

          grupe.push_back(laik);
          laik.nd.clear();
       
        cout << "Ar norite ivesti dar viena studenta? (t/n): ";
        cin >> testiStudentus;
        while (testiStudentus != 't' && testiStudentus != 'T' && testiStudentus != 'n' && testiStudentus != 'N') 
        {
            cout << "Netinkama ivestis. Bandykite dar karta: ";
            cin >> testiStudentus;
        }
        } while (testiStudentus == 't' || testiStudentus == 'T');
       }

       else if (pasirinkimas==2)
       {
        do{
            i++;
        cout << "Iveskite "<< i << "-ojo studento varda: ";
        readString(laik.var);
        cout << "Iveskite "<< i << "-ojo studento pavarde: ";
        readString(laik.pav);

        laik.nd.clear();

        int kiekis = generuotiAtsitiktiniP();

          for (int j = 0; j < kiekis; ++j) 
          {
          int paz = generuotiAtsitiktiniP();
           laik.nd.push_back(paz);
          }

           laik.egz = generuotiAtsitiktiniP();

           grupe.push_back(laik);
           laik.nd.clear();
           
            cout << "Ar norite ivesti dar viena studenta? (t/n): ";
            cin >> testiStudentus;
            while (testiStudentus != 't' && testiStudentus != 'T' && testiStudentus != 'n' && testiStudentus != 'N') 
            {
                cout << "Netinkama ivestis. Bandykite dar karta: ";
                cin >> testiStudentus;
            }
        }while (testiStudentus == 't' || testiStudentus == 'T');

       }
       else if (pasirinkimas==3)
       {
        do
        {
        bool berniukas = rand() % 2 == 0;
        laik.var = generuotiVarda(berniukas);
        laik.pav = generuotiPavarde(berniukas);

        laik.nd.clear();

        int kiekis = generuotiAtsitiktiniP();

          for (int j = 0; j < kiekis; ++j) 
          {
          int paz = generuotiAtsitiktiniP();
           laik.nd.push_back(paz);
          }

           laik.egz = generuotiAtsitiktiniP();

           grupe.push_back(laik);
           laik.nd.clear();

        cout << "Ar sugeneruoti dar viena studenta? (t/n): ";
        cin >> testiStudentus;
        while (testiStudentus != 't' && testiStudentus != 'T' && testiStudentus != 'n' && testiStudentus != 'N') 
        {
            cout << "Netinkama ivestis. Bandykite dar karta: ";
            cin >> testiStudentus;
        }
       }while(testiStudentus == 't' || testiStudentus == 'T');
       }
    }
    else if(pasirinkimas==4)
        {
        cout << "Pasirinkta baigti darba" <<endl;
        return 1;
        }
}
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

if (sortingOption == 'v' || sortingOption == 'V') {
    sort(grupe.begin(), grupe.end(), sortByName);
} else if (sortingOption == 'p' || sortingOption == 'P') {
    sort(grupe.begin(), grupe.end(), sortBySurname);
} else if (sortingOption == 'g') {
    if (ats == 'v' || ats == 'V') 
    {
        sort(grupe.begin(), grupe.end(), sortByFinalGradeAvg);
    } else 
    {
        sort(grupe.begin(), grupe.end(), sortByFinalGradeMed);
    }
}
vector<Stud> kietiakiai;
vector<Stud> vargsai;
skirstytiStudentus(grupe, kietiakiai, vargsai, ats);

isvestiStudentusIFaila(kietiakiai, "test_files/kietiakiai.txt", ats);
isvestiStudentusIFaila(vargsai, "test_files/vargsai.txt", ats);

cout << "Ar norite atspausdinti studentu duomenis i faila ar i ekrana? (f/e): ";
char spausdinti;
cin >> spausdinti;
while (spausdinti != 'f' && spausdinti != 'F' && spausdinti != 'e' && spausdinti != 'E') 
{
    cout << "Netinkama ivestis. Bandykite dar karta: ";
    cin >> spausdinti;
}

    Laikas rezultatuIsvedimas("Rezultatu isvedimas");
    rezultatuIsvedimas.pradeti();

    if (spausdinti == 'f' || spausdinti == 'F') 
    {
        std::ofstream outputFile("rezultatai.txt"); 
        if (!outputFile.is_open()) 
        {
            cout << "Nepavyko sukurti failo" << endl;
            return 1;
        }
        outputFile<< std::left << setw(15) << "Vardas" << setw(15) << "Pavarde";
        if (ats=='v' || ats == 'V') 
        { 
            outputFile<< std::left << setw(20) << "Galutinis (Vid.)" << endl;
        }
        else if (ats == 'm' || ats == 'M') 
        {
            outputFile<< std::left  << setw(20) << "Galutinis (Med.)" << endl;
        }
        outputFile << string(50, '-') << endl; 
        for (const auto &a : grupe) 
        {
            double galutinis = skaiciuotiGalutini(a, ats);
            outputFile << std::left << setw(15) << a.var << setw(15) << a.pav << std::fixed << std::setprecision(2) << galutinis << endl;
        }
    }
    
    else if (spausdinti == 'e' || spausdinti == 'E')
    {
        cout<< std::left << setw(15) << "Vardas" << setw(15) << "Pavarde" ;
        if (ats=='v' || ats == 'V') 
        { 
            cout<< std::left << "Galutinis (Vid.)" << endl;
        }
        else if (ats == 'm' || ats == 'M') 
        {
            cout << std::left << setw(20) << "Galutinis (Med.)" << endl;
        }
        cout << string(50, '-') << endl; 
        double galutinis = 0.0;
    for (const auto &a : grupe) 
    {
        double galutinis = skaiciuotiGalutini(a, ats);
        cout << std::left << setw(15) << a.var << setw(15) << a.pav << std::fixed << std::setprecision(2) << galutinis << endl;
    }
}
    rezultatuIsvedimas.baigti();
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
