#pragma once
#include "GameObject.h"
class Collider :
    public Component
{
public:
    bool CheckCollision(Collider* other);
    void OnCollision(Collider* other);
    b2AABB getAABB();
    b2Shape* getShape();
protected:
    b2Shape* shape;
};

