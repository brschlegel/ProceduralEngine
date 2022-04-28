#pragma once
#include "../Script.h"
#include "../Time.h"
class MoveLeft :
    public Script
{
public:
    MoveLeft();
    void update() override;
    void start() override;

private:
    float speed;
};

