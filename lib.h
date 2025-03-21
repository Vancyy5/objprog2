#ifndef LIB_H      
#define LIB_H

#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<string>
#include<numeric>
#include<algorithm>
#include<random>
#include<sstream>
#include<stdexcept>
#include<list>
#include<deque>
#include<execution>
#include<ctime>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::getline;
using std::endl;
using std::setw;
using std::list;
using std::deque;

template <typename Container>
struct Stud 
{
    string var;  
    string pav;  
    Container nd;     
    int egz;   
    double galutinis;
    
    using nd_type = Container;
};

#endif // LIB_H