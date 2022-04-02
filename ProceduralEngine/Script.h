#pragma once
#include "GameObject.h"
#include "Debug.h"

class Script :
    public Component
{
public:
    Script(std::string fileName);
    Script(std::string fileName, GameObject* _gameObject);

    virtual void start();
    virtual void update();
    virtual void fixedUpdate();

    std::string toString();

private:
    std::string fileName;
};

