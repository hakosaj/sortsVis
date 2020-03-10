
#include <SFML/Graphics.hpp>
#include "bar.h"


Bar::Bar(int val,int currentx, int slot) {
    value=val;
    //Koko on siis leveydessä vakio, pituudessa arvon mittainen
    rect.setSize(sf::Vector2f(12,value));
    rect.setFillColor(sf::Color::Red);
    backg.setSize(sf::Vector2f(14,value+2));
    backg.setFillColor(sf::Color::Black);

    //Mittaus vasen yläkulma. x vakioiinkrementaatio, y 200-value
    rect.setPosition(currentx,480-value);
    backg.setPosition(currentx-1,480-value-1);
}