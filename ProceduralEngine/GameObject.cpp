#include "GameObject.h"
#include <iostream>

GameObject::GameObject() {
	name = "GameObject";
	tag = "None";
	transform = Transform();
	components = std::vector<Component>();
}

std::string GameObject::getName() { return name; }

void GameObject::setName(std::string _name) { name = _name; }

std::string GameObject::getTag() { return tag; }

void GameObject::setTag(std::string _tag) { tag = _tag; }

Transform GameObject::getTransform() { return transform; }

void GameObject::setTransform(Transform _transform) { transform = _transform; }

Component GameObject::addComponent(Component _component)
{
	components.push_back(_component);
	return _component;
}
