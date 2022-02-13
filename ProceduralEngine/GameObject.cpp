#include "GameObject.h"
#include <iostream>

GameObject::GameObject() {
	name = "GameObject";
	tag = "None";
	enabled = true;
	transform = new Transform();
	components = std::vector<Component*>();
}

GameObject::~GameObject()
{
	delete transform;
	for (Component* component : components) {
		delete component;
	}
}

GameObject::GameObject(const GameObject& _other)
{
}

GameObject& GameObject::operator=(const GameObject& _other)
{
	return *this;
}

std::string GameObject::getName() { return name; }

void GameObject::setName(std::string _name) { name = _name; }

std::string GameObject::getTag() { return tag; }

void GameObject::setTag(std::string _tag) { tag = _tag; }

Transform* GameObject::getTransform() { return transform; }

void GameObject::setTransform(Transform* _transform) { transform = _transform; }

Component* GameObject::addComponent(Component* _component)
{
	components.push_back(_component);
	return _component;
}

void GameObject::start()
{
}

void GameObject::update()
{
}

void GameObject::fixedUpdate()
{
}

void GameObject::onEnable()
{
}

void GameObject::onDisable()
{
}
