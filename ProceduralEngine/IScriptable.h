#pragma once

/// <summary>
/// An interface for all classes that will have code attached to them.
/// The classes that implement this interface will be updated every frame via the main update loop.
/// </summary>
__interface IScriptable {
	// Called when the GameObject this is attached to is first instantiated.
	void start();

	// Called every frame update.
	void update();

	// Called on a fixed update timer.
	void fixedUpdate();
};