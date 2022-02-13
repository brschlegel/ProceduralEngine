#pragma once
#include "GameObject.h"
#include <vector>
#include <string>

class Scene
{
public:
	// -------------------------------
	//			CONSTRUCTORS
	// -------------------------------

	Scene(std::string _name);

	// ----------------------------
	//			RULE OF 3
	// ----------------------------

	~Scene();

	Scene(const Scene& _other);

	Scene& operator = (const Scene& _other);

	// -------------------------------------
	//			SCENE METHODS
	// -------------------------------------



private:
	std::vector<GameObject*> gameObjects;
	std::string name;
};

