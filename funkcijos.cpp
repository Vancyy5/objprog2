#include "funkcijos.h"
#include "laikas.h"

//---
Studentas::Studentas(std::istream& is) {
    readStudent(is);
}

//---
std::istream& Studentas::readStudent(std::istream& is) {
    is >> vardas_ >> pavarde_;
    
    nd_.clear();
    int pazymys;
    
    while (is >> pazymys) {
        if (pazymys >= 1 && pazymys <= 10) {
            nd_.push_back(pazymys);
        } else {
            throw std::invalid_argument("Klaida: Netinkamas pazymys studentui " + vardas_ + " " + pavarde_);
        }
    }
    
    if (is.fail() && !is.eof()) {
        throw std::invalid_argument("Klaida: Netinkamas pazymys (ne skaicius) studentui " + vardas_ + " " + pavarde_);
    }
    
    if (!nd_.empty())
    {
        egzaminas_ = nd_.back();
        nd_.pop_back();
    }
    
    is.clear();
    
    return is;
}

//---
void Studentas::addND(int pazymys) {
    if (pazymys >= 1 && pazymys <= 10) {
        nd_.push_back(pazymys);
    } else {
        throw std::invalid_argument("Klaida: Netinkamas pazymys");
    }
}

//---
void Studentas::clearND() 
{
    nd_.clear();
}

//---
double Studentas::skaiciuotiVid() const {
    if (nd_.empty()) {
        throw std::runtime_error("Namu darbu sarasas negali buti tuscias");
    } else {
        double suma = 0.0;
        for (const auto& nd_elem : nd_) {
            suma += nd_elem;
        }
        return suma / nd_.size();
    }
}

double Studentas::skaiciuotiMed() const {
    if (nd_.empty()) {
        throw std::runtime_error("Namu darbu sarasas negali buti tuscias");
    } else {
        std::vector<int> nd_copy = nd_;
        std::sort(nd_copy.begin(), nd_copy.end());
        
        int dydis = nd_copy.size();
        if (dydis % 2 == 0) {
            return (nd_copy[dydis / 2 - 1] + nd_copy[dydis / 2]) / 2.0;
        } else {
            return nd_copy[dydis / 2];
        }
    }
}

double Studentas::galBalas(bool naudotiVidurki) const {
    double ndRezultatas;
    
    if (naudotiVidurki) {
        ndRezultatas = skaiciuotiVid();
    } else {
        ndRezultatas = skaiciuotiMed();
    }
    
    return 0.4 * ndRezultatas + 0.6 * egzaminas_;
}

bool compareByVardas(const Studentas& a, const Studentas& b) {
    return a.vardas() < b.vardas();
}

bool compareByPavarde(const Studentas& a, const Studentas& b) {
    return a.pavarde() < b.pavarde();
}

bool compareByGalutinis(const Studentas& a, const Studentas& b) {
    return a.galutinis() > b.galutinis();
}

void skaitytiIsFailo(std::vector<Studentas>& grupe, const std::string& failoPavadinimas)
 {
    std::ifstream inputFile(failoPavadinimas, std::ios::in);
    std::vector<char> buffer(65536);
    inputFile.rdbuf()->pubsetbuf(buffer.data(), buffer.size());
    
    if (!inputFile.is_open()) {
        throw std::runtime_error("Nepavyko atidaryti failo: " + failoPavadinimas);
    }
    
    Studentas laik;
    std::string line;
    
    getline(inputFile, line);
    
    while (getline(inputFile, line)) {
        std::stringstream ss(line);
        
        std::string vardas, pavarde;
        ss >> vardas >> pavarde;
        
        laik.setVardas(vardas);
        laik.setPavarde(pavarde);
        
        laik.clearND();
        int pazymys;
        std::vector<int> scores;
        
        while (ss >> pazymys) {
            if (pazymys >= 1 && pazymys <= 10) {
                scores.push_back(pazymys);
            } else {
                throw std::invalid_argument("Klaida: Netinkamas pazymys studentui " + vardas + " " + pavarde);
            }
        }
        
        if (ss.fail() && !ss.eof()) {
            throw std::invalid_argument("Klaida: Netinkamas pazymys (ne skaicius) studentui " + vardas + " " + pavarde);
        }
        
        if (!scores.empty()) {
            laik.setEgzaminas(scores.back());
            scores.pop_back();
            
            for (const auto& score : scores) {
                laik.addND(score);
            }
            
            grupe.push_back(laik);
        }
    }
    
    inputFile.close();
}

