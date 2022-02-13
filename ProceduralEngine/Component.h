#pragma once
#include <string>

class GameObject; // Forward declaring GameObject for use within the Component class
class Component
{
public:
	// -------------------------------
	//			CONSTRUCTORS
	// -------------------------------

	Component(GameObject* _gameObject);

	// ----------------------------
	//			RULE OF 3
	// ----------------------------

	~Component();

	Component(const Component& _other);

	Component& operator = (const Component& _other);

	// -------------------------------------
	//			COMPONENT METHODS
	// -------------------------------------

	// Getter for the GameObject this Component is attached to
	GameObject* getGameObject();

protected:
	GameObject* gameObject;
};