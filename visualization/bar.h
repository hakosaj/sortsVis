#ifndef BAR_H
#define BAR_H

class Bar {       
  public:             
    int value;        
    sf::RectangleShape rect;
    sf::RectangleShape backg;
    Bar(int value, int currentx, int slot);
};

#endif