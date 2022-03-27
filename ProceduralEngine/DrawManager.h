#pragma once
#include "Debug.h"
#include "SpriteRenderer.h"

#define PIXEL_PER_METER 30.0f;
class SpriteRenderer;
class DrawManager
{
public:
	static int windowWidth;
	static int windowHeight;
	static sf::Vector2f convertToSF(b2Vec2 vec);
	static b2Vec2 convertToB2(sf::Vector2f vec);
	void DrawDebug(sf::RenderWindow* window);
	SpriteRenderer* createSpriteRenderer(std::string name);
	void drawSpriteRenderers(sf::RenderWindow* window);
private:
	std::vector<SpriteRenderer*> sprites;

};

