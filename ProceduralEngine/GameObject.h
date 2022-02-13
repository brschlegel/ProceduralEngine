#pragma once
#include <vector>
#include "Component.h"
#include "Transform.h"
#include "IScriptable.h"

class GameObject : public IScriptable
{
public:

	// -------------------------------
	//			CONSTRUCTORS
	// -------------------------------

	GameObject();

	// ----------------------------
	//			RULE OF 3
	// ----------------------------

	~GameObject();

	GameObject(const GameObject& _other);

	GameObject& operator = (const GameObject& _other);

	// -------------------------------------
	//			GAMEOBJECT METHODS
	// -------------------------------------

	// Getters and Setters for the name, tag, and transform of the GameObject
	std::string getName();
	void setName(std::string _name);

	std::string getTag();
	void setTag(std::string _tag);

	Transform* getTransform();
	void setTransform(Transform* _transform);

	// Add a component to the GameObject. Returns the component being added.
	Component* addComponent(Component* _component);

	// CODE STUB TO BE IMPLEMENTED AFTER SCENES ARE CREATED
	// Scene getScene() { return scene; }
	
	// Gets a component of the requested type if it exists. Returns 'nullptr' if a component is not found.
	template <class Type> Component* getComponent() {
		for (int i = 0; i < components.size(); i++) {
			if (typeid(Type) == typeid(components[i])) {
				return components[i];
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
	Transform* transform;
	std::vector<Component*> components;
	bool enabled;
	// Reference to the scene this object is in
};