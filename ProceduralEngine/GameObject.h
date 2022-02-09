#pragma once
#include <vector>
#include "Component.h"
#include "Transform.h"

class GameObject
{
public:
	GameObject();

	// Getter and Setters for the name and transform of the GameObject
	std::string getName();
	void setName(std::string _name);

	Transform* getTransform();
	void setTransform(Transform _transform);

	// Add a component to the GameObject. Returns the component being added.
	Component addComponent(Component _component);

	// Gets a component of the requested type if it exists. Returns 'nullptr' if a component is not found.
	template <class Type> Component* getComponent() {
		for (int i = 0; i < components.size(); i++) {
			if (typeid(Type) == typeid(components[i])) {
				return &components[i];
			}
		}

		return nullptr;
	}

private:
	std::string name;
	Transform transform;
	std::vector<Component> components;
};