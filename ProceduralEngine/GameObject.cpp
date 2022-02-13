#include "GameObject.h"
#include <iostream>

GameObject::GameObject(Scene* _scene, std::string _name) {
	name = _name;
	tag = "None";
	enabled = true;
	transform = Transform(this);
	scene = _scene;
	components = std::vector<Component*>();
}

GameObject::~GameObject()
{
	for (Component* component : components) {
		delete component;
		component = nullptr;
	}
}

GameObject::GameObject(const GameObject& _other)
{
}

GameObject& GameObject::operator=(const GameObject& _other)
{
	if (this == &_other)
		return *this;

	for (Component* component : components) {
		delete component;
	}

	components = _other.components;

	return *this;
}

std::string GameObject::getName() { return name; }

void GameObject::setName(std::string _name) { name = _name; }

std::string GameObject::getTag() { return tag; }

void GameObject::setTag(std::string _tag) { tag = _tag; }

Transform GameObject::getTransform() { return transform; }

void GameObject::setTransform(Transform _transform) { transform = _transform; }

void GameObject::setTransform(b2Vec2 _position, b2Rot _rotation, b2Vec2 _scale)
{
	transform.setPosition(_position);
	transform.setRotation(_rotation);
	transform.setScale(_scale);
}

void GameObject::setTransform(float32 positionX, float32 positionY, float32 angle, float32 scaleX, float32 scaleY)
{
	transform.setPosition(positionX, positionY);
	transform.setRotation(angle);
	transform.setScale(scaleX, scaleY);
}

Scene* GameObject::getScene() { return scene; }

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
