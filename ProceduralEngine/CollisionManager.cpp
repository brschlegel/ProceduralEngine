#include "CollisionManager.h"

CollisionManager::CollisionManager()
{
}

BoxCollider* CollisionManager::createBoxCollider(b2Vec2 size)
{
	BoxCollider* c = new BoxCollider(size);
	boxColliders.push_back(c);
	return c;
}

void CollisionManager::update()
{
}
