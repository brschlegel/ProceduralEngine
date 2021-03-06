#pragma once
#include <Box2D/Box2D.h>
#include "Component.h"
#include "PMath.h"

/// <summary>
/// An extension of b2Transform. The b2Transform class has limited functionality, so creating
/// a Tranform class that extends it will allow for additional functionality and flexibility.
/// The b2Transform class only has position and rotation, so Transform adds scale as a 2D vector.
/// </summary>
class Transform : public Component
{
public:
	// -------------------------------
	//			CONSTRUCTORS
	// -------------------------------

	Transform();
	Transform(GameObject* _gameObject);

	// -------------------------------------
	//			TRANSFORM METHODS
	// -------------------------------------

	/// <summary>
	/// Get the position of the transform.
	/// </summary>
	b2Vec2 getPosition();

	/// <summary>
	/// Set the position of the transform.
	/// </summary>
	void setPosition(b2Vec2 _position);
	void setPosition(float32 x, float32 y);

	/// <summary>
	/// Get the rotation of the transform.
	/// </summary>
	b2Rot getRotation();

	/// <summary>
	/// Set the rotation of the transform.
	/// </summary>
	void setRotation(b2Rot _rotation);
	void setRotation(float32 angle);

	/// <summary>
	/// Get the scale of the transform.
	/// </summary>
	b2Vec2 getScale();

	/// <summary>
	/// Set the scale of the transform.
	/// </summary>
	void setScale(b2Vec2 _scale);
	void setScale(float32 x, float32 y);

	/// <summary>
	/// A string representation of a transform
	/// </summary>
	std::string toString();

	/// <summary>
	/// Makes a b2Transform from the information here
	/// </summary>
	b2Transform getb2Transform();

private:
	b2Vec2 position;
	b2Rot rotation;
	b2Vec2 scale;
};

