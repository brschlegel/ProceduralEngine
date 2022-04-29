#pragma once
#include "Script.h"
#include "BoxCollider.h"
#include "Scene.h"
#include "Ball.h"
class Brick :
    public Script
{
public:
    Brick(int num, Scene* scene);
    void start() override;
    void update() override;
private:
    int num;
    void handleCollisions(Collider* other);
    Scene* scene;
    float timer;
};

