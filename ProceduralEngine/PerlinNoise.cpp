#include "PerlinNoise.h"

//Not using the static random class here so the seed is indepedent
PerlinNoise::PerlinNoise(int seed)
{
	if (seed == 0)
	{
		seed =  chrono::system_clock::now().time_since_epoch().count();
	}

	for (int i = 0; i < 256; i++)
	{
		p[i] = i;
	}
	//shuffles the permutation table
	minstd_rand engine = minstd_rand(seed);
	shuffle(p.begin(), p.end(),engine );
	//Doubling the array, allowing for wrapping
	for (int i = 0; i < 256; i++)
	{
		permutation[i] = p[i];
	}
	for (int i = 0; i < 256; i++)
	{
		permutation[256 + i] = p[i];
	}
}

float PerlinNoise::sample(float x, float y)
{
	//Find the coords of the unit sqaure that contains the point
	int X = (int)floor(x) & 255;
	int Y = (int)floor(y) & 255;
	
	//Find the relative position
	float xf = x - floor(x);
	float yf = y - floor(y);

	b2Vec2 topRight = b2Vec2(xf - 1.0f, yf - 1.0f);
	b2Vec2 topLeft = b2Vec2(xf, yf - 1.0f);
	b2Vec2 bottomRight = b2Vec2(xf - 1.0f, yf);
	b2Vec2 bottomLeft = b2Vec2(xf, yf);

	//Select the values for each corner from the permutations
	//The reason this looks so weird, is that no matter where the corner is relative to our grid space, it must have the same value. IE: valueBottomRight at (0,0) must equal valueBottomLeft at (1,0)
	int valueTopRight = permutation[permutation[X + 1] + Y + 1];
	int valueTopLeft = permutation[permutation[X] + Y + 1];
	int valueBottomRight = permutation[permutation[X + 1] + Y];
	int valueBottomLeft = permutation[permutation[X] + Y];

	//Get the dot products
	float dotTopRight = PMath::dot(topRight, getConstantVector(valueTopRight));
	float dotTopLeft = PMath::dot(topLeft, getConstantVector(valueTopLeft));
	float dotBottomRight = PMath::dot(bottomRight, getConstantVector(valueBottomRight));
	float dotBottomLeft = PMath::dot(bottomLeft, getConstantVector(valueBottomLeft));

	//combine all those values to get one value
	float u = PMath::fade(xf);
	float v = PMath::fade(yf);
	return PMath::lerp(u, PMath::lerp(v, dotBottomLeft, dotTopLeft), PMath::lerp(v, dotBottomRight, dotTopRight));
}

b2Vec2 PerlinNoise::getConstantVector(int v)
{
	int h = v & 3;
	switch (h) {
	case 0:
		return b2Vec2(1.0f, 1.0f);
		break;
	case 1:
		return b2Vec2(-1.0f, 1.0f);
		break;
	case 2:
		return b2Vec2(-1.0f, -1.0f);
		break;
	default:
		return b2Vec2(1.0f, -1.0f);
	}

}


