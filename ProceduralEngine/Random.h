#pragma once
#include <random>
#include <chrono>

//Going with the linear congruential engine instead of the mersenne twister as we really don't need a super large period, nor that random of numbers
//https://stackoverflow.com/questions/16536617/random-engine-differences
using namespace std;
class Random
{
public:

	static void seedGenerator(int seed = 0);
	static int generateRandomInt(int min, int max);
	static int generateRandomInt(int max);
	static float generateRandomReal(int min, int max);
	static float generateRandomValue();
	static float generateNormalValue(float mean, float stdDev);
	static minstd_rand getEngine();
private:
	static minstd_rand rng;
};

