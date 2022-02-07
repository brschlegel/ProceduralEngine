#include "Transform.h"

b2Vec2 Transform::getPosition() { return position; }

void Transform::setPosition(b2Vec2 _position) { position = _position; }

b2Rot Transform::getRotation() { return rotation; }

void Transform::setRotation(b2Rot _rotation) { rotation = _rotation; }

b2Vec2 Transform::getScale() { return scale; }

void Transform::setScale(b2Vec2 _scale) { scale = _scale; }
