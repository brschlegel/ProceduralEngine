#include "Brick.h"

Brick::Brick(int num, Scene* scene)
{
	this->num = num;
	this->scene = scene;
	timer = 0;
}

void Brick::start()
{
	BoxCollider* collider = gameObject->getComponent<BoxCollider>();
	collider->onCollisionDelegate.AddRaw(this, &Brick::handleCollisions);
}

void Brick::update()
{
	timer += Time::deltaTime;
}

void Brick::handleCollisions(Collider* other)
{
	if (other->getGameObject()->getName() == "Ball" && timer > .1f)
	{
		timer = 0;
		num--;
		if (num <= 0)
		{
			scene->destroyGameObject(getGameObject());
			
		}
		else
		{
			SpriteRenderer* sr = gameObject->getComponent<SpriteRenderer>();
			string newSprite = "Brick" + to_string(num);
			sr->setSprite(newSprite);
		}
		other->getGameObject()->getComponent<Ball>()->speed *= 1.01f;
	}
}
