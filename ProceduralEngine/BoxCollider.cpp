#include "BoxCollider.h"

BoxCollider::BoxCollider(b2Vec2 size)
{
	b2PolygonShape* s = new b2PolygonShape();
	this->size = size;
	
	shape = s;
}

void BoxCollider::init()
{
	b2PolygonShape* s = dynamic_cast<b2PolygonShape*>(shape);
	s->SetAsBox(size.x / 2.0f, size.y / 2.0f);
}

void BoxCollider::debugDraw()
{
	Debug::DrawRectangle(gameObject->getTransform()->getPosition(), size.x, size.y);
}

std::string BoxCollider::toString()
{
	return "Box Collider: " + to_string(size.x) + " " + to_string(size.y);
}
