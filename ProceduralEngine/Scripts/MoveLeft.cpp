#include "MoveLeft.h"

MoveLeft::MoveLeft()
{
	speed = 5;
}

void MoveLeft::update()
{
	b2Vec2 currentPos = gameObject->getTransform()->getPosition();
	currentPos.x -= speed * Time::deltaTime;
	gameObject->getTransform()->setPosition(currentPos);
}

void MoveLeft::start()
{
}
