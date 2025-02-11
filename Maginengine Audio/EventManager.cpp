#include "EventManager.h"

EventManager::EventManager()
{
	init();
}

EventManager::~EventManager()
{
	delete tree;
	delete bigWave_Event;
	delete bigWave_FullSound_Track;
	delete laserGun_Event;
	delete laserGun_Charge_Track;
	delete laserGun_Trigger_Track;
	delete laserGun_Release_Track;
	delete footsteps_wood_Event;
	delete footsteps_wood_Track1;
	delete footsteps_wood_Track2; 
	delete footsteps_wood_Track3;
	delete footsteps_wood_Track4;
	delete footsteps_wood_Track5;

}

void EventManager::init()
{
	//std::cout << "EventManager -> init() called()" << std::endl;

	// initialising the Engine's hierarchy. Making use of the 
	// composite pattern
	tree->Add(bigWave_Event);
	bigWave_Event->Add(bigWave_FullSound_Track);

	tree->Add(laserGun_Event);
	laserGun_Event->Add(laserGun_Charge_Track);
	laserGun_Event->Add(laserGun_Trigger_Track);
	laserGun_Event->Add(laserGun_Release_Track);

	tree->Add(footsteps_wood_Event);
	tree->Add(footsteps_wood_Track1);
	tree->Add(footsteps_wood_Track2);
	tree->Add(footsteps_wood_Track3);
	tree->Add(footsteps_wood_Track4);
	tree->Add(footsteps_wood_Track5);


	TreeStructure(tree);

	bigWave_Asset.loadFile("BigWave.wav");
	bigWave_FullSound_Track->assignAssetToTrack(bigWave_Asset.getAudioData());
	bigWave_FullSound_Track->getAudioData();

	//bigWave_FullSound_Track->play();
	// concept of how to grab a function created outside of the base class
	//Leaf* derivedTrack = dynamic_cast<Leaf*> (bigWave_FullSound_Track);
	//if (derivedTrack)
	//	derivedTrack->assignAssetToTrack(bigWave_Asset.getAudioData());
	//
	//delete derivedTrack;
}

void EventManager::TreeStructure(Component* component)
{
	std::cout << "Result: " << component->Operation() << std::endl;
}

void EventManager::TreeStructure(Component* component1, Component* component2)
{
	if (component1->IsComposite())
	{
		component1->Add(component2);

	}
	std::cout << "Result: " << component1->Operation() << std::endl;
}


