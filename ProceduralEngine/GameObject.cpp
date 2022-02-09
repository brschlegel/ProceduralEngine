#include "GameObject.h"
#include <iostream>

GameObject::GameObject() {
	setName("GameObject");
	components = std::vector<Component>();
}

std::string GameObject::getName() { return name; }

void GameObject::setName(std::string _name) { name = _name; }

Transform* GameObject::getTransform() { return &transform; }

void GameObject::setTransform(Transform _transform) { transform = _transform; }

Component GameObject::addComponent(Component _component)
{
	components.push_back(_component);
	return _component;
}
