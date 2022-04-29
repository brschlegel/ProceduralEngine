#pragma once
#include "GameObject.h"
#include <map>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "DrawManager.h"
#include "PMath.h"

class DrawManager;
class SpriteRenderer :
    public Component
{
public:
   
    void draw(sf::RenderWindow* window);
    //We have seperate setScale and setRotation methods because I would assume that scale and rotation often don't need to be set every frame
    void setScale(b2Vec2 scale);
    void setRotation(b2Rot rotation);
    void setSprite(std::string name);
    void init();
    std::string toString();
    static void unloadTextures();
private:
    static std::map<std::string, sf::Texture*> textureMap;
    sf::Sprite sprite;
    /// <summary>
   /// Constructor 
   /// </summary>
   /// <param name="name">Name of file. Leave off the .png</param>
    SpriteRenderer(std::string name);
    friend class DrawManager;
};

