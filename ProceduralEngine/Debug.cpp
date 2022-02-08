#include "Debug.h"

vector<sf::RectangleShape> Debug::rects;
vector<array<sf::Vertex, 2>> Debug::lines;
vector<sf::CircleShape> Debug::circles;
void Debug::print(string s, bool ln)
{
	if (ln)
		cout << s << endl;
	else
		cout << s;
}

void Debug::print(sf::Vector2f vec, bool ln)
{
	if (ln)
		cout << "x: " << vec.x << " y: " << vec.y << endl;
	else
		cout << "x: " << vec.x << " y: " << vec.y;
}

void Debug::print(b2Vec2 vec, bool ln)
{
	if (ln)
		cout << "x: " << vec.x << " y: " << vec.y << endl;
	else
		cout << "x: " << vec.x << " y: " << vec.y;
}

/// <summary>
/// Draws a square to the window
/// </summary>
/// <param name="pos">position</param>
/// <param name="size">size of square</param>
/// <param name="color">Color of the square</param>
void Debug::DrawSquare(b2Vec2 pos, float size, sf::Color color)
{
	Debug::DrawRectangle(pos, size, size, color);
}
/// <summary>
/// Draws a line to the window
/// </summary>
/// <param name="p1">Start</param>
/// <param name="p2">End</param>
/// <param name="color">Color of the line</param>
void Debug::DrawLine(b2Vec2 p1, b2Vec2 p2, sf::Color color)
{
	array<sf::Vertex, 2> arr{ sf::Vertex(DrawManager::convertToSF(p1), color), sf::Vertex(DrawManager::convertToSF(p2), color)};
	lines.push_back(arr);
}

/// <summary>
/// Draws a circle to the window
/// </summary>
/// <param name="pos">Position</param>
/// <param name="radius">Radius of the circle</param>
/// <param name="color">Color of the circle</param>
void Debug::DrawCircle(b2Vec2 pos, float radius, sf::Color color)
{
	radius *= PIXEL_PER_METER;
	sf::CircleShape circle(radius);
	circle.setOrigin(radius / 2, radius / 2);
	circle.setPosition(DrawManager::convertToSF(pos));
	circle.setFillColor(color);
	circles.push_back(circle);
}

/// <summary>
/// Draws a rectangle to the window
/// </summary>
/// <param name="pos"></param>
/// <param name="width"></param>
/// <param name="height"></param>
/// <param name="color"></param>
void Debug::DrawRectangle(b2Vec2 pos, float width, float height, sf::Color color)
{
	width *= PIXEL_PER_METER;
	height *= PIXEL_PER_METER;
	sf::RectangleShape rect(sf::Vector2f(width, height));
	rect.setFillColor(color);
	rect.setOrigin(sf::Vector2f(width / 2, height / 2));
	rect.setPosition(DrawManager::convertToSF(pos));
	rects.push_back(rect);
}
