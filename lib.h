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
    string var, pav;
    double egz;
    Container nd; 
};

#endif // LIB_H