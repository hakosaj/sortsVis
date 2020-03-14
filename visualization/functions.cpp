
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
    