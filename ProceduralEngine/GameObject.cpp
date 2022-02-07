#include "GameObject.h"

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
	for (int i = components.begin(); i < components.end(); i++) {
		if (typeid(components[i]) == typeid(type)) {
			return components[i];
		}
	}
}

void IScriptable::start() {

}

void IScriptable::update() {

}

void IScriptable::fixedUpdate() {

}