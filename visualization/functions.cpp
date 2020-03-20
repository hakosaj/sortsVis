
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "functions.h"
using std::vector;




void swapBars(vector<Bar>& bars, int i, int j) {
    int slot1=bars[i].slot;
    bars[i].setBarSlot(bars[j].slot);
    bars[j].setBarSlot(slot1);
    std::swap(bars[i],bars[j]);
}

void reorderBars(std::vector<Bar> bars) {
    
}


    
void insertSort(int& sortIndexi, int& sortIndexj,int n,vector<Bar>& bars, int& arrayAccesses, int& comparisons ) 
{
            
            
                    if (sortIndexj==n) {
                        sortIndexi++;
                        sortIndexj=sortIndexi+1;
                        for (int a=sortIndexi;a<n;a++) {
                            bars[a].rect.setFillColor(myRed);
                        }
                    }else {
                        sortIndexj++;
                    }

                    if (sortIndexi!=n-1) {

                        if(bars[sortIndexj].value<bars[sortIndexi].value) {
                            comparisons+=1;
                            swapBars(bars,sortIndexi,sortIndexj);
                            arrayAccesses+=4;

                        }
                    }
        bars[sortIndexi].rect.setFillColor(myGreen);
        bars[sortIndexj].rect.setFillColor(myYellow);
}


void iterativeQS(std::vector<Bar>& bars, int lo, int hi) {
    int stack[hi-lo+1];
    int top=-1;
    stack[++top]=lo;
    stack[++top]=hi;
    while(top>=0) {
        hi=stack[top--];
        lo=stack[top--];
        //partition
        Bar pivot=bars[hi];
        int i=lo;
        for (int j=lo;j<hi;j++) {
            if (bars[j].value<pivot.value) {
               swapBars(bars,i,j);
                i++;
            }
        }
        swapBars(bars,i,hi);
        int p=i;

        if(p-1>lo) {
            stack[++top]=lo;
            stack[++top]=p-1;
        }

        if(p+1<hi) {
            stack[++top]=p+1;
            stack[++top]=hi;
        }
    }
}

