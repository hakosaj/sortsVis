
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "bar.h"


Bar::Bar(int val, int slott) {
    value=val;
    slot=slott;
    //Koko on siis leveydessä vakio, pituudessa arvon mittainen
    rect.setSize(sf::Vector2f(barWidth,value));
    rect.setFillColor(sf::Color::Red);
    backg.setSize(sf::Vector2f(barWidth+2,value+2));
    backg.setFillColor(sf::Color::Black);

    //Mittaus vasen yläkulma. x vakioiinkrementaatio, y 200-value
    rect.setPosition(20+slot*barWidth+2,480-value);
    backg.setPosition(20+slot*barWidth+2-1,480-value-1);




}

    void Bar::setBarPosition(int x) {
        rect.setPosition(20+x,480-value);
        backg.setPosition(20+x-1,480-value-1);
    }
    void Bar::setBarSlot(int slott) {
        slot=slott;
        Bar::setBarPosition(slott*(barWidth)+2);
    }