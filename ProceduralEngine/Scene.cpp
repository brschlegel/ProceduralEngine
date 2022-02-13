#include "Scene.h"

Scene::Scene(std::string _name)
{
    name = _name;
    gameObjects = std::vector<GameObject*>();
}

Scene::~Scene()
{
    for (GameObject* gameObject : gameObjects) {
        delete gameObject;
    }
}

Scene::Scene(const Scene& _other)
{
}

Scene& Scene::operator=(const Scene& _other)
{
    return *this;
}
