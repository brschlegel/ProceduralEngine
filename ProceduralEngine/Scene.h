#pragma once
#include <vector>
#include <string>
#include "GameObject.h"

class Scene
{
public:
	// -------------------------------
	//			CONSTRUCTORS
	// -------------------------------

	Scene(std::string _name = "Scene");

	// ----------------------------
	//			RULE OF 3
	// ----------------------------

	~Scene();

	Scene(const Scene& _other);

	Scene& operator = (const Scene& _other);

	// ---------------------------------
	//			SCENE METHODS
	// ---------------------------------

	std::string getName();
	void setName(std::string _name);

	// Add a component to the GameObject. Returns the component being added.
	GameObject* addGameObject(GameObject* _gameObject);

	// Gets a GameObject with the given name if it exists. Returns 'nullptr' if a GameObject is not found.
	GameObject* getGameObjectByName(std::string _name);
	GameObject* getGameObjectByTag(std::string _tag);

private:
	std::vector<GameObject*> gameObjects;
	std::string name;
};

