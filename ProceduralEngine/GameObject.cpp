#include "GameObject.h"
#include <iostream>
#include "Script.h"

GameObject::GameObject(std::string _name, GameObject* _parent) {
	name = _name;
	tag = "None";
	enabled = true;
	transform = new Transform(this);
	parent = _parent;
	children = std::vector<GameObject*>();
	components = std::vector<Component*>();

	components.push_back(transform);

	if (parent != nullptr) {
		parent->children.push_back(this);
	}
}

GameObject::~GameObject()
{
	parent = nullptr;

	for (int i = 0; i < components.size(); i++) {

		delete components[i];
		components[i] = nullptr;
	}

	for (GameObject* child : children) {
		delete child;
		child = nullptr;
	}
}

GameObject::GameObject(const GameObject& _other)
{
	name = _other.name;
	tag = _other.tag;
	enabled = _other.enabled;
	parent = _other.parent;
	transform = new Transform(*_other.transform);
	children = std::vector<GameObject*>();
	components = std::vector<Component*>();

	for (Component* component : _other.components) {
		// This line will be used to check then push a type
		// 		if (dynamic_cast<Type*>(component) != nullptr) {
		//			components.push_back(new Type(*static_cast<Type*>(component)));
		//		}
		if (dynamic_cast<Transform*>(component) != nullptr) {
			components.push_back(transform);
		}
		else if (dynamic_cast<SpriteRenderer*>(component) != nullptr) {
			addComponent(new SpriteRenderer(*static_cast<SpriteRenderer*>(component)));
		}
		else if (dynamic_cast<Script*>(component) != nullptr) {
			addComponent(new Script(*static_cast<Script*>(component)));
		}
	}

	for (GameObject* child : _other.children) {
		children.push_back(new GameObject(*child));
	}
}

GameObject& GameObject::operator=(const GameObject& _other)
{
	if (this != &_other) {
		if (parent != nullptr) { delete parent; }

		for (Component* component : components) {
			delete component;
		}

		for (GameObject* child : children) {
			delete child;
		}

		name = _other.name;
		tag = _other.tag;
		enabled = _other.enabled;
		parent = _other.parent;
		transform = new Transform(*_other.transform);

		for (Component* component : _other.components) {
			// This block will be used to check then push a new component
			// 		if (dynamic_cast<Type*>(component) != nullptr) {
			//			components.push_back(new Type(*static_cast<Type*>(component)));
			//		}
			if (dynamic_cast<Transform*>(component) != nullptr) {
				components.push_back(transform);
			}
			else if (dynamic_cast<SpriteRenderer*>(component) != nullptr) {
				addComponent(new SpriteRenderer(*static_cast<SpriteRenderer*>(component)));
			}
			else if (dynamic_cast<Script*>(component) != nullptr) {
				addComponent(new Script(*static_cast<Script*>(component)));
			}
		}

		for (GameObject* child : _other.children) {
			children.push_back(new GameObject(*child));
		}
	}

	return *this;
}

std::string GameObject::toString() { return "Name: " + name + "\n"; }

std::string GameObject::getName() { return name; }

void GameObject::setName(std::string _name) { name = _name; }

std::string GameObject::getTag() { return tag; }

void GameObject::setTag(std::string _tag) { tag = _tag; }

Transform* GameObject::getTransform() { return transform; }

void GameObject::setTransform(Transform* _transform) {
	setTransform(_transform->getPosition(), _transform->getRotation(), _transform->getScale());
}

void GameObject::setTransform(b2Vec2 _position, b2Rot _rotation, b2Vec2 _scale)
{
	transform->setPosition(_position);
	transform->setRotation(_rotation);
	transform->setScale(_scale);
}

void GameObject::setTransform(float32 positionX, float32 positionY, float32 angle, float32 scaleX, float32 scaleY)
{
	transform->setPosition(positionX, positionY);
	transform->setRotation(angle);
	transform->setScale(scaleX, scaleY);
}

GameObject* GameObject::getParent()
{
	return parent;
}

