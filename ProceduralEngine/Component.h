#pragma once
#include <string>
#include "IScriptable.h"

class GameObject; // Forward declaring GameObject for use within the Component class
class Component : public IScriptable
{
public:
	// -------------------------------
	//			CONSTRUCTORS
	// -------------------------------

	Component();
	Component(GameObject* _gameObject);

	// ----------------------------
	//			RULE OF 3
	// ----------------------------

	~Component();

	Component(const Component& _other);

	Component& operator = (const Component& _other);

	// -------------------------------------
	//			COMPONENT METHODS
	// -------------------------------------

	// The GameObject this Component is attached to
	GameObject* getGameObject();
	void setGameObject(GameObject* _gameObject);

	virtual std::string toString() = 0;
	/// <summary>
	/// Called after setting the gameobject, so we can get data from that 
	/// </summary>
	virtual void init();

	virtual void start() override;
	virtual void update() override;
	virtual void fixedUpdate() override;
	virtual void onEnable() override;
	virtual void onDisable() override;

protected:
	GameObject* gameObject;
};