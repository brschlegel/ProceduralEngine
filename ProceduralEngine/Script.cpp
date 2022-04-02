#include "Script.h"

Script::Script(std::string _fileName)
{
	fileName = _fileName;
}

Script::Script(std::string _fileName, GameObject* _gameObject) : Component::Component(_gameObject)
{
	fileName = _fileName;
}

void Script::start()
{
	Debug::print("Hello Script!", true);
}

void Script::update()
{
}

void Script::fixedUpdate()
{
}

std::string Script::toString()
{
	return fileName;
}
