#pragma once
#include "Collider.h"

class BoxCollider :
    public Collider
{
public:
    BoxCollider(b2Vec2 size);
    void init() override;
    void DebugDraw();
    std::string toString() override;
private:
    b2Vec2 size;
};

