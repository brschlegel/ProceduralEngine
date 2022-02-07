#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include "Random.h"
#include <string>
#include "PerlinNoise.h"
#include "GameObject.h"

int main()
{
    Random::seedGenerator();

    PerlinNoise p = PerlinNoise(1);

    //Testing perlin noise. Should really just do a texture lol
    sf::RectangleShape shapes[50][50];

    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            sf::RectangleShape r = sf::RectangleShape(sf::Vector2f(20, 20));
            r.setPosition(sf::Vector2f(i * 20, j * 20));
            float n = (p.sample(i * .1f, j * .1f) + 1) * 127;
            r.setFillColor(sf::Color(n,n,n));
            shapes[i][j] = r;
        }
    }
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    //Test for Box2D, works for release too
    b2Vec2 gravity(0.0f, -10.0f);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                window.draw(shapes[i][j]);
            }
        }
        window.display();
    }


    return 0;
}