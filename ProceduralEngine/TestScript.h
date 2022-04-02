#pragma once
#include "Script.h"

class TestScript:
	public Script
{
public:
	TestScript();
	
	// You only have to implement the functions that you need
	// Unneeded ones can be removed with no problems
	void start() override;
	void update() override;
	void fixedUpdate() override;
};