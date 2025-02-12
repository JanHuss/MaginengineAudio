// Runs the entire application
// Initialises the EventManager that lays out a hierarchial structure of 
// the engine.

#pragma once
// classes
#include "EventManager.h"
#include "PlaybackDevice.h"

// libraries
#include <iostream>

class Engine
{
public: 
	Engine();
	~Engine();

	int init();
	void run();

private:
	PlaybackDevice playbackDevice;
	EventManager eventManager;
};

