#include "funkcijos.h"
#include "laikas.h"

//---
Studentas::Studentas(std::istream& is) 
{
    readStudent(is);
}
// Copy constructor
Studentas::Studentas(const Studentas& other) : 
    vardas_(other.vardas_), 
    pavarde_(other.pavarde_), 
    nd_(other.nd_), 
    egzaminas_(other.egzaminas_),
    galutinis_(other.galutinis_) 
    {}

// Copy assignment operator
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vardas_ = other.vardas_;
        pavarde_ = other.pavarde_;
        nd_ = other.nd_;
        egzaminas_ = other.egzaminas_;
        galutinis_ = other.galutinis_;
    }
    return *this;
}

// Move constructor
Studentas::Studentas(Studentas&& other) noexcept : 
    vardas_(std::move(other.vardas_)),
    pavarde_(std::move(other.pavarde_)),
    nd_(std::move(other.nd_)),
    egzaminas_(other.egzaminas_),
    galutinis_(other.galutinis_)
{
    other.egzaminas_ = 0;
    other.galutinis_ = 0;
}

// Move assignment operator
Studentas& Studentas::operator=(Studentas&& other) noexcept {
    if (this != &other) {
        vardas_ = std::move(other.vardas_);
        pavarde_ = std::move(other.pavarde_);
        nd_ = std::move(other.nd_);
        egzaminas_ = other.egzaminas_;
        galutinis_ = other.galutinis_;
        
        other.egzaminas_ = 0;
        other.galutinis_ = 0;
    }
    return *this;
}

// Output operator
std::ostream& operator<<(std::ostream& os, const Studentas& stud) 
{
    os << std::left << std::setw(15) << stud.vardas_ << std::setw(15) << stud.pavarde_;
    
    os << "ND: ";
    for (const auto& nd : stud.nd_) {
        os << nd << " ";
    }
    
    os << "Egz: " << stud.egzaminas_;
    os << " Galutinis: " << std::fixed << std::setprecision(2) << stud.galutinis_;
    
    return os;
}

// Input operator
std::istream& operator>>(std::istream& is, Studentas& stud) 
{
    return stud.readStudent(is);
}

std::istream& Studentas::readStudent(std::istream& is) 
{
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
Studentas::~Studentas()
 {
    nd_.clear();
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

void testuotiStudentoMetodus() {
    std::cout << "\n===== STUDENTAS KLASES METODU TESTAVIMAS =====\n" << std::endl;
    
    // Test default constructor
    std::cout << "1. Default konstruktoriaus testavimas:" << std::endl;
    Studentas s1;
    s1.setVardas("Vanesa");
    s1.setPavarde("Balsyte");
    s1.addND(8);
    s1.addND(9);
    s1.addND(10);
    s1.setEgzaminas(9);
    s1.setGalutinis(s1.galBalas());
    std::cout << "   Sukurtas studentas: " << s1 << std::endl;
    
    // Test copy constructor
    std::cout << "\n2. Kopijavimo konstruktoriaus testavimas:" << std::endl;
    Studentas s2(s1);
    std::cout << "   Originalas: " << s1 << std::endl;
    std::cout << "   Kopija: " << s2 << std::endl;
    
    // Test copy assignment
    std::cout << "\n3. Kopijavimo priskyrimo operatoriaus testavimas:" << std::endl;
    Studentas s3;
    s3 = s1;
    std::cout << "   Originalas: " << s1 << std::endl;
    std::cout << "   Priskirta kopija: " << s3 << std::endl;
    
    // Test move constructor
    std::cout << "\n4. Perkelimo konstruktoriaus testavimas:" << std::endl;
    Studentas s4(std::move(Studentas(s1)));
    std::cout << "   Originalas: " << s1 << std::endl;
    std::cout << "   Perkeltas objektas: " << s4 << std::endl;
    
    // Test move assignment
    std::cout << "\n5. Perkelimo priskyrimo operatoriaus testavimas:" << std::endl;
    Studentas s5;
    s5 = std::move(Studentas(s1));
    std::cout << "   Originalas: " << s1 << std::endl;
    std::cout << "   Priskirtas perkeltas objektas: " << s5 << std::endl;
    
    // Test input and output operators
    std::cout << "\n6. Ivesties ir isvesties operatoriu testavimas:" << std::endl;
    std::cout << "   Isvestis: " << s1 << std::endl;
    
    std::cout << "   Ivestis is string srauto (Petras Petraitis 7 8 9 10):" << std::endl;
    std::stringstream ss("Petras Petraitis 7 8 9 10");
    Studentas s6;
    ss >> s6;
    std::cout << "   Nuskaitytas studentas: " << s6 << std::endl;
    
    // Test nd functions
    std::cout << "\n7. ND funkciju testavimas:" << std::endl;
    std::cout << "   Pries pakeitimus: " << s6 << std::endl;
    s6.addND(5);
    std::cout << "   Po addND(5): " << s6 << std::endl;
    std::cout << "   ND vidurkis: " << s6.skaiciuotiVid() << std::endl;
    std::cout << "   ND mediana: " << s6.skaiciuotiMed() << std::endl;
    s6.clearND();
    std::cout << "   Po clearND(): " << s6 << std::endl;
    
    std::cout << "\n===== TESTAVIMAS BAIGTAS =====\n" << std::endl;
}