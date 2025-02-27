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


using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::getline;
using std::endl;
using std::setw;

struct Stud
{
    string var, pav;
    vector <int> nd;
    int egz;
};

#endif // LIB_H