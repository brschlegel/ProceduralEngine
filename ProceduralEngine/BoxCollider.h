#pragma once
#include "Collider.h"

class BoxCollider :
    public Collider
{
public:
   
    void init() override;
    void DebugDraw();
    std::string toString() override;
private:
    b2Vec2 size;
    BoxCollider(b2Vec2 size);
    friend class CollisionManager;
};

