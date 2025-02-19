#include"lib.h"
//---
double skaiciuotiVid(vector<int> nd);
double skaiciuotiMed(vector<int> nd);
int generuotiAtsitiktiniP(int min=1, int max=10) 
{
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}
//---
int main() 
{
    Stud laik;
    vector<Stud> grupe;

    char testiStudentus, testiNd, generuoti;
    int i=0;
    do 
    {
        i++;
        cout << "Iveskite "<< i << "-ojo studento varda: ";
        cin >> laik.var;
        cout << "Iveskite "<< i << "-ojo studento pavarde: ";
        cin >> laik.pav;

        laik.nd.clear();
        cout << "Ar norite generuoti namu darbu ir egzamino rezultatus atsitiktinai? (t/n): ";
        cin >> generuoti;

        if (generuoti == 't' or generuoti == 'T') 
        {
            int kiekis = generuotiAtsitiktiniP(1, 10);

          for (int j = 0; j < kiekis; ++j) 
          {
          int paz = generuotiAtsitiktiniP(1, 10);
           laik.nd.push_back(paz);
          }

           laik.egz = generuotiAtsitiktiniP(1, 10);
        } 
        else 
        {
        cout << "Ar norite ivesti "<< i << "-ojo studento namu darbu rezultatus? (t/n): ";
        cin >> testiNd;
        int j=0;
        while (testiNd == 't' or testiNd == 'T')
         {

            int paz;
            j++;
            cout << "Iveskite "<< i << "-ojo studento "<< j << "-ojo namu darbo rezultata: ";
            cin >> paz;
            laik.nd.push_back(paz);

            cout << "Ar norite ivesti dar viena namu darba? (t/n): ";
            cin >> testiNd;
        }
        cout << "Iveskite "<< i << "-ojo studento egzamino rezultata: ";
        cin >> laik.egz;
       }  

       grupe.push_back(laik);
       laik.nd.clear();
       


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
        else 
        {
        cout << "Netinkamai atsakytas klausimas apie galutinio balo skaiciavima" <<endl;
        return 1;
        }

    return 0;
}
//---
double skaiciuotiVid(vector<int> nd) 
{
    if (nd.empty()) return 0.00;
    else
    {
    double suma = accumulate(nd.begin(), nd.end(), 0.0); //pataisyk
    return suma / nd.size();
    }
    
}
//---
double skaiciuotiMed(vector<int> nd) 
{
    if (nd.empty()) return 0.00;
    else
    {
        sort(nd.begin(), nd.end());
    int dydis = nd.size();
    if (dydis % 2 == 0) 
    {
        return (nd[dydis / 2 - 1] + nd[dydis / 2]) / 2.0;
    } 
    else 
    {
        return nd[dydis / 2];
    }
    }
    
}
//---
//duomenu patikrinima padaryti