#include "lib.h"
//---
struct Studentai
{
    string var, pav;
    int* nd;
    int nd_kiekis;
    int egz;
};
//---
double skaiciuotiVid(const Studentai& a);
double skaiciuotiMed(const Studentai& a);
int generuotiAtsitiktiniP(int min=1, int max=10);
string generuotiPavarde(bool berniukas);
string generuotiVarda(bool berniukas);
int readInteger();
//---
int main() 
{
    srand(time(0));
    Studentai laik;
    vector<Studentai> grupe;
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

        if (pasirinkimas!=1 and pasirinkimas!=2 and pasirinkimas!=3 and pasirinkimas!=4)
    {
        cout << "Neteisingai pasirinktas meniu variantas" <<endl;
        return 1;
    }
    if (pasirinkimas!=4)
    {
        if(pasirinkimas==1)
        {
          int i=0;
          do
          {
            laik.nd_kiekis = 0;
            laik.nd = nullptr;
            i++;
            cout << "Iveskite "<< i << "-ojo studento varda: ";
            cin>> laik.var;
            cout << "Iveskite "<< i << "-ojo studento pavarde: ";
            cin>> laik.pav;

        do 
        {
            int paz;
            laik.nd_kiekis++;
            cout << "Iveskite "<< i << "-ojo studento "<< laik.nd_kiekis << "-ojo namu darbo rezultata: ";
            paz=readInteger();

            laik.nd = new int[laik.nd_kiekis];
            for (int k = 0; k < laik.nd_kiekis; ++k) 
            {
                laik.nd[k] = paz;
            }
            cout << "Ar norite ivesti dar viena namu darba? (t/n): ";
            cin >> testiNd;
            if (testiNd == 'n' or testiNd == 'N') break;
        else if (testiNd != 't' and testiNd != 'T')
        {
            cout << "Blogai atsakytas paskutinis klausimas" << endl;
            return 1;
        }

        }while (testiNd == 't' or testiNd == 'T');
        cout << "Iveskite "<< i << "-ojo studento egzamino rezultata: ";
        laik.egz=readInteger();

        grupe.push_back(laik);
       
        cout << "Ar norite ivesti dar viena studenta? (t/n): ";
        cin >> testiStudentus;
        if (testiStudentus == 'n' or testiStudentus == 'N') break;
        else if (testiStudentus != 't' and testiStudentus != 'T')
        {
            cout << "Blogai atsakytas paskutinis klausimas" << endl;
            return 1;
        }
        } while (testiStudentus == 't' or testiStudentus == 'T');
       }

       else if (pasirinkimas==2)
       {
        do{
            i++;
            laik.nd_kiekis = 0;
            laik.nd = nullptr;
        cout << "Iveskite "<< i << "-ojo studento varda: ";
        cin>>laik.var;
        cout << "Iveskite "<< i << "-ojo studento pavarde: ";
        cin>>laik.pav;

        laik.nd_kiekis = generuotiAtsitiktiniP(1, 10);

        laik.nd = new int[laik.nd_kiekis]; 

        for (int j = 0; j < laik.nd_kiekis; ++j) 
        {
            laik.nd[j] = generuotiAtsitiktiniP(1, 10); 
        }

       laik.egz = generuotiAtsitiktiniP(1, 10);

           grupe.push_back(laik);
           
            cout << "Ar norite ivesti dar viena studenta? (t/n): ";
            cin >> testiStudentus;
            if (testiStudentus == 'n' or testiStudentus == 'N') break;
        else if (testiStudentus != 't' and testiStudentus != 'T')
        {
            cout << "Blogai atsakytas paskutinis klausimas" << endl;
            return 1;
        }
        }while (testiStudentus == 't' or testiStudentus == 'T');

       }
       else if (pasirinkimas==3)
       {
        do
        {
            laik.nd_kiekis = 0;
            laik.nd = nullptr;
        bool berniukas = rand() % 2 == 0;
        laik.var = generuotiVarda(berniukas);
        laik.pav = generuotiPavarde(berniukas);

           laik.nd_kiekis = generuotiAtsitiktiniP(1, 10);

            laik.nd = new int[laik.nd_kiekis]; 

            for (int j = 0; j < laik.nd_kiekis; ++j) 
            {
                laik.nd[j] = generuotiAtsitiktiniP(1, 10); 
            }

           laik.egz = generuotiAtsitiktiniP(1, 10);

           grupe.push_back(laik);

        cout << "Ar sugeneruoti dar viena studenta? (t/n): ";
        cin >> testiStudentus;
        if (testiStudentus == 'n' or testiStudentus == 'N') break;
        else if (testiStudentus != 't' and testiStudentus != 'T')
        {
            cout << "Blogai atsakytas paskutinis klausimas" << endl;
            return 1;
        }
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
               double galutinis = 0.4 * skaiciuotiVid(a) + 0.6 * a.egz;
               cout << std::left << setw(15) << a.pav << setw(15) << a.var << std::fixed << std::setprecision(2) << galutinis << endl;
           }
       } 
           else if (ats == 'm' or ats == 'M') 
           {
           cout << std::left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Med.)" << endl;
           cout << string(50, '-') << endl;
           for (const auto &a : grupe) 
           {
               double galutinis = 0.4 * skaiciuotiMed(a) + 0.6 * a.egz;
               cout << std::left << setw(15) << a.pav << setw(15) << a.var << std::fixed << std::setprecision(2) << galutinis << endl;
           }
           } 
           else
        {
            cout << "Netinkamai atsakytas klausimas apie galutinio balo skaiciavima" <<endl;
            return 1;
        }
           for (auto &a : grupe) 
           { 
           delete[] a.nd;
           }
           return 0;
        
    }

    else if(pasirinkimas==4)
        {
        cout << "Pasirinkta baigti darba" <<endl;
        return 1;
        }
    
}
//---
double skaiciuotiVid(const Studentai& a) 
{
    if (a.nd == nullptr)
    {
        throw std::runtime_error("Namu darbu sarasas negali buti tuscias");
    }

    double suma = 0;
    for (int i = 0; i < a.nd_kiekis; ++i) 
    {
        suma += a.nd[i];
    }
    return suma / a.nd_kiekis;
}
//---
double skaiciuotiMed(const Studentai& a) 
{
    if (a.nd == nullptr) 
    {
        throw std::runtime_error("Namu darbu sarasas negali buti tuscias");
    }

    int* kopija = new int[a.nd_kiekis];
    for (int i = 0; i < a.nd_kiekis; ++i) 
    {
        kopija[i] = a.nd[i];
    }

    std::sort(kopija, kopija + a.nd_kiekis);

    double mediana;
    if (a.nd_kiekis % 2 == 0)
     {
        mediana = (kopija[a.nd_kiekis / 2 - 1] + kopija[a.nd_kiekis / 2]) / 2.0;
    } else {
        mediana = kopija[a.nd_kiekis / 2];
    }

    delete[] kopija;
    return mediana;
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
int readInteger() 
{
    int value;
    while (true) {
        cin >> value;
        if (cin.fail() or value < 0) 
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Klaida: Prasome ivesti teigiama skaiciu." << endl;
        }
        else 
        {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return value;
}

