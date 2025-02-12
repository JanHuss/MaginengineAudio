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


// libraries
#include <iostream>



class EventManager
{
public:
	EventManager();
	~EventManager();

	void init();

	void TreeStructure(Component* component);
    void TreeStructure(Component* component1, Component* component2);

private:
	// Composite objects
	Component* tree = new Composite;

	Component* bigWave_Event = new Composite;
	Component* bigWave_FullSound_Track = new Leaf;

	Component* laserGun_Event = new Composite;
	Component* laserGun_Charge_Track = new Leaf;
	Component* laserGun_Trigger_Track = new Leaf;
	Component* laserGun_Release_Track = new Leaf;

	Component* footsteps_wood_Event = new Composite;
	Component* footsteps_wood_Track1 = new Leaf;
	Component* footsteps_wood_Track2 = new Leaf;
	Component* footsteps_wood_Track3 = new Leaf;
	Component* footsteps_wood_Track4 = new Leaf;
	Component* footsteps_wood_Track5 = new Leaf;

	// Assets
	Asset bigWave_Asset;

	// Object Pool Setup
	RealVoicePool* realVoicePool = RealVoicePool::getInstance();
	VirtualVoicePool* virtualVoicePool = VirtualVoicePool::getInstance();
	//RealVoice* realVoice;
	//RealVoice* realVoiceTwo;
	//RealVoice* realVoiceThree;
	
};

