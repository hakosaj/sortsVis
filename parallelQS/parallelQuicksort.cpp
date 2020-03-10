
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
#include "auxFunctions.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;

typedef unsigned long long data_t;


 void quicksort(data_t* first, data_t* last)
 {
    if (last-first < 5000) {
        std::sort(first,last);
        return;
    }


    auto pivot = *std::next(first, std::distance(first,last)/2);

    data_t* middleLo = std::partition(first, last, 
                         [pivot](const auto& element){ return element < pivot; });

    data_t* middleHi = std::partition(middleLo, last, 
                         [pivot](const auto& element){ return !(pivot < element); });

    #pragma omp task
    quicksort(first, middleLo);

    #pragma omp task
    quicksort(middleHi, last);
 }
 

void psort(int n, data_t* data) {


    #pragma omp parallel
    #pragma omp single
    {
 	   quicksort(data, data+n);
    }

}

int main(int argc, char** argv)  {
    int n;


    if (argc==2)
        n=std::stoi(argv[1]);
    else
        n=10000000;


    data_t* rar=randomArray(n);

	timerStart();

    psort(n,rar);
   
    timerEnd();

    assertSorted(rar,n);

    return 1;
}
