#include <SFML/Graphics.hpp>
#include "bar.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    Bar a(100,1);
    Bar b(10,2);
    Bar c(200,3);
    Bar d(70,4);
    Bar e(120,5);
    Bar f(50,6);
    std::vector<Bar> bars{a,b,c,d,e,f};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (const auto& r:bars)
        {
            window.draw(.rect);
        }
        window.display();
    }

    return 0;
}