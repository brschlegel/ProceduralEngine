#include "Collider.h"

bool Collider::CheckCollision(Collider* other)
{
   // return b2TestOverlap(shape, 0, other->getShape(), 0, gameObject->getTransform()->getb2Transform(),other->getGameObject()->getTransform()->getb2Transform() );
    return b2TestOverlap(getAABB(), other->getAABB());
}

void Collider::OnCollision(Collider* other)
{
    onCollisionDelegate.Broadcast(other);
}

b2AABB Collider::getAABB()
{
    b2AABB a;
    shape->ComputeAABB(&a, gameObject->getTransform()->getb2Transform(),0);

    return a;
}

b2Shape* Collider::getShape()
{
    return shape;
}

bool Collider::testPoint(b2Vec2 point)
{
    return shape->TestPoint(gameObject->getTransform()->getb2Transform(), point);
}