void isvestiStudentusIFaila(const std::vector<Studentas>& studentai, const std::string& failoPavadinimas, char ats) {
    std::ofstream outFile(failoPavadinimas);
    if (!outFile.is_open()) {
        throw std::runtime_error("Nepavyko atidaryti failo: " + failoPavadinimas);
    }
    
    std::vector<char> buffer(65536);
    outFile.rdbuf()->pubsetbuf(buffer.data(), buffer.size());
    
    std::stringstream header;
    header << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde";

    if (std::tolower(ats) == 'v') {
        header << std::left << "Galutinis (Vid.)" << std::endl;
    } else {
        header << std::left << "Galutinis (Med.)" << std::endl;
    }
    header << std::string(50, '-') << std::endl;
    
    outFile << header.str();
    
    const size_t BATCH_SIZE = 1000;
    std::stringstream batch;
    size_t count = 0;
    
    for (const auto& a : studentai) {
        batch << std::left << std::setw(15) << a.vardas() << std::setw(15) << a.pavarde()
              << std::fixed << std::setprecision(2) << a.galutinis() << std::endl;
        
        if (++count % BATCH_SIZE == 0) {
            outFile << batch.str();
            batch.str("");
            batch.clear();
        }
    }
    
    if (!batch.str().empty()) {
        outFile << batch.str();
    }
}

void sortStudentai(std::vector<Studentas>& grupe, char sortingOption) 
{
    if (sortingOption == 'v' || sortingOption == 'V') 
    {
        std::sort(grupe.begin(), grupe.end(), compareByVardas);
    } else if (sortingOption == 'p' || sortingOption == 'P') 
    {
        std::sort(grupe.begin(), grupe.end(), compareByPavarde);
    } else if (sortingOption == 'g' || sortingOption == 'G') 
    {
        std::sort(grupe.begin(), grupe.end(), compareByGalutinis);
    }
}

void skirstytiStudentus(std::vector<Studentas>& grupe, std::vector<Studentas>& kietiakiai, std::vector<Studentas>& vargsai)
 {
    auto it = std::partition(grupe.begin(), grupe.end(), [](const auto& a) 
    { 
        return a.galutinis() >= 5.0; 
    }
    );
    
    kietiakiai.reserve(kietiakiai.size() + std::distance(grupe.begin(), it));
    vargsai.reserve(vargsai.size() + std::distance(it, grupe.end()));
    
    std::move(grupe.begin(), it, std::back_inserter(kietiakiai));
    std::move(it, grupe.end(), std::back_inserter(vargsai));
    
    grupe.clear();
}

void testuotiDuomenuApdorojima(const std::string& aplankas, int skaicius) 
{
    srand(time(0));
    
    std::vector<Studentas> grupe;
    std::vector<Studentas> kietiakiai;
    std::vector<Studentas> vargsai;
    
    std::cout << "Ar galutinio balo skaiciavimui norite naudoti vidurki ar mediana? (v/m): ";
    char ats;
    std::cin >> ats;
    
    while (ats != 'v' && ats != 'V' && ats != 'm' && ats != 'M') {
        std::cout << "Netinkama ivestis. Bandykite dar karta: ";
        std::cin >> ats;
    }
    
    std::cout << "Kaip norite surusiuoti studentus? (v/vardas, p/pavarde, g/galutinis): ";
    char sortingOption;
    std::cin >> sortingOption;
    while (sortingOption != 'v' && sortingOption != 'V' && sortingOption != 'p' && sortingOption != 'P' && sortingOption != 'g' && sortingOption != 'G') {
        std::cout << "Netinkama ivestis. Bandykite dar karta: ";
        std::cin >> sortingOption;
    }
    
    std::string failoPavadinimas = aplankas + "/studentai_" + std::to_string(skaicius) + ".txt";
    
    Laikas nuskaitymas("Failo nuskaitymas");
    nuskaitymas.pradeti();
    skaitytiIsFailo(grupe, failoPavadinimas);
    nuskaitymas.baigti();
    
    bool naudotiVidurki = (std::tolower(ats) == 'v');
    for (auto& studentas : grupe) {
        studentas.setGalutinis(studentas.galBalas(naudotiVidurki));
    }
    

    Laikas rikiavimas(std::to_string(skaicius) + " studentu failo rusiavimas didejimo tvarka");
    rikiavimas.pradeti();
    sortStudentai(grupe, sortingOption);
    rikiavimas.baigti();
    
    Laikas skirstymas(std::to_string(skaicius)+" studentu failo skirstymas i du konteinerius");
    skirstymas.pradeti();
    skirstytiStudentus(grupe, kietiakiai, vargsai);
    skirstymas.baigti();
   
    isvestiStudentusIFaila(kietiakiai, aplankas + "/kietiakiai.txt", ats);
    isvestiStudentusIFaila(vargsai, aplankas + "/vargsai.txt", ats);
    
    kietiakiai.clear();
    vargsai.clear();
}