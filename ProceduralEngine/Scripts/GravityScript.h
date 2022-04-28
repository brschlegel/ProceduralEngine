#pragma once
#include "../Script.h"
#include "../Time.h"
#include "../Input.h"
class GravityScript :
    public Script
{
public:
    GravityScript();
    void start() override;
    void update() override;
private:
    float velocity;
    float acceleration;
    

};