unsigned int GameObject::getChildCount() { return children.size(); }

GameObject* GameObject::getChild(unsigned int index) { return index < children.size() ? children[index] : nullptr; }

GameObject* GameObject::getChildByName(std::string _name)
{
	for (GameObject* child : children) {
		if (child->name == _name) {
			return child;
		}
	}

	return nullptr;
}

GameObject* GameObject::getChildByTag(std::string _tag)
{
	for (GameObject* child : children) {
		if (child->tag == _tag) {
			return child;
		}
	}

	return nullptr;
}

Component* GameObject::addComponent(Component* _component)
{
	_component->setGameObject(this);
	_component->init();
	_component->start();
	components.push_back( _component);

	return _component;
}

void GameObject::start()
{
	for (Component* component : components) {
		// This block will be used to check then push a new component
		// 		if (dynamic_cast<Type*>(component) != nullptr) {
		//			components.push_back(new Type(*static_cast<Type*>(component)));
		//		}
		if (dynamic_cast<Transform*>(component) != nullptr) {
			transform->start();
		}
		else if (dynamic_cast<SpriteRenderer*>(component) != nullptr) {
			static_cast<SpriteRenderer*>(component)->start();
		}
		else if (dynamic_cast<Script*>(component) != nullptr) {
			static_cast<Script*>(component)->start();
		}
	}
}

void GameObject::update()
{
	for (Component* component : components) {
		// This block will be used to check then push a new component
		// 		if (dynamic_cast<Type*>(component) != nullptr) {
		//			components.push_back(new Type(*static_cast<Type*>(component)));
		//		}
		if (dynamic_cast<Transform*>(component) != nullptr) {
			transform->update();
		}
		else if (dynamic_cast<SpriteRenderer*>(component) != nullptr) {
			static_cast<SpriteRenderer*>(component)->update();
		}
		else if (dynamic_cast<Script*>(component) != nullptr) {
			static_cast<Script*>(component)->update();
		}
	}
}

void GameObject::fixedUpdate()
{
	for (Component* component : components) {
		// This block will be used to check then push a new component
		// 		if (dynamic_cast<Type*>(component) != nullptr) {
		//			components.push_back(new Type(*static_cast<Type*>(component)));
		//		}
		if (dynamic_cast<Transform*>(component) != nullptr) {
			transform->fixedUpdate();
		}
		else if (dynamic_cast<SpriteRenderer*>(component) != nullptr) {
			static_cast<SpriteRenderer*>(component)->fixedUpdate();
		}
		else if (dynamic_cast<Script*>(component) != nullptr) {
			static_cast<Script*>(component)->fixedUpdate();
		}
	}
}

void GameObject::onEnable()
{
	for (Component* component : components) {
		// This block will be used to check then push a new component
		// 		if (dynamic_cast<Type*>(component) != nullptr) {
		//			components.push_back(new Type(*static_cast<Type*>(component)));
		//		}
		if (dynamic_cast<Transform*>(component) != nullptr) {
			transform->onEnable();
		}
		else if (dynamic_cast<SpriteRenderer*>(component) != nullptr) {
			static_cast<SpriteRenderer*>(component)->onEnable();
		}
		else if (dynamic_cast<Script*>(component) != nullptr) {
			static_cast<Script*>(component)->onEnable();
		}
	}
}

void GameObject::onDisable()
{
	for (Component* component : components) {
		// This block will be used to check then push a new component
		// 		if (dynamic_cast<Type*>(component) != nullptr) {
		//			components.push_back(new Type(*static_cast<Type*>(component)));
		//		}
		if (dynamic_cast<Transform*>(component) != nullptr) {
			transform->onDisable();
		}
		else if (dynamic_cast<SpriteRenderer*>(component) != nullptr) {
			static_cast<SpriteRenderer*>(component)->onDisable();
		}
		else if (dynamic_cast<Script*>(component) != nullptr) {
			static_cast<Script*>(component)->onDisable();
		}
	}
}