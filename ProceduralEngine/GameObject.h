#pragma once
#include <vector>
#include <map>
#include "Component.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "IScriptable.h"
#include "Debug.h"


class GameObject : public IScriptable
{
public:

	// -------------------------------
	//			CONSTRUCTORS
	// -------------------------------

	GameObject(std::string _name = "GameObject", GameObject* parent = nullptr);

	// ----------------------------
	//			RULE OF 3
	// ----------------------------

	~GameObject();

	GameObject(const GameObject& _other);

	GameObject& operator = (const GameObject& _other);

	// -------------------------------------
	//			GAMEOBJECT METHODS
	// -------------------------------------

	std::string toString();

	std::string getName();
	void setName(std::string _name);

	std::string getTag();
	void setTag(std::string _tag);

	Transform* getTransform();
	void setTransform(Transform* _transform);
	void setTransform(b2Vec2 _position, b2Rot _rotation, b2Vec2 _scale);
	void setTransform(float32 positionX, float32 positionY, float32 angle, float32 scaleX, float32 scaleY);

	GameObject* getParent();

	unsigned int getChildCount();

	GameObject* getChild(unsigned int index);
	GameObject* getChildByName(std::string _name);
	GameObject* getChildByTag(std::string _tag);

	// Add a component to the GameObject. Returns the component being added.
	Component* addComponent(Component* _component);
	
	// Gets a component of the requested type if it exists. Returns 'nullptr' if a component is not found.
	template <class Type> Type* getComponent() {
		for (Component* component : components) {
			Type* cast = dynamic_cast<Type*>(component);
			if ( cast!= nullptr) {
				return cast;
			}
		}

		return nullptr;
	}

	// --------------------------------------------
	// DECLARING METHODS FROM ISCRIPTABLE INTERFACE
	// --------------------------------------------

	void start();
	void update();
	void fixedUpdate();
	void onEnable();
	void onDisable();

private:
	std::string name;
	std::string tag;
	bool enabled;
	Transform* transform;
	GameObject* parent;
	std::vector<GameObject*> children;
	std::vector<Component*> components;
};