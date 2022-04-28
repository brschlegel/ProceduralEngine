#include "DrawManager.h"
#include <iostream>
#include "Random.h"
#include <string>
#include "PerlinNoise.h"
#include "Scene.h"
#include "ScriptManager.h"
#include "Scripts/GravityScript.h"
#include "Time.h"
#include "Input.h"

#include "PipeManager.h"


int windowWidth = 960;
int windowHeight = 540;
unsigned int DelegateHandle::CURRENT_ID;
float Time::deltaTime;
static bool sceneDone = false;

Scene* BuildFlappy()
{
    Scene* scene = new Scene();
    GameObject* flappy = scene->addGameObject(new GameObject("Flappy"));
    flappy->setTransform(0, 0, 0, 1, 1);
    BoxCollider* collider = (BoxCollider*)flappy->addComponent(scene->collisionManager.createBoxCollider(b2Vec2(1, 1)));
    flappy->addComponent(scene->drawManager.createSpriteRenderer("Flappy"));
    flappy->addComponent(new GravityScript());
    collider->onCollisionDelegate.AddLambda([](Collider* other)
        {
            sceneDone = true;
        });

    GameObject* pipeManager = scene->addGameObject(new GameObject("Manager"));
    pipeManager->addComponent(new PipeManager(scene));


   

    return scene;
}

int main()
{
    Random::seedGenerator();
    // Testing Scenes and GameObjects
    Scene* scene = BuildFlappy();


   


    Debug::drawDebug = true;
    Debug::drawGrid = true;
    Debug::drawColliders = true;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");
    DrawManager::windowWidth = windowWidth;
    DrawManager::windowHeight = windowHeight;
    window.setKeyRepeatEnabled(false);
   
    sf::Clock clock;
    //Test for Box2D, works for release too
    b2Vec2 gravity(0.0f, -10.0f);
    while (window.isOpen())
    {
        Time::deltaTime = clock.restart().asSeconds();
        Input::clear();
        window.clear(sf::Color(255, 255, 255));
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                Input::recordKeyPressed(event.key.code);
            if (event.type == sf::Event::KeyReleased)
                Input::recordKeyReleased(event.key.code);
                
        }
        
        scene->update(&window);

        if (sceneDone)
        {
            delete scene;
            scene = BuildFlappy();
            sceneDone = false;
        }

        window.display();
    }

    SpriteRenderer::unloadTextures();

    return 0; 
}