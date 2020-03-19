#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unistd.h>
#include <iostream>
#include "functions.h"

using std::vector;

//Päivitys: 1) järjestele valuet 2) etsi jokaisen barin uusi slotti vertaamalla valueihin 
// 3) muuta barien positiota slottien perusteella




int main(int argc, char **argv)
{
    sf::Font font;
    int arrayAccessess=0;
    int comparisons=0;
    sf::Text accessText;
    sf::Text comparisonText;
    font.loadFromFile("assets/Arial.ttf");
    accessText.setFont(font);
    comparisonText.setFont(font);


    int sortIndexi=0;
    int sortIndexj=0;

    bool sorted=false;

    int outline=20;
    int screenx=660;
    int screeny=500;
    sf::RenderWindow window(sf::VideoMode(screenx,screeny), "SortsVis");
    window.setFramerateLimit(240);


    vector<int> values=vector<int>();

    std::vector<Bar> bars = std::vector<Bar>();
    srand(std::time(NULL));
    int currentPos=outline;
    for (int i=0;i<n;i++) {
        int v = rand() %maxValue+1;
        bars.push_back(Bar(v,i));
        values.push_back(v);
    }


    /*
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("hit.wav"))
        return -1;

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    */




    while (window.isOpen())
    {

        std::cout << '\a';

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();




        sf::RectangleShape background1;
        background1.setSize(sf::Vector2f(screenx-2*outline,screeny-2*outline));
        background1.setPosition(outline,outline);
        sf::Color Gray =sf::Color(149, 165, 166);
        sf::Color BgWhite =sf::Color(236, 240, 241);

        background1.setFillColor(Gray);

        sf::RectangleShape background2;
        background2.setSize(sf::Vector2f(screenx,screeny));
        background2.setPosition(0,0);
        background2.setFillColor(BgWhite);

        sf::RectangleShape boundingBox;
        boundingBox.setSize(sf::Vector2f(screenx-2*outline+4,screeny-2*outline+4));
        boundingBox.setPosition(outline-2,outline-2);
        boundingBox.setFillColor(sf::Color::Black);



        window.draw(background2);
        window.draw(boundingBox);
        window.draw(background1);



        
        if (argc>1)
            //InsertSort
            if (*argv[1]=='i') {
                if (sortIndexi==n-1) {
                    sorted=true;
                }
                if(!sorted) {
                    quickSort(sortIndexi,sortIndexj,n,bars,arrayAccessess,comparisons);
                }
            }
        }

        

        

        accessText.setString("Array accesses: "+std::to_string(arrayAccessess));
        accessText.setPosition(50,30);
        accessText.setCharacterSize(20);
        accessText.setFillColor(sf::Color::Black);

        comparisonText.setString("Comparisons:    "+std::to_string(comparisons));
        comparisonText.setPosition(50,50);
        comparisonText.setCharacterSize(20);
        comparisonText.setFillColor(sf::Color::Black);
        window.draw(accessText);
        window.draw(comparisonText);

        for (const auto& r:bars)
        {
            window.draw(r.backg);
            window.draw(r.rect);
        }
        window.display();
    }

    return 0;
}

