#pragma once
#include <string>

class GameObject; // Forward declaring GameObject for use within the Component class
class Component
{
public:
	Component(GameObject* _gameObject);

	~Component();

	// Getter for the GameObject this Component is attached to
	GameObject* getGameObject();

protected:
	std::string name;
	GameObject* gameObject;
};