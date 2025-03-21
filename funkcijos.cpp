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
        // Make a copy of the const container
        Container nd = nd_const;
        
        // Sort the copy
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
template double skaiciuotiVid<std::vector<int>>(const std::vector<int>&);
template double skaiciuotiMed<std::vector<int>>(const std::vector<int>&);

template double skaiciuotiVid<std::list<int>>(const std::list<int>&);
template double skaiciuotiMed<std::list<int>>(const std::list<int>&);

template double skaiciuotiVid<std::deque<int>>(const std::deque<int>&);
template double skaiciuotiMed<std::deque<int>>(const std::deque<int>&);

template void skaitytiIsFailo<std::vector<Stud<std::vector<int>>>>(std::vector<Stud<std::vector<int>>>&, const std::string&);
template void skaitytiIsFailo<std::list<Stud<std::list<int>>>>(std::list<Stud<std::list<int>>>&, const std::string&);
template void skaitytiIsFailo<std::deque<Stud<std::deque<int>>>>(std::deque<Stud<std::deque<int>>>&, const std::string&);