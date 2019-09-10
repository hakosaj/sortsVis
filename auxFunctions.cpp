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

typedef unsigned long long data_t;
using std::cout;
using std::vector;
using std::endl;
using std::string;

auto start_time = std::chrono::high_resolution_clock::now();
auto end_time = std::chrono::high_resolution_clock::now();




data_t* randomArray(int n)  {

    std::random_device(rd);

    std::default_random_engine generator(rd());
    std::uniform_int_distribution<long long unsigned> distribution(0,0xFFFFFFFFFFFFFFFF);

    data_t* rar=(data_t*)calloc(n,sizeof(data_t));

    for (int j=0;j<n;j++) {
        rar[j] = distribution(generator);
    }

    return rar;

}




void assertSorted(data_t* ar, int n) {

    assert(std::is_sorted(ar,ar+n));
    std::cout<<"Is properly sorted!"<<std::endl;
}


void timerStart() {start_time = std::chrono::high_resolution_clock::now();}
void timerEnd() {
    end_time= std::chrono::high_resolution_clock::now();
    cout << std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ".";
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " seconds!"<<endl;

    }
