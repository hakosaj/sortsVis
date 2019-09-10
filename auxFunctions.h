#ifndef AUX_H
#define AUX_H



#include <omp.h>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <random>
#include <cassert>
#include <chrono>

typedef unsigned long long data_t;
using std::cout;
using std::vector;
using std::endl;
using std::string;


data_t* randomArray(int);
void assertSorted(data_t*, int);
void timerStart();
void timerEnd();


#endif
