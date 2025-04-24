#include "funkcijos.h"
#include "laikas.h"

// Initialize static counter
int Studentas::destruktoriuSk = 0;

//---
Studentas::Studentas(std::istream& is) {
    readStudent(is);
}

//---
// Copy constructor
Studentas::Studentas(const Studentas& other) : 
    vardas_(other.vardas_), 
    pavarde_(other.pavarde_), 
    nd_(other.nd_), 
    egzaminas_(other.egzaminas_),
    galutinis_(other.galutinis_) 
{
    // std::cout << "Copy constructor called for " << vardas_ << " " << pavarde_ << std::endl;
}

// Copy assignment operator
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vardas_ = other.vardas_;
        pavarde_ = other.pavarde_;
        nd_ = other.nd_;
        egzaminas_ = other.egzaminas_;
        galutinis_ = other.galutinis_;
    }
    // std::cout << "Copy assignment operator called for " << vardas_ << " " << pavarde_ << std::endl;
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
    // std::cout << "Move constructor called for " << vardas_ << " " << pavarde_ << std::endl;
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
    // std::cout << "Move assignment operator called for " << vardas_ << " " << pavarde_ << std::endl;
    return *this;
}

// Output operator
std::ostream& operator<<(std::ostream& os, const Studentas& stud) {
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
std::istream& operator>>(std::istream& is, Studentas& stud) {
    return stud.readStudent(is);
}

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
Studentas::~Studentas()
{
    nd_.clear();
    destruktoriuSk++; 
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

// Static method for file reading
void Studentas::nuskaitymasFile(std::vector<Studentas>& grupe, const std::string& failoPavadinimas) {
    std::ifstream inputFile(failoPavadinimas);
    
    if (!inputFile.is_open()) {
        throw std::runtime_error("Nepavyko atidaryti failo: " + failoPavadinimas);
    }
    
    std::string line;
    
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        Studentas stud;
        ss >> stud;
        
        if (!stud.vardas().empty()) {
            stud.setGalutinis(stud.galBalas(true));
            grupe.push_back(stud);
        }
    }
    
    inputFile.close();
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
    

    Laikas rikiavimas(std::to_string(skaicius) + " studentu failo rusiavimas");
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
    
    // Reset counter
    Studentas::destruktoriuSk = 0;
    
    // === 1. Default constructor ===
    std::cout << "[TEST 1] Default konstruktorius\n";
    Studentas s1;
    s1.setVardas("Vanesa");
    s1.setPavarde("Balsyte");
    s1.addND(8);
    s1.addND(9);
    s1.addND(10);
    s1.setEgzaminas(9);
    s1.setGalutinis(s1.galBalas());
    std::cout << "Sukurtas studentas s1: " << s1 << std::endl;
    assert(!s1.vardas().empty());
    
    // === 2. Copy constructor ===
    std::cout << "\n[TEST 2] Kopijavimo konstruktorius (s2(s1))\n";
    Studentas s2(s1);
    std::cout << "Originalas s1: " << s1 << std::endl;
    std::cout << "Kopija s2: " << s2 << std::endl;
    assert(s2.vardas() == s1.vardas());
    assert(s2.nd() == s1.nd());
    
    // === 3. Copy assignment ===
    std::cout << "\n[TEST 3] Kopijavimo priskyrimo operatorius (s3 = s1)\n";
    Studentas s3;
    s3 = s1;
    std::cout << "Originalas s1: " << s1 << std::endl;
    std::cout << "Priskirta kopija s3: " << s3 << std::endl;
    assert(s3.vardas() == s1.vardas());
    assert(s3.nd() == s1.nd());
    
    // === 4. Move constructor ===
    std::cout << "\n[TEST 4] Perkelimo konstruktorius (s4(move(Studentas(s1))))\n";
    Studentas tempS1(s1);
    std::cout << "Temp studentas pries perkelima: " << tempS1 << std::endl;
    Studentas s4(std::move(tempS1));
    std::cout << "Perkeltas objektas s4: " << s4 << std::endl;
    std::cout << "Temp studentas po perkelimo: " << tempS1 << std::endl;
    assert(s4.vardas() == s1.vardas());
    assert(tempS1.nd().empty());
    
    // === 5. Move assignment ===
    std::cout << "\n[TEST 5] Perkelimo priskyrimo operatorius (s5 = move(s2))\n";
    Studentas s5;
    s5 = std::move(s2);
    std::cout << "Perkeltas s5: " << s5 << std::endl;
    std::cout << "s2 po perkelimo: " << s2 << std::endl;
    assert(!s5.nd().empty());
    assert(s2.nd().empty());

    
    // === 6.1 Input operator (istringstream) ===
    std::cout << "\n[TEST 6.1] Ivesties operatorius (>> is istringstream)\n";
    std::istringstream iss("Vardenis Pavardenis 10 10 10 10 10");
    Studentas s6;
    iss >> s6;
    s6.setGalutinis(s6.galBalas());
    std::cout << "Ivestas s6: " << s6 << std::endl;
    assert(s6.vardas() == "Vardenis");
    
    // === 6.2 Input from user ===
    std::cout << "\n[TEST 6.2] Ivestis is cin (>>)\n";
    std::cout << "Iveskite studenta (vardas pavarde ND1 ND2... egzaminas) vienoje eiluteje: ";
    Studentas s7;
    std::cin >> s7;
    s7.setGalutinis(s7.galBalas());
    std::cout << "Ivestas s7: " << s7 << std::endl;
    assert(!s7.vardas().empty());
    
    // === 6.3 Input from file with operator>> ===
    std::cout << "\n[TEST 6.3] Ivestis is failo su operator>>\n";
    std::ofstream failin("failinis.txt");
    failin << "Antanas Antanaitis 9 8 7 6 5" << std::endl;
    failin.close();

    std::ifstream failIn("failinis.txt");
    Studentas s8;
    failIn >> s8;
    failIn.close();
    s8.setGalutinis(s8.galBalas());
    std::cout << "Is failo ivestas s8: " << s8 << std::endl;
    assert(s8.vardas() == "Antanas");
    
    // === 7 Output to stringstream (<<) ===
    std::cout << "\n[TEST 7] Isvedimas i stringstream (<<)\n";
    std::ostringstream oss2;
    oss2 << s8;
    std::cout << "stringstream rezultatas: " << oss2.str() << std::endl;
    assert(oss2.str().find("Antanaitis") != std::string::npos);
    
    // === 8. File reading with Studentas::nuskaitymasFile ===
    std::cout << "\n[TEST 8] Failo nuskaitymas su nuskaitymasFile()\n";
    std::ofstream testFailas("studentai.txt");
    testFailas << "Vanesa Balsyte 10 9 8 7 6" << std::endl;
    testFailas << "Petras Petrauskas 8 9 7 10 5" << std::endl;
    testFailas.close();

    std::vector<Studentas> grupe;
    Studentas::nuskaitymasFile(grupe, "studentai.txt");
    std::cout << "Gauta studentu: " << grupe.size() << std::endl;
    assert(grupe.size() == 2);
    assert(grupe[0].vardas() == "Vanesa");
    assert(grupe[1].vardas() == "Petras");
    
    // === 9. Output to console and file ===
    std::cout << "\n[TEST 9] Isvedimas i ekrana ir i faila\n";
    // To console
    std::cout << "Studentu rezultatai (ekrane):" << std::endl;
    for (const auto& s : grupe) std::cout << s << std::endl;
    // To file
    std::ofstream out("rezultataiT.txt");
    for (const auto& s : grupe) out << s << std::endl;
    out.close();
    
    // === 10. Destructor test ===
    std::cout << "\n[TEST 10] Destruktoriaus kvietimo testas\n";
    {
        Studentas laikinas;
    }
    std::cout << "Destruktoriaus kvietimu skaicius: " << Studentas::destruktoriuSk << std::endl;
    
    std::cout << "\n===== TESTAVIMAS SEKMINGAI BAIGTAS =====\n" << std::endl;
}

void testuotiZmogausKlase() 
{
    std::cout << "\n===== ZMOGUS KLASES TESTAVIMAS =====\n" << std::endl;
    
    try {
        std::cout << "[TEST] Bandymas sukurti Zmogus objekta tiesiogiai\n";
        //Atkomentuoti, kad tikrinti
        // Zmogus z; 
    }
    catch (const std::exception& e) {
        std::cerr << "Klaida testuojant Zmogus klase: " << e.what() << std::endl;
    }
}