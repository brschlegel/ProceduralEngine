#include "Ball.h"


Ball::Ball()
{
	
}

void Ball::start()
{
	collider = gameObject->getComponent<BoxCollider>();
	collider->onCollisionDelegate.AddLambda([this](Collider* other)
		{
			handleCollision(other);
		});
	direction = b2Vec2(1, 1);
	direction.Normalize();
	speed = 6;
}

void Ball::update()
{
	b2Vec2 currentPosition = gameObject->getTransform()->getPosition();
	currentPosition += Time::deltaTime * speed * direction;
	gameObject->getTransform()->setPosition(currentPosition);
}

void Ball::handleCollision(Collider* other)
{
	b2Vec2 center = gameObject->getTransform()->getPosition();
	b2Vec2 step = Time::deltaTime * speed * direction;
	center -=  step;
	//Check Horizontal
	float signX = direction.x > 0 ? 1 : -1;
	b2Vec2 horPoint = center + b2Vec2((signX * (collider->size.x / 2)) + step.x, 0);
	if (other->testPoint(horPoint))
	{
		direction.x *= -1;
	}
	//Check vertical
	float signY = direction.y > 0 ? 1 : -1;
	b2Vec2 vertPoint = center + b2Vec2(0, (signY * (collider->size.y / 2)) + step.y);
	if (other->testPoint(vertPoint))
	{
		direction.y *= -1;
	}
	gameObject->getTransform()->setPosition(gameObject->getTransform()->getPosition() + ( Time::deltaTime * speed * direction));
}
