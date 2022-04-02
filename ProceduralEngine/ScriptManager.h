#pragma once
#include "Script.h"
#include <fstream>

class ScriptManager
{
public:
	ScriptManager();

	Script* createScript(std::string fileName);

private:
	std::vector<Script*> scripts;
};

