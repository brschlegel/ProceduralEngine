#include "DrawManager.h"
int DrawManager::windowWidth;
int DrawManager::windowHeight;

bool Debug::drawGrid;
bool Debug::drawDebug;

sf::Vector2f DrawManager::convertToSF(b2Vec2 vec)
{
    vec *= PIXEL_PER_METER;
    return sf::Vector2f(vec.x + DrawManager::windowWidth / 2, -vec.y + DrawManager::windowHeight / 2);

}

b2Vec2 DrawManager::convertToB2(sf::Vector2f vec)
{
    return b2Vec2();
}

int distBetweenLines = 1;
int numLines = 50;

void DrawManager::DrawDebug(sf::RenderWindow* window)
{
    if (Debug::drawDebug)
    {
        if (Debug::drawGrid)
        {
            for (int i = 0; i < numLines; i++)
            {
                //Shade the axis black
                int offset = distBetweenLines * numLines / 2;
                if (i != numLines / 2)
                {
                    Debug::DrawLine(b2Vec2(i * distBetweenLines - offset, 100), b2Vec2(i * distBetweenLines - offset, -100), sf::Color(255, 0, 0, 50));
                    Debug::DrawLine(b2Vec2(100, i * distBetweenLines - offset), b2Vec2(-100, i * distBetweenLines - offset), sf::Color(0, 0, 255, 50));
                }
                else
                {
                    Debug::DrawLine(b2Vec2(i * distBetweenLines - offset, 100), b2Vec2(i * distBetweenLines - offset, -100), sf::Color(0, 0, 0, 100));
                    Debug::DrawLine(b2Vec2(100, i * distBetweenLines - offset), b2Vec2(-100, i * distBetweenLines - offset), sf::Color(0, 0, 0, 100));
                }
            }
        }
        for (sf::RectangleShape rect : Debug::rects)
        {
            window->draw(rect);
        }
        for (int i = 0; i < Debug::lines.size(); i++)
        {
            window->draw(Debug::lines[i].data(), 2, sf::Lines);
        }
        for (sf::CircleShape circle : Debug::circles)
        {
            window->draw(circle);
        }

        //Once we are done drawing, remove from the list
        Debug::rects.clear();
        Debug::lines.clear();
        Debug::circles.clear();
    }
}

SpriteRenderer* DrawManager::createSpriteRenderer(std::string name)
{
    SpriteRenderer* s = new SpriteRenderer(name);
    sprites.push_back(s);
    return s;
}

void DrawManager::drawSpriteRenderers(sf::RenderWindow* window)
{
    for (int i = 0; i < sprites.size(); i++)
    {
        sprites[i]->draw(window);
    }
}

