#pragma once
#include "Script.h"
#include "Time.h"
#include "Input.h"
class Paddle :
    public Script
{
public:
    Paddle();
    void start() override;
    void update() override;
private:
    float speed;
};

