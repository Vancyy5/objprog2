#include "funkcijos.h"
#include "laikas.h"

template <typename Container>
double skaiciuotiVid(const Container& nd) 
{
    if (nd.empty()) 
    {
        throw std::runtime_error("Namu darbu sarasas negali buti tuscias");
    }
    else
    {
        double suma = 0.0;
        for (const auto& nd_elem : nd)  
        {
            suma += nd_elem;
        }
        return suma / nd.size();
    }
}
//---
template <typename Container>
double skaiciuotiMed(const Container& nd_const)
{
    if (nd_const.empty())
    {
        throw std::runtime_error("Namu darbu sarasas negali buti tuscias");
    }
    else 
    {
        Container nd = nd_const;
        
        if constexpr (std::is_same_v<Container, std::list<int>>)
        {
            nd.sort();
        }
        else
        {
            std::sort(nd.begin(), nd.end());
        }
        
        int dydis = nd.size();
        if (dydis % 2 == 0) {
            auto it = std::next(nd.begin(), dydis / 2 - 1);
            auto it2 = std::next(nd.begin(), dydis / 2);
            return (*it + *it2) / 2.0;
        } else {
            auto it = std::next(nd.begin(), dydis / 2);
            return *it;
        }
    }
}
//---
template <typename Container>
void skaitytiIsFailo(Container& grupe, const std::string& failoPavadinimas)
{
    using StudentType = typename Container::value_type;
    using NDContainer = typename StudentType::nd_type;
    
    std::ifstream inputFile(failoPavadinimas, std::ios::in | std::ios::binary);
    std::vector<char> buffer(65536); 
    inputFile.rdbuf()->pubsetbuf(buffer.data(), buffer.size());
    
    if (!inputFile.is_open()) {
        throw std::runtime_error("Nepavyko atidaryti failo: " + failoPavadinimas);
    }
    
    StudentType laik;
    std::string line;
    
    getline(inputFile, line);  

    while (getline(inputFile, line)) 
    {
        std::stringstream ss(line);
        ss >> laik.var >> laik.pav; 

        laik.nd.clear();  
        int pazymys;
        NDContainer scores;

        while (ss >> pazymys)  
        {
            if (pazymys >= 1 && pazymys <= 10)  
            {
                scores.push_back(pazymys); // Now scores is the right container type
            }
            else 
            {
                throw std::invalid_argument("Klaida: Netinkamas pazymys studentui " + laik.var + " " + laik.pav);
            }
        }

        if (ss.fail() && !ss.eof()) 
        {
            throw std::invalid_argument("Klaida: Netinkamas pazymys (ne skaicius) studentui " + laik.var + " " + laik.pav);
        }

        if (!scores.empty())
        {
            laik.egz = scores.back();  
            scores.pop_back();  
            laik.nd = std::move(scores);  
            grupe.push_back(laik);  
        }
    }

    inputFile.close();
}
//---
template <typename Container>
void isvestiStudentusIFaila(const Container& studentai, const std::string& failoPavadinimas, char ats)
{
    std::ofstream outFile(failoPavadinimas);
    if (!outFile.is_open()) 
    {
        throw std::runtime_error("Nepavyko atidaryti failo: " + failoPavadinimas);
    }
    
    std::vector<char> buffer(65536);
    outFile.rdbuf()->pubsetbuf(buffer.data(), buffer.size());
    
    std::stringstream header;
    header << std::left << setw(15) << "Vardas" << setw(15) << "Pavarde";
    if (tolower(ats) == 'v') {
        header << std::left << "Galutinis (Vid.)" << std::endl;
    } else {
        header << std::left << "Galutinis (Med.)" << std::endl;
    }
    header << string(50, '-') << std::endl;
    
    outFile << header.str();
    
    const size_t BATCH_SIZE = 1000;
    std::stringstream batch;
    size_t count = 0;
    
    for (const auto& a : studentai) {
        batch << std::left << setw(15) << a.var << setw(15) << a.pav 
              << std::fixed << std::setprecision(2) << a.galutinis << std::endl;
        
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
//---
template <typename Container>
void sortByChoice(Container& grupe, char sortingOption) 
{
    if constexpr (std::is_same_v<Container, std::list<typename Container::value_type>>) 
    { 
        if (sortingOption == 'v' || sortingOption == 'V') {
            grupe.sort([](const auto& a, const auto& b) { return a.var < b.var; }); 
        } else if (sortingOption == 'p' || sortingOption == 'P') {
            grupe.sort([](const auto& a, const auto& b) { return a.pav < b.pav; });
        } else if (sortingOption == 'g' || sortingOption == 'G') {
            grupe.sort([](const auto& a, const auto& b) { return a.galutinis > b.galutinis; });
        }
    }
    else 
    {
        if (sortingOption == 'v' || sortingOption == 'V') {
            std::sort(std::execution::par, grupe.begin(), grupe.end(),
                      [](const auto& a, const auto& b) { return a.var < b.var; });
        } else if (sortingOption == 'p' || sortingOption == 'P') {
            std::sort(std::execution::par, grupe.begin(), grupe.end(),
                      [](const auto& a, const auto& b) { return a.pav < b.pav; });
        } else if (sortingOption == 'g' || sortingOption == 'G') {
            std::sort(std::execution::par, grupe.begin(), grupe.end(),
                      [](const auto& a, const auto& b) { return a.galutinis > b.galutinis; });
        }
    }
}
//---
template double skaiciuotiVid<std::vector<int>>(const std::vector<int>&);
template double skaiciuotiMed<std::vector<int>>(const std::vector<int>&);

template double skaiciuotiVid<std::list<int>>(const std::list<int>&);
template double skaiciuotiMed<std::list<int>>(const std::list<int>&);

template double skaiciuotiVid<std::deque<int>>(const std::deque<int>&);
template double skaiciuotiMed<std::deque<int>>(const std::deque<int>&);

template void skaitytiIsFailo<std::vector<Stud<std::vector<int>>>>(std::vector<Stud<std::vector<int>>>&, const std::string&);
template void skaitytiIsFailo<std::list<Stud<std::list<int>>>>(std::list<Stud<std::list<int>>>&, const std::string&);
template void skaitytiIsFailo<std::deque<Stud<std::deque<int>>>>(std::deque<Stud<std::deque<int>>>&, const std::string&);

template void isvestiStudentusIFaila<std::list<Stud<std::list<int>>>>(const std::list<Stud<std::list<int>>>&, const std::string&, char);
template void isvestiStudentusIFaila<std::vector<Stud<std::vector<int>>>>(const std::vector<Stud<std::vector<int>>>&, const std::string&, char);
template void isvestiStudentusIFaila<std::deque<Stud<std::deque<int>>>>(const std::deque<Stud<std::deque<int>>>&, const std::string&, char);

template void sortByChoice<std::list<Stud<std::list<int>>>>(std::list<Stud<std::list<int>>>&, char);
template void sortByChoice<std::vector<Stud<std::vector<int>>>>(std::vector<Stud<std::vector<int>>>&, char);
template void sortByChoice<std::deque<Stud<std::deque<int>>>>(std::deque<Stud<std::deque<int>>>&, char);