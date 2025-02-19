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
//---
int main() 
{
    Studentai laik;
    vector<Studentai> grupe;

    char testiStudentus, testiNd, generuoti;
    int i=0;
    do 
    {
        i++;
        cout << "Iveskite "<< i << "-ojo studento varda: ";
        cin >> laik.var;
        cout << "Iveskite "<< i << "-ojo studento pavarde: ";
        cin >> laik.pav;

        laik.nd_kiekis = 0;
        laik.nd = nullptr;

        cout << "Ar norite generuoti namu darbu ir egzamino rezultatus atsitiktinai? (t/n): ";
        cin >> generuoti;

        if (generuoti == 't' or generuoti == 'T') 
        {
            laik.nd_kiekis = generuotiAtsitiktiniP(1, 10);

            laik.nd = new int[laik.nd_kiekis]; 

            for (int j = 0; j < laik.nd_kiekis; ++j) 
            {
                laik.nd[j] = generuotiAtsitiktiniP(1, 10); 
            }

           laik.egz = generuotiAtsitiktiniP(1, 10);
        } 
        else 
       {
        cout << "Ar norite ivesti "<< i << "-ojo studento namu darbu rezultatus? (t/n): ";
        cin >> testiNd;

        while (testiNd == 't' or testiNd == 'T') 
        {
            int paz;
            laik.nd_kiekis++;
            cout << "Iveskite "<< i << "-ojo studento "<< laik.nd_kiekis << "-ojo namu darbo rezultata: ";
            cin >> paz;

            laik.nd = new int[laik.nd_kiekis];
            for (int k = 0; k < laik.nd_kiekis; ++k) 
            {
                laik.nd[k] = paz;
            }
            cout << "Ar norite ivesti dar viena namu darba? (t/n): ";
            cin >> testiNd;

        }
        cout << "Iveskite "<< i << "-ojo studento egzamino rezultata: ";
        cin >> laik.egz;
        }

        grupe.push_back(laik);

        cout << "Ar norite ivesti dar viena studenta? (t/n): ";
        cin >> testiStudentus;
    } while (testiStudentus == 't' or testiStudentus == 'T');

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
//---
double skaiciuotiVid(const Studentai& a) 
{
    if (a.nd_kiekis == 0) return 0.0;

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
    if (a.nd_kiekis == 0) return 0.0;

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
//meniu padaryti
//duomenu patikrinima padaryti