#include "TestScript.h"

TestScript::TestScript() : Script::Script("TestScript")
{
}

void TestScript::start()
{
	Debug::print("Hello TestScript!", true);
}

void TestScript::update()
{
}

void TestScript::fixedUpdate()
{
}