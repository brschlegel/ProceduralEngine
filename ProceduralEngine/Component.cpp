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

void Component::setGameObject(GameObject* _gameObject)
{
	gameObject = _gameObject;
}

void Component::init()
{
}

void Component::start()
{
}

void Component::update()
{
}

void Component::fixedUpdate()
{
}

void Component::onEnable()
{
}

void Component::onDisable()
{
}
