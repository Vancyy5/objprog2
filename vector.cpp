#include "funkcijos.h"
#include "laikas.h"

//---
int main() 
{
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
    skaitytiIsFailo(grupe);
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
            if (testiStudentus == 'n' || testiStudentus == 'N') break;
        else if (testiStudentus != 't' && testiStudentus != 'T')
        {
            cout << "Blogai atsakytas apie studentu ivedima" << endl;
            return 1;
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
        if (testiStudentus == 'n' || testiStudentus == 'N') break;
        else if (testiStudentus != 't' && testiStudentus != 'T')
        {
            cout << "Blogai atsakytas klausimas apie studentu generavima" << endl;
            return 1;
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
        if (ats=='v' || ats == 'V') 
        { 
            outputFile<< std::left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << endl;
        }
        else if (ats == 'm' || ats == 'M') 
        {
            outputFile<< std::left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Med.)" << endl;
        }
        outputFile << string(50, '-') << endl; 
        for (const auto &a : grupe) 
        {
            double galutinis = 0.0;
            if (ats=='v' || ats == 'V') 
            { 
                galutinis = 0.4 * skaiciuotiVid(a.nd) + 0.6 * a.egz;
            }
            else if (ats == 'm' || ats == 'M') 
            {
                galutinis = 0.4 * skaiciuotiMed(a.nd) + 0.6 * a.egz;
            }
            outputFile << std::left << setw(15) << a.var << setw(15) << a.pav << std::fixed << std::setprecision(2) << galutinis << endl;
        }
    }
    
    else if (spausdinti == 'e' || spausdinti == 'E')
    {
        if (ats=='v' || ats == 'V') 
        { 
            cout<< std::left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << endl;
        }
        else if (ats == 'm' || ats == 'M') 
        {
            cout<< std::left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Med.)" << endl;
        }
        cout << string(50, '-') << endl; 
        double galutinis = 0.0;
    for (const auto &a : grupe) 
    {
        if (ats=='v' || ats == 'V') 
        { 
            galutinis = 0.4 * skaiciuotiVid(a.nd) + 0.6 * a.egz;
        }
        else if (ats == 'm' || ats == 'M') 
        {
            galutinis = 0.4 * skaiciuotiMed(a.nd) + 0.6 * a.egz;
        }

        cout << std::left << setw(15) << a.var << setw(15) << a.pav << std::fixed << std::setprecision(2) << galutinis << endl;
    }
}
    rezultatuIsvedimas.baigti();
    programa.baigti(); 
    return 0;
    
}
//---
