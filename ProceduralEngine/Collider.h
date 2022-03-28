#pragma once
#include "GameObject.h"
#include "Delegate.h"
class Collider :
    public Component
{
public:
    bool CheckCollision(Collider* other);
    void OnCollision(Collider* other);
    b2AABB getAABB();
    b2Shape* getShape();
    virtual void debugDraw() = 0;
    MulticastDelegate<Collider*> onCollisionDelegate;
protected:
    b2Shape* shape;
};

