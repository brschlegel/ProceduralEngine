#include "Component.h"

Component::Component() {
	setName("Component");
}

std::string Component::getName() { return name; }

void Component::setName(std::string _name) { name = _name; }

GameObject* Component::getGameObject() { return gameObject; }