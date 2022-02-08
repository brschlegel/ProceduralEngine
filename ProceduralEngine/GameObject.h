#pragma once
#include <vector>
#include "IScriptable.h"
#include "Component.h"

// TODO: Resolve LNK2001 error occurring within GameObject class
class GameObject : IScriptable
{
public:
	GameObject();

	template <class type> type addComponent(type component);
	template <class type> type getComponent();

private:
	std::vector<Component> components;
};

