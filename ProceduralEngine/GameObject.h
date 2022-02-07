#pragma once
#include <vector>;
#include "IScriptable.h";
#include "Component.h";

class GameObject : IScriptable
{
public:
	GameObject();

	/// <summary>
	/// Adds a component to the component list
	/// </summary>
	/// <typeparam name="type">The type of the component being added</typeparam>
	/// <param name="component">The component to add</param>
	/// <returns>The added component</returns>
	template <class type> type addComponent(type component);

	/// <summary>
	/// Gets the first component of type 'type' from the components attached to the GameObject if one exists
	/// </summary>
	/// <typeparam name="type">The type of the component being gotten</typeparam>
	/// <returns>The gotten component</returns>
	template <class type> type getComponent();

private:
	std::vector<Component> components;
};
