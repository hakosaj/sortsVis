#ifndef BAR_H
#define BAR_H

class Bar {       
  public:             
    int value;
    int slot;
    sf::RectangleShape rect;
    sf::RectangleShape backg;
    Bar(int value, int slot);
    void setBarPosition(int x);
    void setBarSlot(int x);
};

#endif