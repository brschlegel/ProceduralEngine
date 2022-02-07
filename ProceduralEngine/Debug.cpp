#include "Debug.h"

vector<sf::RectangleShape> Debug::rects;
//vector<sf::Vertex[]> Debug::lines;
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

void Debug::DrawSquare(b2Vec2 pos, float size, sf::Color color)
{
	size *= PIXEL_PER_METER;
	sf::RectangleShape rect(sf::Vector2f(size, size));
	rect.setFillColor(color);
	rect.setOrigin(sf::Vector2f(size / 2, size / 2));
	rect.setPosition(DrawManager::convertToSF(pos));
	rects.push_back(rect);
}

void Debug::DrawLine(b2Vec2 p1, b2Vec2 p2, sf::Color color)
{
}
