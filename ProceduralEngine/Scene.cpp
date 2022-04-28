#include "Scene.h"
#include <iostream>

Scene::Scene(std::string _name) {
	name = _name;
	gameObjects = std::vector<GameObject*>();
}

std::string Scene::getName() { return name; }
void Scene::setName(std::string _name) { name = _name; }

GameObject* Scene::addGameObject(GameObject* _gameObject)
{
	gameObjects.push_back(_gameObject);
	_gameObject->start();
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

void Scene::destroyGameObject(GameObject* g)
{
	std::vector<GameObject*>::iterator it = std::find(gameObjects.begin(), gameObjects.end(), g);
	if (it != gameObjects.end())
	{
		//There has to be a better way of doing this
		SpriteRenderer* sprite = g->getComponent<SpriteRenderer>();
		if(sprite != nullptr)
			drawManager.deleteSpriteRenderer(sprite);
		BoxCollider* box = g->getComponent<BoxCollider>();
		if (box != nullptr)
			collisionManager.deleteBoxCollider(box);

		gameObjects.erase(it);
		delete g;
	}
}

void Scene::update(sf::RenderWindow* window)
{
	if (Debug::drawColliders)
	{
		collisionManager.DrawDebug();
	}
	collisionManager.update();
	drawManager.DrawDebug(window);
	drawManager.drawSpriteRenderers(window);
	int i = 0;
	for (GameObject* g : gameObjects)
	{
		g->update();
		i++;
	}

}

Scene::~Scene()
{
	for (int i = 0; i < gameObjects.size(); i++) {
		// Remove any children of GameObjects in the scene from the list
		// WITHOUT deleting them. The parent GameObjects are responsible
		// for deleting children.
		if (gameObjects[i]->getChildCount() > 0) {
			for (int j = 1; j <= gameObjects[i]->getChildCount(); j++) {
				gameObjects[i + j] = nullptr;
				gameObjects.erase(gameObjects.begin() + i + j);
			}
		}

		// After any children of the current GameObject are removed, delete the parent.
		// This will delete the parent and all of its children.
		delete gameObjects[i];
		gameObjects[i] = nullptr;
	}
}

Scene::Scene(const Scene& _other)
{
	gameObjects = std::vector<GameObject*>();
	
	for (GameObject* gameObject : _other.gameObjects) {
		gameObjects.push_back(new GameObject(*gameObject));
	}

	name = _other.name;
	drawManager = _other.drawManager;
	collisionManager = _other.collisionManager;
	scriptManager = _other.scriptManager;
}

Scene& Scene::operator=(const Scene& _other)
{
	if (this != &_other) {

		for (GameObject* gameObject : gameObjects) {
			delete gameObject;
		}

		for (GameObject* gameObject : _other.gameObjects) {
			gameObjects.push_back(new GameObject(*gameObject));
		}

		name = _other.name;
		drawManager = _other.drawManager;
		collisionManager = _other.collisionManager;
		scriptManager = _other.scriptManager;
	}

	return *this;
}