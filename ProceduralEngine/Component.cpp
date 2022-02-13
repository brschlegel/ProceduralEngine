#include "Component.h"
#include <iostream>

Component::Component() 
{
	gameObject = nullptr;
}

Component::Component(GameObject* _gameObject) {
	gameObject = _gameObject;
}

Component::Component(const Component& _other)
{
}

Component::~Component() {
	gameObject = nullptr;
}

Component& Component::operator=(const Component& _other)
{
	return *this;
}

GameObject* Component::getGameObject() { return gameObject; }