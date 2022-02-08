#include "DrawManager.h"
#include <iostream>
#include "Random.h"
#include <string>
#include "PerlinNoise.h"
#include "GameObject.h"



int windowWidth = 960;
int windowHeight = 540;

int main()
{
    Random::seedGenerator();

    Debug::drawDebug = true;
    Debug::drawGrid = true;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");
    DrawManager::windowWidth = windowWidth;
    DrawManager::windowHeight = windowHeight;
    DrawManager drawManager = DrawManager();
    
    //Test for Box2D, works for release too
    b2Vec2 gravity(0.0f, -10.0f);
    while (window.isOpen())
    {

        window.clear(sf::Color(255,255,255));
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        drawManager.DrawDebug(&window);
        window.display();
    }


    return 0;
}