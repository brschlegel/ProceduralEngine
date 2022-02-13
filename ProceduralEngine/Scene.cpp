#include "Scene.h"

Scene::Scene(std::string _name) {
	name = _name;
	gameObjects = std::vector<GameObject*>();
}

std::string Scene::getName() { return name; }
void Scene::setName(std::string _name) { name = _name; }

GameObject* Scene::addGameObject(GameObject* _gameObject)
{
	gameObjects.push_back(_gameObject);
	return _gameObject;
}

GameObject* Scene::getGameObjectByName(std::string _name) {
	for (GameObject* gameObject : gameObjects) {
		if (gameObject->getName() == _name) {
			return gameObject;
		}
	}

	return nullptr;
}

GameObject* Scene::getGameObjectByTag(std::string _tag) {
	for (GameObject* gameObject : gameObjects) {
		if (gameObject->getTag() == _tag) {
			return gameObject;
		}
	}

	return nullptr;
}