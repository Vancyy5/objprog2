#include "funkcijos.h"
//---
int main() 
{
    srand(time(0));
    Stud laik;
    vector<Stud> grupe;
    int pasirinkimas;

    char testiStudentus, testiNd, generuoti;

    int i=0;
        cout << "Pasirinkite veiksma:\n";
        cout << "1 - Ivesti duomenis ranka\n";
        cout << "2 - Generuoti tik pazymius\n";
        cout << "3 - Generuoti vardus, pavardes ir pazymius\n";
        cout << "4 - Baigti darba\n";
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;

    if (pasirinkimas!=4)
    {
        if(pasirinkimas==1)
        {
          int i=0;
          do
          {
            i++;
            cout << "Iveskite "<< i << "-ojo studento varda: ";
            cin >> laik.var;
            cout << "Iveskite "<< i << "-ojo studento pavarde: ";
            cin >> laik.pav;
    
            laik.nd.clear();
            int j=0;
            do 
            {

            int paz;
            j++;
            cout << "Iveskite "<< i << "-ojo studento "<< j << "-ojo namu darbo rezultata: ";
            cin >> paz;
            laik.nd.push_back(paz);

            cout << "Ar norite ivesti dar viena namu darba? (t/n): ";
            cin >> testiNd;
            } while (testiNd == 't' or testiNd == 'T');
           cout << "Iveskite "<< i << "-ojo studento egzamino rezultata: ";
           cin >> laik.egz;

          grupe.push_back(laik);
          laik.nd.clear();
       
        cout << "Ar norite ivesti dar viena studenta? (t/n): ";
        cin >> testiStudentus;
        } while (testiStudentus == 't' or testiStudentus == 'T');
       }

       else if (pasirinkimas==2)
       {
        do{
            i++;
        cout << "Iveskite "<< i << "-ojo studento varda: ";
        cin >> laik.var;
        cout << "Iveskite "<< i << "-ojo studento pavarde: ";
        cin >> laik.pav;

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
        }while (testiStudentus == 't' or testiStudentus == 'T');

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
       }while(testiStudentus == 't' or testiStudentus == 'T');
       }

       cout << "Ar galutinio balo skaiciavimui norite naudoti vidurki ar mediana? (v/m): ";
    char ats;
    cin >> ats;

    if (ats == 'v' or ats == 'V') 
    {
        cout << std::left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)" << endl;
        cout << string(50, '-') << endl;
        for (const auto &a : grupe) 
        {
            double galutinis = 0.4 * skaiciuotiVid(a.nd) + 0.6 * a.egz;
            cout << std::left << setw(15) << a.pav << setw(15) << a.var << std::fixed << std::setprecision(2) << galutinis << endl;
        }
    } 
        else if (ats == 'm' or ats == 'M') 
        {
        cout << std::left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Med.)" << endl;
        cout << string(50, '-') << endl;
        for (const auto &a : grupe) 
        {
            double galutinis = 0.4 * skaiciuotiMed(a.nd) + 0.6 * a.egz;
            cout << std::left << setw(15) << a.pav << setw(15) << a.var << std::fixed << std::setprecision(2) << galutinis << endl;
        }
       }
        return 0;
    }

    else 
        {
        cout << "Pasirinkta baigti darba" <<endl;
        return 1;
        }
    }

//---
//duomenu patikrinima padaryti