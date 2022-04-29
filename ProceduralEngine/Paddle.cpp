#include "Paddle.h"

Paddle::Paddle()
{
	speed = 10;
}

void Paddle::start()
{

}

void Paddle::update()
{
	if (Input::isDown(sf::Keyboard::A))
	{
		b2Vec2 currentPosition = gameObject->getTransform()->getPosition();
		currentPosition += Time::deltaTime * b2Vec2(-speed, 0);
		gameObject->getTransform()->setPosition(currentPosition);
	}
	if (Input::isDown(sf::Keyboard::D))
	{
		b2Vec2 currentPosition = gameObject->getTransform()->getPosition();
		currentPosition += Time::deltaTime * b2Vec2(speed, 0);
		gameObject->getTransform()->setPosition(currentPosition);
	}
}
