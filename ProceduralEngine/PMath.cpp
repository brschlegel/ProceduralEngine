#include "PMath.h"

//Implementation from https://rtouti.github.io/graphics/perlin-noise-algorithm
/// <summary>
/// Easing function used by Perlin noise. 
/// </summary>
/// <param name="t">Variable to be eased</param>
/// <returns></returns>
float PMath::fade(float t)
{
    return ((6 * t - 15) * t + 10) * t * t * t;
}

/// <summary>
/// Lerping function
/// </summary>
/// <param name="a">First value</param>
/// <param name="b">Second value</param>
/// <param name="t">How far between we are</param>
/// <returns></returns>
float PMath::lerp(float a, float b, float t)
{
    return a + t * (b - a);
}

float PMath::dot(b2Vec2 a, b2Vec2 b)
{
    return a.x * b.x + a.y * b.y;
}

float PMath::radToDeg(float radians)
{
    return radians / b2_pi * 180.f;
}
