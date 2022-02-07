#pragma once
#include <string>;
#include "Transform.h";

/// <summary>
/// An interface for all objects that will have code attached to them.
/// The classes that implement this interface will be updated every frame via the main update loop.
/// </summary>
class IScriptable {
public:
	virtual void start() = 0;
	virtual void update() = 0;
	virtual void fixedUpdate() = 0;
	
	std::string getName() { return name; }
	std::string setName(std::string _name) { name = _name; }

	Transform getTransform() { return transform; }
	void setTransform(Transform _transform) { transform = _transform; }

private:
	std::string name;
	Transform transform;
};