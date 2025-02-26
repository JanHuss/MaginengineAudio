// Initialises and manages the hierarchial structure of the engine
// The structure is making use of the Composite Design pattern.
// EventManager is considered the "Client" and handles the components.

#pragma once
// Headers
#include "Component.h"
#include "Composite.h"
#include "Leaf.h"
#include "Asset.h"
#include "RealVoicePool.h"
#include "VirtualVoicePool.h"
#include "PlaybackDevice.h"

// libraries
#include <iostream>
#include <thread>


class EventManager
{
public:
	EventManager();
	~EventManager();

	void init();
	void update(float dt);

	void TreeStructure(Component* component);
    void TreeStructure(Component* component1, Component* component2);

	void checkIfRealVoiceAvailable();


private:
	PlaybackDevice playbackDevice;

	// Composite objects
	Component* tree = new Composite;

	Component* bigWave_Event = new Composite;
	Component* bigWave = new Leaf;

	Component* trapDoor_Event = new Composite;
	Component* trapDoor = new Leaf;

	Component* smilyDay_Event = new Composite;
	Component* smilyDay_Track = new Leaf;

	Component* janVoice_Event = new Composite;
	Component* janVoice_Track = new Leaf;

	Component* thisIsMyVoice_Event = new Composite;
	Component* thisIsMyVoice_Track = new Leaf;

	// Assets
	Asset bigWave_Asset;
	Asset trapDoor_Asset;
	Asset smilyDay_Asset;
	Asset janVoice_Asset;
	Asset thisIsMyVoice_Asset;

	// Object Pool Setup
	RealVoicePool* realVoicePool = RealVoicePool::getInstance();
	VirtualVoicePool* virtualVoicePool = VirtualVoicePool::getInstance();

	
};

