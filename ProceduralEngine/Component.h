#pragma once
#include <string>

class GameObject; // Forward declaring GameObject for use within the Component class
class Component
{
public:
	Component();

	// Getters for the name and attached GameObject and a setter for the name
	std::string getName();
	void setName(std::string _name);

	GameObject* getGameObject();

protected:
	std::string name;
	GameObject* gameObject;
};