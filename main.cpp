#include"lib.h"
//---
double skaiciuotiVid(vector <int> nd);
double skaiciuotiMed(vector <int> nd);
int readInteger();
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
        n=readInteger();

        for (int i=0; i<m; i++)
        {
            cout << "Iveskite " << i+1 << "-ojo studento varda: ";
            getline(cin, laik.var);
            cout << "Iveskite " << i+1 << "-ojo studento pavarde: ";
            getline(cin, laik.pav);

            for (int j=0; j<n; j++)
            {
                int paz;
                cout << "Iveskite "<< i+1 << "-ojo studento " << j+1 << "-ojo namu darbo rezultata:";
                paz=readInteger();
                laik.nd.push_back(paz);
            }

            cout << "Iveskite "<< i+1 << "-ojo studento egzamino rezultata: ";
            laik.egz=readInteger();

            grupe.push_back(laik);
            laik.nd.clear();
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
        double suma = 0.0;
        for (int nd : nd) 
        {
            suma += nd;
        }
    return suma*1.00/ nd.size();
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
//---
int readInteger() 
{
    int value;
    while (true) {
        cin >> value;
        if (cin.fail() or value < 0) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Klaida: Prasome ivesti teigiama skaiciu." << endl;
        }
        else {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return value;
}
//--------------------------
//padaryt kiekvieno ivedamo duomenu patikrinima
//padaryt pasirinktinai meniu
//funkcijas sutvarkyti
//funkciju headeri padaryt
//funkciju faila padaryt

//isdestyt lentele??




