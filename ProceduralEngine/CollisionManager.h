#pragma once
#include "BoxCollider.h"
#include <Box2D/Box2D.h>

class CollisionManager
{
public:
	CollisionManager();
	BoxCollider* createBoxCollider(b2Vec2 size);
	void update();
	void DrawDebug();
private:
	vector<Collider*> colliders;
};

