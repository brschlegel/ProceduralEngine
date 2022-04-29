#pragma once
#include "Script.h"
#include "BoxCollider.h";
#include "Time.h";
class Ball :
    public Script
{
public:
    Ball();
    void start() override;
    void update() override;
    void handleCollision(Collider* other);
    b2Vec2 direction;
    float speed;
private:
    
    BoxCollider* collider;
};

