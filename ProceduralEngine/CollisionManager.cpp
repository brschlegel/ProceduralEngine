#include "CollisionManager.h"


bool Debug::drawColliders;
CollisionManager::CollisionManager()
{
}

BoxCollider* CollisionManager::createBoxCollider(b2Vec2 size)
{
	BoxCollider* c = new BoxCollider(size);
	colliders.push_back(c);
	return c;
}

void CollisionManager::deleteBoxCollider(BoxCollider* b)
{
	auto it = std::find(colliders.begin(), colliders.end(), b);
	if (it != colliders.end())
	{
		colliders.erase(it);
	}
}

void CollisionManager::update()
{
	for (int i = 0; i < colliders.size(); i++)
	{
		for (int j = 0; j < colliders.size(); j++)
		{
			if (i < j)
			{
				if(colliders[i]->CheckCollision(colliders[j]))
				{
					colliders[i]->OnCollision(colliders[j]);
					colliders[j]->OnCollision(colliders[i]);
				}
			}
		}
	}
}

void CollisionManager::DrawDebug()
{
	for (int i = 0; i < colliders.size(); i++)
	{
		colliders[i]->debugDraw();
	}
}
