// Runs the entire application
// Initialises the EventManager that lays out a hierarchial structure of 
// the engine.

#pragma once
// classes
#include "EventManager.h"

// libraries
#include <iostream>

class Engine
{
public: 
	Engine();
	~Engine();

	void init();
	void run();

private:
	EventManager eventManager;
};

