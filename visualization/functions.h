#ifndef FNC_H
#define FNC_H

#include "bar.h"


void swapBars(std::vector<Bar>& bars, int i, int j);
void reorderBars(std::vector<Bar> bars);
void insertSort(int& sortIndexi, int& sortIndexj,int n,std::vector<Bar>& bars, int& arrayAccesses, int& comparisons );
void iterativeQS(std::vector<Bar>& bars, int lo, int hi);






#endif