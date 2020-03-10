
#include <SFML/Graphics.hpp>
#include "bar.h"



Bar::Bar(int val, int iid) {
    value=val;
    id=iid;
    rect.setSize(sf::Vector2f(10,value));
    rect.setFillColor(sf::Color::White);
    rect.setPosition(50+10*id,200);
}