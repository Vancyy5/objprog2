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
    
    // Validacijos tikrinimai
    assert(!s1.vardas().empty());
    assert(!s1.pavarde().empty());
    assert(!s1.nd().empty());
    assert(s1.egzaminas() >= 0 && s1.egzaminas() <= 10);
    assert(s1.galutinis() >= 0 && s1.galutinis() <= 10);
    for (const auto& pazymys : s1.nd()) {
        assert(pazymys >= 0 && pazymys <= 10);
    }
    std::cout << "Visi s1 atributai validus\n";
    
    // === 2. Copy constructor ===
    std::cout << "\n[TEST 2] Kopijavimo konstruktorius (s2(s1))\n";
    Studentas s2(s1);
    std::cout << "Originalas s1: " << s1 << std::endl;
    std::cout << "Kopija s2: " << s2 << std::endl;
    
    // Validacijos tikrinimai s2
    assert(!s2.vardas().empty());
    assert(!s2.pavarde().empty());
    assert(!s2.nd().empty());
    assert(s2.egzaminas() >= 0 && s2.egzaminas() <= 10);
    assert(s2.galutinis() >= 0 && s2.galutinis() <= 10);
    for (const auto& pazymys : s2.nd()) {
        assert(pazymys >= 0 && pazymys <= 10);
    }
    // Lygumas su originalu
    assert(s2.vardas() == s1.vardas());
    assert(s2.pavarde() == s1.pavarde());
    assert(s2.nd() == s1.nd());
    assert(s2.egzaminas() == s1.egzaminas());
    assert(s2.galutinis() == s1.galutinis());
    std::cout << "Visi s2 atributai validus ir lygus s1\n";
    
    // === 3. Copy assignment ===
    std::cout << "\n[TEST 3] Kopijavimo priskyrimo operatorius (s3 = s1)\n";
    Studentas s3;
    s3 = s1;
    std::cout << "Originalas s1: " << s1 << std::endl;
    std::cout << "Priskirta kopija s3: " << s3 << std::endl;
    
    // Validacijos tikrinimai s3
    assert(!s3.vardas().empty());
    assert(!s3.pavarde().empty());
    assert(!s3.nd().empty());
    assert(s3.egzaminas() >= 0 && s3.egzaminas() <= 10);
    assert(s3.galutinis() >= 0 && s3.galutinis() <= 10);
    for (const auto& pazymys : s3.nd()) {
        assert(pazymys >= 0 && pazymys <= 10);
    }
    // Lygumas su originalu
    assert(s3.vardas() == s1.vardas());
    assert(s3.pavarde() == s1.pavarde());
    assert(s3.nd() == s1.nd());
    assert(s3.egzaminas() == s1.egzaminas());
    assert(s3.galutinis() == s1.galutinis());
    std::cout << " Visi s3 atributai validus ir lygus s1\n";
    
    // === 4. Move constructor ===
    std::cout << "\n[TEST 4] Perkelimo konstruktorius (s4(move(Studentas(s1))))\n";
    Studentas tempS1(s1);
    std::cout << "Temp studentas pries perkelima: " << tempS1 << std::endl;
    
    // Išsaugoti tempS1 duomenis prieš perkėlimą
    std::string tempVardas = tempS1.vardas();
    std::string tempPavarde = tempS1.pavarde();
    std::vector<int> tempND = tempS1.nd();
    int tempEgzaminas = tempS1.egzaminas();
    double tempGalutinis = tempS1.galutinis();
    
    Studentas s4(std::move(tempS1));
    std::cout << "Perkeltas objektas s4: " << s4 << std::endl;
    std::cout << "Temp studentas po perkelimo: " << tempS1 << std::endl;
    
    // Validacijos tikrinimai s4 (turi turėti originalius duomenis)
    assert(!s4.vardas().empty());
    assert(!s4.pavarde().empty());
    assert(!s4.nd().empty());
    assert(s4.egzaminas() >= 0 && s4.egzaminas() <= 10);
    assert(s4.galutinis() >= 0 && s4.galutinis() <= 10);
    for (const auto& pazymys : s4.nd()) {
        assert(pazymys >= 0 && pazymys <= 10);
    }
    // Patikrinti ar duomenys teisingai perkelti
    assert(s4.vardas() == tempVardas);
    assert(s4.pavarde() == tempPavarde);
    assert(s4.nd() == tempND);
    assert(s4.egzaminas() == tempEgzaminas);
    assert(s4.galutinis() == tempGalutinis);
    
    // tempS1 turėtų būti "ištuštintas"
    assert(tempS1.nd().empty());
    std::cout << "s4 turi visus validus atributus, tempS1 istustintas\n";
    
    // === 5. Move assignment ===
    std::cout << "\n[TEST 5] Perkelimo priskyrimo operatorius (s5 = move(s2))\n";
    
    // Išsaugoti s2 duomenis prieš perkėlimą
    std::string s2Vardas = s2.vardas();
    std::string s2Pavarde = s2.pavarde();
    std::vector<int> s2ND = s2.nd();
    int s2Egzaminas = s2.egzaminas();
    double s2Galutinis = s2.galutinis();
    
    Studentas s5;
    s5 = std::move(s2);
    std::cout << "Perkeltas s5: " << s5 << std::endl;
    std::cout << "s2 po perkelimo: " << s2 << std::endl;
    
    // Validacijos tikrinimai s5 (turi turėti s2 duomenis)
    assert(!s5.vardas().empty());
    assert(!s5.pavarde().empty());
    assert(!s5.nd().empty());
    assert(s5.egzaminas() >= 0 && s5.egzaminas() <= 10);
    assert(s5.galutinis() >= 0 && s5.galutinis() <= 10);
    for (const auto& pazymys : s5.nd()) {
        assert(pazymys >= 0 && pazymys <= 10);
    }
    // Patikrinti ar duomenys teisingai perkelti
    assert(s5.vardas() == s2Vardas);
    assert(s5.pavarde() == s2Pavarde);
    assert(s5.nd() == s2ND);
    assert(s5.egzaminas() == s2Egzaminas);
    assert(s5.galutinis() == s2Galutinis);
    
    // s2 turėtų būti "ištuštintas"
    assert(s2.nd().empty());
    std::cout << "s5 turi visus validus atributus, s2 istustintas\n";

    // === 6.1 Input operator (istringstream) ===
    std::cout << "\n[TEST 6.1] Ivesties operatorius (>> is istringstream)\n";
    std::istringstream iss("Vardenis Pavardenis 10 10 10 10 10");
    Studentas s6;
    iss >> s6;
    s6.setGalutinis(s6.galBalas());
    std::cout << "Ivestas s6: " << s6 << std::endl;
    
    // Validacijos tikrinimai s6
    assert(!s6.vardas().empty());
    assert(!s6.pavarde().empty());
    assert(!s6.nd().empty());
    assert(s6.egzaminas() >= 0 && s6.egzaminas() <= 10);
    assert(s6.galutinis() >= 0 && s6.galutinis() <= 10);
    for (const auto& pazymys : s6.nd()) {
        assert(pazymys >= 0 && pazymys <= 10);
    }
    // Specifiniai duomenys
    assert(s6.vardas() == "Vardenis");
    assert(s6.pavarde() == "Pavardenis");
    assert(s6.egzaminas() == 10);
    std::cout << "Visi s6 atributai validus ir teisingi\n";
    
    // === 6.2 Input from user ===
    std::cout << "\n[TEST 6.2] Ivestis is cin (>>)\n";
    std::cout << "Iveskite studenta (vardas pavarde ND1 ND2... egzaminas) vienoje eiluteje: ";
    Studentas s7;
    std::cin >> s7;
    s7.setGalutinis(s7.galBalas());
    std::cout << "Ivestas s7: " << s7 << std::endl;
    
    // Validacijos tikrinimai s7
    assert(!s7.vardas().empty());
    assert(!s7.pavarde().empty());
    assert(!s7.nd().empty());
    assert(s7.egzaminas() >= 0 && s7.egzaminas() <= 10);
    assert(s7.galutinis() >= 0 && s7.galutinis() <= 10);
    for (const auto& pazymys : s7.nd()) {
        assert(pazymys >= 0 && pazymys <= 10);
    }
    std::cout << "Visi s7 atributai validus\n";
    
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
    
    // Validacijos tikrinimai s8
    assert(!s8.vardas().empty());
    assert(!s8.pavarde().empty());
    assert(!s8.nd().empty());
    assert(s8.egzaminas() >= 0 && s8.egzaminas() <= 10);
    assert(s8.galutinis() >= 0 && s8.galutinis() <= 10);
    for (const auto& pazymys : s8.nd()) {
        assert(pazymys >= 0 && pazymys <= 10);
    }
    // Specifiniai duomenys
    assert(s8.vardas() == "Antanas");
    assert(s8.pavarde() == "Antanaitis");
    assert(s8.egzaminas() == 5);
    std::cout << " Visi s8 atributai validus ir teisingi\n";
    
    // === 7 Output to stringstream (<<) ===
    std::cout << "\n[TEST 7] Isvedimas i stringstream (<<)\n";
    std::ostringstream oss2;
    oss2 << s8;
    std::cout << "stringstream rezultatas: " << oss2.str() << std::endl;
    
    // Validacijos tikrinimai - patikrinti ar išvestyje yra visi duomenys
    assert(oss2.str().find("Antanas") != std::string::npos);
    assert(oss2.str().find("Antanaitis") != std::string::npos);
    assert(oss2.str().find(std::to_string(s8.galutinis()).substr(0,4)) != std::string::npos);
    std::cout << " Isvestyje yra visi reikalingi duomenys\n";
    
    // === 8. File reading with Studentas::nuskaitymasFile ===
    std::cout << "\n[TEST 8] Failo nuskaitymas su nuskaitymasFile()\n";
    std::ofstream testFailas("studentai.txt");
    testFailas << "Vanesa Balsyte 10 9 8 7 6" << std::endl;
    testFailas << "Petras Petrauskas 8 9 7 10 5" << std::endl;
    testFailas.close();

    std::vector<Studentas> grupe;
    Studentas::nuskaitymasFile(grupe, "studentai.txt");
    std::cout << "Gauta studentu: " << grupe.size() << std::endl;
    
    // Validacijos tikrinimai - teisingas studentų skaičius
    assert(grupe.size() == 2);
    
    // Validacijos tikrinimai kiekvienam studentui
    for (size_t i = 0; i < grupe.size(); ++i) {
        const auto& studentas = grupe[i];
        assert(!studentas.vardas().empty());
        assert(!studentas.pavarde().empty());
        assert(!studentas.nd().empty());
        assert(studentas.egzaminas() >= 0 && studentas.egzaminas() <= 10);
        assert(studentas.galutinis() >= 0 && studentas.galutinis() <= 10);
        for (const auto& pazymys : studentas.nd()) {
            assert(pazymys >= 0 && pazymys <= 10);
        }
        std::cout << "Studentas " << (i+1) << " visi atributai validus\n";
    }
    
    // Specifiniai duomenys
    assert(grupe[0].vardas() == "Vanesa");
    assert(grupe[0].pavarde() == "Balsyte");
    assert(grupe[1].vardas() == "Petras");
    assert(grupe[1].pavarde() == "Petrauskas");
    std::cout << " Visi nuskaityti studentai turi teisingus duomenis\n";
    
    // === 9. Output to console and file ===
    std::cout << "\n[TEST 9] Isvedimas i ekrana ir i faila\n";
    // To console
    std::cout << "Studentu rezultatai (ekrane):" << std::endl;
    for (const auto& s : grupe) {
        std::cout << s << std::endl;
        // Patikrinti kad išvedimas turi visus duomenis
        std::ostringstream temp;
        temp << s;
        assert(temp.str().find(s.vardas()) != std::string::npos);
        assert(temp.str().find(s.pavarde()) != std::string::npos);
    }
    
    // To file
    std::ofstream out("rezultataiT.txt");
    for (const auto& s : grupe) {
        out << s << std::endl;
    }
    out.close();
    
    // Patikrinti ar failas sukurtas ir turi duomenų
    std::ifstream checkFile("rezultataiT.txt");
    std::string line;
    int lineCount = 0;
    while (std::getline(checkFile, line)) {
        lineCount++;
        assert(!line.empty());
    }
    checkFile.close();
    assert(lineCount == grupe.size());
    std::cout << "Failas sukurtas su " << lineCount << " eilutemis\n";
    
    // === 10. Destructor test ===
    std::cout << "\n[TEST 10] Destruktoriaus kvietimo testas\n";
    int priesDestruktoriu = Studentas::destruktoriuSk;
    {
        Studentas laikinas;
        laikinas.setVardas("Laikinas");
        laikinas.setPavarde("Objektas");
        laikinas.addND(5);
        laikinas.setEgzaminas(7);
        laikinas.setGalutinis(laikinas.galBalas());
        
        // Validacijos tikrinimai laikinam objektui
        assert(!laikinas.vardas().empty());
        assert(!laikinas.pavarde().empty());
        assert(!laikinas.nd().empty());
        assert(laikinas.egzaminas() >= 0 && laikinas.egzaminas() <= 10);
        assert(laikinas.galutinis() >= 0 && laikinas.galutinis() <= 10);
        std::cout << "Laikinas objektas validus\n";
    } // Čia turėtų būti iškvietas destruktorius
    
    int poDestruktoriaus = Studentas::destruktoriuSk;
    assert(poDestruktoriaus > priesDestruktoriu);
    std::cout << "Destruktorius sekmingai iskviestas\n";
    std::cout << "Destruktoriaus kvietimu skaicius: " << Studentas::destruktoriuSk << std::endl;
    
    std::cout << "\n===== TESTAVIMAS SEKMINGAI BAIGTAS =====\n" << std::endl;
    std::cout << "Visi testai praejo sekmingai\n";
    std::cout << "Visi objektu atributai buvo patikrinti ir rasti validus\n";
}