#include "GravityScript.h"
#

GravityScript::GravityScript()
{
	acceleration = -10;
	velocity = 0;
}

void GravityScript::start()
{
}

void GravityScript::update()
{
	if (Input::isPressed(sf::Keyboard::Space))
	{
		velocity += 10;
	}
	float y = gameObject->getTransform()->getPosition().y;
	velocity += acceleration * Time::deltaTime;
	y += velocity * Time::deltaTime;
	gameObject->getTransform()->setPosition(gameObject->getTransform()->getPosition().x, y);
	float angle = PMath::clamp(-velocity * 2, -50, 50);
	gameObject->getTransform()->setRotation(angle);
}
