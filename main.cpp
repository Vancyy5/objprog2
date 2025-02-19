#include"lib.h"
//---
double skaiciuotiVid(vector <int> nd);
double skaiciuotiMed(vector <int> nd) ;
//---
int main()
{
    Stud laik;
    vector<Stud> grupe;

    int m, n;
    cout << "Iveskite studentu skaiciu: ";
    cin >> m;

    if (m==0) //???? sutvarkyk
    {
        cout <<"Ivestas netinkamas skaicius nusakantis studentu skaiciu" << endl; 
        return 1;
    }

    else
    {
        cout << "Iveskite studentu namu darbu skaiciu: ";
        cin >> n;

        for (int i=0; i<m; i++)
        {
            cout << "Iveskite " << i+1 << "-ojo studento varda: ";
            cin >> laik.var;
            cout << "Iveskite " << i+1 << "-ojo studento pavarde: ";
            cin >> laik.pav;

            for (int j=0; j<n; j++)
            {
                int paz;
                cout << "Iveskite "<< i+1 << "-ojo studento " << j+1 << "-ojo namu darbo rezultata:";
                cin >> paz;
                laik.nd.push_back(paz);
            }

            cout << "Iveskite "<< i+1 << "-ojo studento egzamino rezultata: ";
            cin >> laik.egz;

            grupe.push_back(laik);
        }
        cout << "Ar galutinio balo skaiciavimui norite naudoti vidurki ar mediana?(v/m) " << endl;
        char ats;
        cin >> ats;

        if (ats == 'v' or ats == 'V')
        {
            cout <<std::left <<  setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20)  <<" Galutinis(Vid.)" << endl;
            cout << std::string(50, '-') << endl;
            for (auto a : grupe)
            {
                double galutinis = 0.4 * skaiciuotiVid(a.nd) + 0.6 * a.egz;
                cout << std::left << setw(15) << a.pav << setw(15) << a.var <<setw(3) <<  std::fixed << std::setprecision(2) << galutinis << endl;
            }

        }
        else if (ats == 'm' or ats =='M')
        {
            cout <<std::left <<  setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20)  <<" Galutinis(Med.)" << endl;
            cout << std::string(50, '-') << endl;
            for (auto a : grupe)
                for (auto a : grupe)
                {
                    double galutinis = 0.4 * skaiciuotiMed(a.nd) + 0.6 * a.egz;
                    cout << std::left << setw(15) << a.pav << setw(15) << a.var <<setw(3) <<  std::fixed << std::setprecision(2) << galutinis << endl;
                }
        }
        else
        {
            cout << "Netinkamai atsakytas klausimas apie galutinio balo skaiciavima" <<endl;
            return 1;
        }
    }
    return 0;
}
//---
double skaiciuotiVid(vector<int> nd) 
{
    if (nd.empty()) return 0.0;
    else
    {
    double suma = accumulate(nd.begin(), nd.end(), 0.0); //pataisyk
    return suma / nd.size();
    }
    
}

double skaiciuotiMed(vector<int> nd) 
{
    if (nd.empty()) return 0.0;
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
//--------------------------
//padaryt kiekvieno ivedamo duomenu patikrinima
//padaryt pasirinktinai meniu
//random generacija
//funkcijas sutvarkyti
//funkciju headeri padaryt
//funkciju faila padaryt

//isdestyt lentele??




