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
#include <chrono>

class Engine
{
public: 
	Engine();
	~Engine();

	int init();
	void run();

private:
	// needs to be refactored. shouldn't be passing this through playback
	// just for test purposes
	//RealVoice realVoice;
	//VirtualVoice virtualVoice;

	PlaybackDevice playbackDevice;
	EventManager eventManager;

	float deltaTime;
	std::chrono::steady_clock::time_point lastUpdate;
};

