
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


    
void quickSort(int& sortIndexi, int& sortIndexj,int n,vector<Bar>& bars, int& arrayAccesses, int& comparisons ) 
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

        
