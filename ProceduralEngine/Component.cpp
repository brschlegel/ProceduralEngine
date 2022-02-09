#include "Component.h"

Component::Component(GameObject* _gameObject) {
	name = "Component";
	gameObject = _gameObject;
}

Component::~Component() {
	delete gameObject;
}

std::string Component::getName() { return name; }

void Component::setName(std::string _name) { name = _name; }

GameObject* Component::getGameObject() { return gameObject; }