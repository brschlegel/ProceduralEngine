#include "Collider.h"

bool Collider::CheckCollision(Collider* other)
{
    return b2TestOverlap(shape, 0, other->getShape(), 0, gameObject->getTransform()->getb2Transform(),other->getGameObject()->getTransform()->getb2Transform() );
}

void Collider::OnCollision(Collider* other)
{
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
