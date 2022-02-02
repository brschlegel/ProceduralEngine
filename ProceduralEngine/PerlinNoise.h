#pragma once
#include <chrono>
#include <random>
#include <array>
#include <algorithm>
#include "PMath.h"

//Implemenation based on https://rtouti.github.io/graphics/perlin-noise-algorithm and https://github.com/sol-prog/Perlin_Noise/blob/master/PerlinNoise.cpp

using namespace std;
class PerlinNoise
{
public:
	PerlinNoise(int seed = 0);
	float sample(float x, float y);
private:
	//Using std::array here instead of standard pointer so that I can use the std::shuffle method
	array<int, 256> p;
	array<int, 512> permutation;
	b2Vec2 getConstantVector(int v);
};

