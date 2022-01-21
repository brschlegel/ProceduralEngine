#include "Random.h"

std::minstd_rand Random::rng;

/// <summary>
/// Seeds the generator
/// </summary>
/// <param name="seed">Seed for the generator. Leave blank for random seed</param>
void Random::seedGenerator(int seed)
{
	//If they didn't specify a seed, use the time
	if (seed == 0)
	{
		seed = chrono::system_clock::now().time_since_epoch().count();
	}
	Random::rng.seed(seed);
}
//TODO: Cache distributions somewhere?

/// <summary>
/// Returns a random int from [min, max), max is exlcuded
/// </summary>
/// <param name="min">Included min</param>
/// <param name="max">Excluded max</param>
/// <returns>Random Int</returns>
int Random::generateRandomInt(int min, int max)
{
	uniform_int_distribution<int> dist(min, max-1);
	return dist(Random::rng);
}
//Separate method because putting the default parameter at the end wouldn't really make sense

/// <summary>
/// Returns a random int from [0,max), max is excluded
/// </summary>
/// <param name="max">Excluded max</param>
/// <returns>Random int</returns>
int Random::generateRandomInt(int max)
{
	uniform_int_distribution<int> dist(0, max-1);
	return dist(Random::rng);
}

/// <summary>
/// Generates real number between min and max, technically inclusive
/// </summary>
/// <param name="min">Minimum</param>
/// <param name="max">Maximum</param>
/// <returns></returns>
float Random::generateRandomReal(int min, int max)
{
	uniform_real_distribution<float> dist(min, max);
	return dist(Random::rng);
}

/// <summary>
/// Generates random real number between 0 and 1
/// </summary>
/// <returns></returns>
float Random::generateRandomValue()
{
	uniform_real_distribution<float> dist(0, 1);
	return dist(Random::rng);
}

/// <summary>
/// Generates a value based on a normal distribution
/// </summary>
/// <param name="mean">Mean of the distribution</param>
/// <param name="stdDev">Standard Deviation of the distribution</param>
/// <returns>float value</returns>
float Random::generateNormalValue(float mean, float stdDev)
{
	normal_distribution<float> dist(mean, stdDev);
	return dist(Random::rng);
}


