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
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"


int windowWidth = 960;
int windowHeight = 540;
unsigned int DelegateHandle::CURRENT_ID;
float Time::deltaTime;
static bool sceneDone = false;
static std::string currentSceneName = "Flappy";

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

Scene* BuildBreakout()
{
    Scene* scene = new Scene();
    GameObject* ball = scene->addGameObject(new GameObject("Ball"));
    ball->setTransform(2, 2, 0,1.0f, 1.0f);
    ball->addComponent(scene->drawManager.createSpriteRenderer("Ball"));
    ball->addComponent(scene->collisionManager.createBoxCollider(b2Vec2(.5f,.5f)));
    ball->addComponent(new Ball());

    //Add paddle
    GameObject* paddle = scene->addGameObject(new GameObject("Paddle"));
    paddle->setTransform(0, -4, 0, 2.0f, 1.0f);
    paddle->addComponent(scene->drawManager.createSpriteRenderer("Paddle"));
    BoxCollider* paddleCollider = (BoxCollider*)paddle->addComponent(scene->collisionManager.createBoxCollider(b2Vec2(4, .25f)));
    paddleCollider->onCollisionDelegate.AddLambda([](Collider* other)
        {
            GameObject* go = other->getGameObject();
            if (go->getName() == "Ball")
            {
                Ball* b = go->getComponent<Ball>();
                if (Input::isDown(sf::Keyboard::A))
                {
                    b->direction += b2Vec2(-.1f, 0);
                    b->direction.Normalize();
                }
                if (Input::isDown(sf::Keyboard::D))
                {

                    b->direction += b2Vec2(.1f, 0);
                    b->direction.Normalize();
                }
            }
        });
    paddle->addComponent(new Paddle());

    //Add bricks 
    for (int i = 0; i < 32; i++)
    {
        //First Row
        GameObject* brick = scene->addGameObject(new GameObject());
        brick->setTransform(i - 15.5, 6, 0, 1, 1);
        brick->addComponent(scene->drawManager.createSpriteRenderer("Brick1"));
        brick->addComponent(scene->collisionManager.createBoxCollider(b2Vec2(.95f, .45f)));
        brick->addComponent(new Brick(1, scene));

        //Second Row
        GameObject* brick2 = scene->addGameObject(new GameObject());
        brick2->setTransform(i - 15.5, 6.5f, 0, 1, 1);
        brick2->addComponent(scene->drawManager.createSpriteRenderer("Brick2"));
        brick2->addComponent(scene->collisionManager.createBoxCollider(b2Vec2(.95f, .45f)));
        brick2->addComponent(new Brick(2, scene));

        //Third Row
        GameObject* brick3 = scene->addGameObject(new GameObject());
        brick3->setTransform(i - 15.5, 7, 0, 1, 1);
        brick3->addComponent(scene->drawManager.createSpriteRenderer("Brick3"));
        brick3->addComponent(scene->collisionManager.createBoxCollider(b2Vec2(.95f, .45f)));
        brick3->addComponent(new Brick(3, scene));

    }

    //Build Walls
    GameObject* left = scene->addGameObject(new GameObject("LeftWall"));
    left->setTransform(-16.5f, 0, 0, 1, 1);
    left->addComponent(scene->collisionManager.createBoxCollider(b2Vec2(1, 18)));
    GameObject* top = scene->addGameObject(new GameObject("TopWall"));
    top->setTransform(0, 9.5f, 0, 1, 1);
    top->addComponent(scene->collisionManager.createBoxCollider(b2Vec2(32, 1)));
    GameObject* right = scene->addGameObject(new GameObject("RightWall"));
    right->setTransform(16.5f, 0, 0, 1, 1);
    right->addComponent(scene->collisionManager.createBoxCollider(b2Vec2(1, 18)));
    GameObject* bottom = scene->addGameObject(new GameObject("BottomWall"));
    bottom->setTransform(0, -9.5f, 0, 1, 1);
    BoxCollider* endGameCollider = (BoxCollider*)bottom->addComponent(scene->collisionManager.createBoxCollider(b2Vec2(32, 1)));
    endGameCollider->onCollisionDelegate.AddLambda([](Collider* other)
        {
            if (other->getGameObject()->getName() == "Ball")
            {
                sceneDone = true;
            }
        });
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
        //window.clear(sf::Color(0, 0, 0));
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
            if (currentSceneName == "Flappy")
            {
                scene = BuildFlappy();
            }
            else
            {
                scene = BuildBreakout();
            }
            sceneDone = false;
        }

        if (Input::isPressed(sf::Keyboard::Num1))
        {
            delete scene;
            scene = BuildFlappy();
            currentSceneName = "Flappy";
        }
        else if (Input::isPressed(sf::Keyboard::Num2))
        {
            delete scene;
            scene = BuildBreakout();
            currentSceneName = "Breakout";
        }

        if (Input::isPressed(sf::Keyboard::G))
        {
            Debug::drawGrid = !Debug::drawGrid;
        }


        if (Input::isPressed(sf::Keyboard::B))
        {
            Debug::drawColliders = !Debug::drawColliders;
        }
        scene->cleanDestroyedObjects();
        window.display();
    }

    SpriteRenderer::unloadTextures();

    return 0; 
}