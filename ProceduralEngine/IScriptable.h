#pragma once

/// <summary>
/// An interface for all classes that will have code attached to them by a user.
/// The classes that implement this interface will be updated every frame via the main update loop.
/// </summary>
__interface IScriptable {
	// -------------------------------------
	//			ISCRIPTABLE METHODS
	// -------------------------------------
	
	// Called when the child this is attached to is first instantiated.
	void start();

	// Called every frame update.
	void update();

	// Called on a fixed update timer.
	void fixedUpdate();

	// Called when the child this is attached to is enabled.
	void onEnable();

	// Called when the child this is attached to is enabled.
	void onDisable();
};