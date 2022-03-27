#include "DrawManager.h"
#include <iostream>
#include "Random.h"
#include <string>
#include "PerlinNoise.h"
#include "Scene.h"
#include "SpriteRenderer.h"
#include "BoxCollider.h"


int windowWidth = 960;
int windowHeight = 540;

int main()
{
    Scene scene = Scene();

    scene.addGameObject(new GameObject());
    scene.addGameObject(new GameObject("Bob"));
    GameObject* go = scene.getGameObjectByName("Bob");

    scene.addGameObject(new GameObject("Jim", go));
   

    Debug::print(go->getTransform()->toString());
    go->setTransform(0, 0, 0, 1, 1);
    go->addComponent(scene.drawManager.createSpriteRenderer("egg"));
    go->addComponent(new BoxCollider(b2Vec2(1, 1)));
    Debug::print(go->getTransform()->toString());

    GameObject* child = go->getChildByName("Jim");

    Debug::print(go->toString());

    Debug::print(go->getChild(0)->toString());
    Debug::print(child->toString());

    Debug::print(go->getComponent<Transform>()->toString());

    Scene scene2 = Scene(scene);

    Random::seedGenerator();

    Debug::drawDebug = true;
    Debug::drawGrid = true;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");
    DrawManager::windowWidth = windowWidth;
    DrawManager::windowHeight = windowHeight;
   

    //Test for Box2D, works for release too
    b2Vec2 gravity(0.0f, -10.0f);
    while (window.isOpen())
    {

        window.clear(sf::Color(255, 255, 255));
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)

                window.close();
        }
        go->getComponent<BoxCollider>()->DebugDraw();
        scene.drawManager.DrawDebug(&window);
        scene.drawManager.drawSpriteRenderers(&window);
     
    
        window.display();
    }

    SpriteRenderer::unloadTextures();

    return 0; 
}