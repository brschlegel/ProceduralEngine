#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "DrawManager.h"
#include <array>
using namespace std;

//Its kind of frustrating but I couldn't think of a way to generalize shapes and lines to be in one list, so they are going to have to be seperate lists
class Debug
{
public:
	static void print(string s, bool ln = true);
	static void print(sf::Vector2f vec, bool ln = true);
	static void print(b2Vec2 vec, bool ln = true);
	//Lists of objects to draw this frame. Gets cleared every frame
	static vector<sf::RectangleShape> rects;
	static vector<sf::CircleShape> circles;
	//We have to use a std::array object here instead of a pointer so it can be stored in a vector
	static vector<array<sf::Vertex, 2>> lines;
	//Methods to push the objects to the lists
	static void DrawSquare(b2Vec2 pos, float size, sf::Color color = sf::Color(255, 0, 0));
	static void DrawLine(b2Vec2 p1, b2Vec2 p2, sf::Color color = sf::Color(255, 0, 0));
	static void DrawCircle(b2Vec2 pos, float radius, sf::Color color = sf::Color(255, 0, 0));
	static void DrawRectangle(b2Vec2 pos, float width, float height, sf::Color color = sf::Color(255, 0, 0));
	//Draw flags
	static bool drawGrid;
	static bool drawDebug;
};

