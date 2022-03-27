#pragma once
#include "BoxCollider.h"
class CollisionManager
{
public:
	CollisionManager();
	BoxCollider* createBoxCollider(b2Vec2 size);
	void update();
private:
	vector<BoxCollider*> boxColliders;
};

