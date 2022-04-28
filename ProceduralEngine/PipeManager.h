#pragma once
#include "Script.h"
#include "Scene.h"
#include "Scripts/MoveLeft.h"
#include "Random.h"
class PipeManager :
    public Script
{
public:
    PipeManager(Scene* scene);
    void start() override;
    void update() override;
private:
    std::vector<std::vector<GameObject*>> pipes;
    void buildPipe(float x);
    Scene* scene;
};

