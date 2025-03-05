// Runs the entire application
// Initialises the EventManager that lays out a hierarchial structure of 
// the engine.

#pragma once
// classes
#include "EventManager.h"
#include "PlaybackDevice.h"

// I don't think this is right
#include "RealVoice.h"
#include "VirtualVoice.h"

// libraries
#include <iostream>

class Engine
{
public: 
	Engine();
	~Engine();

	int init();
	void run(float deltaTime);

	// for other frameworks to access the Eventmanager class
	// and its Composite Tree pattern.
	EventManager& getEventManagerInstance();

private:
	PlaybackDevice playbackDevice;
	EventManager eventManager;

	enum DEVSTATE{STANDALONE, ATTACHED, ATTACHEDDEBUG};
	DEVSTATE developmentState;
};

