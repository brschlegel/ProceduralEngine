#pragma once
#include <Box2D/Box2D.h>
using namespace std;
class PMath
{
public:
	static float fade(float t);
	static float lerp(float a, float b, float t);
	static float dot(b2Vec2 a, b2Vec2 b);
	static float radToDeg(float radians);
	static float degToRad(float degrees);
	static float clamp(float num, float min, float max);
};

