#include "GameObject.h"
#include <iostream>

GameObject::GameObject() {
	components = std::vector<Component>();
}

template<class type> type GameObject::addComponent(type component)
{
	components.push_back(component);
	return component;
}

template<class type> type GameObject::getComponent()
{
	components.push_back(Component());
	for (int i = 0; i < components.size(); i++) {
		std::cout << i << std::endl;
		if (typeid(components[i]) == typeid(type)) {
			return components[i];
		}
	}
}