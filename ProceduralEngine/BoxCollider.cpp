//#include "BoxCollider.h"
//
//BoxCollider::BoxCollider(b2Vec2 size)
//{
//	b2PolygonShape* s = new b2PolygonShape();
//	this->size = size;
//	s->SetAsBox(size.x / 2.0f, size.y / 2.0f);
//	shape = s;
//}
//
//void BoxCollider::init()
//{
//}
//
//void BoxCollider::DebugDraw()
//{
//	Debug::DrawRectangle(gameObject->getTransform()->getPosition(), size.x, size.y);
//}
//
//std::string BoxCollider::toString()
//{
//	return "Box Collider: " + to_string(size.x) + " " + to_string(size.y);
//}
