#pragma once
#include <Box2D/Box2D.h>

/// <summary>
/// An extension of b2Transform. The b2Transform class has limited functionality, so creating
/// a Tranform class that extends it will allow for additional functionality and flexibility.
/// The b2Transform class only has position and rotation, so Transform adds scale as a 2D vector.
/// </summary>
class Transform : public b2Transform
{
public:
	// Getters and Setters for position, rotation, and scale
	b2Vec2 getPosition();
	void setPosition(b2Vec2 _position);

	b2Rot getRotation();
	void setRotation(b2Rot _rotation);

	b2Vec2 getScale();
	void setScale(b2Vec2 _scale);

private:
	b2Vec2 position;
	b2Rot rotation;
	b2Vec2 scale;
};

