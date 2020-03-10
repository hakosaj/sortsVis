#include <SFML/Graphics.hpp>
#include "bar.h"

using std::vector;

//Päivitys: 1) järjestele valuet 2) etsi jokaisen barin uusi slotti vertaamalla valueihin 
// 3) muuta barien positiota slottien perusteella


int main()
{

    int outline=20;
    int screenx=660;
    int screeny=500;
    sf::RenderWindow window(sf::VideoMode(screenx,screeny), "SortsVis");

    int n=0;
    std::vector<int> slots = std::vector<int>();
    int g=outline;
    while (g<screenx-100) {
        slots.push_back(g);
        g+=14;
        n+=1;
    }

    vector<int> values=vector<int>();

    int maxValue=300;
    std::vector<Bar> bars = std::vector<Bar>();
    srand(std::time(NULL));
    int currentPos=outline;
    for (int i=0;i<n;i++) {
        int v = rand() %maxValue+1;
        bars.push_back(Bar(v,slots[i], i));
        values.push_back(v);
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();



        //Draw background itself. Green outline, white inside, black bounding box

        sf::RectangleShape background1;
        background1.setSize(sf::Vector2f(screenx-2*outline,screeny-2*outline));
        background1.setPosition(outline,outline);
        background1.setFillColor(sf::Color::White);

        sf::RectangleShape background2;
        background2.setSize(sf::Vector2f(screenx,screeny));
        background2.setPosition(0,0);
        background2.setFillColor(sf::Color::Green);

        sf::RectangleShape boundingBox;
        boundingBox.setSize(sf::Vector2f(screenx-2*outline+4,screeny-2*outline+4));
        boundingBox.setPosition(outline-2,outline-2);
        boundingBox.setFillColor(sf::Color::Black);



        window.draw(background2);
        window.draw(boundingBox);
        window.draw(background1);






        for (const auto& r:bars)
        {
            window.draw(r.backg);
            window.draw(r.rect);
        }
        window.display();
    }

    return 0;
}