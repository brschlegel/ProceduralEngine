#include "DrawManager.h"
int DrawManager::windowWidth;
int DrawManager::windowHeight;

sf::Vector2f DrawManager::convertToSF(b2Vec2 vec)
{
    vec *= PIXEL_PER_METER;
    return sf::Vector2f(vec.x + DrawManager::windowWidth / 2, -vec.y + DrawManager::windowHeight / 2);

}

b2Vec2 DrawManager::convertToB2(sf::Vector2f vec)
{
    return b2Vec2();
}

void DrawManager::DrawDebug(sf::RenderWindow* window)
{

    for (sf::RectangleShape rect : Debug::rects)
    {
        window->draw(rect);
    }

    //Once we are done drawing, remove from the list
    Debug::rects.clear();
}
