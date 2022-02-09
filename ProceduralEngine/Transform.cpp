#include "Transform.h"

Transform::Transform() {
	position = b2Vec2(1, 1);
	rotation = b2Rot(0);
	scale = b2Vec2(1, 1);
}

b2Vec2 Transform::getPosition() { return position; }

void Transform::setPosition(b2Vec2 _position) { position = _position; }
void Transform::setPosition(float32 x, float32 y) { position = b2Vec2(x, y); }

b2Rot Transform::getRotation() { return rotation; }

void Transform::setRotation(b2Rot _rotation) { rotation = _rotation; }
void Transform::setRotation(float32 angle) { rotation = b2Rot(angle); }

b2Vec2 Transform::getScale() { return scale; }

void Transform::setScale(b2Vec2 _scale) { scale = _scale; }
void Transform::setScale(float32 x, float32 y) { scale = b2Vec2(x, y); }