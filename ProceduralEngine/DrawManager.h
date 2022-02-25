#pragma once
#include "Debug.h"

#define PIXEL_PER_METER 2.0f;

class DrawManager
{
public:
	static int windowWidth;
	static int windowHeight;
	static sf::Vector2f convertToSF(b2Vec2 vec);
	static b2Vec2 convertToB2(sf::Vector2f vec);
	void DrawDebug(sf::RenderWindow* window);
};

