#include "EventManager.h"

EventManager::EventManager()
{
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
	std::cout << "EventManager -> initialising \"eventManager\" object" << std::endl;

	// initialising the Engine's hierarchy. Making use of the 
	// composite pattern
	tree->Add(bigWave_Event);

	bigWave_Event->Add(bigWave_FullSound_Track); // add a Track to an Event
	bigWave_Asset.loadFile("BigWave.wav"); // Load an Audio File
	bigWave_FullSound_Track->assignAssetToTrack(bigWave_Asset.getAudioData()); // Assign an Audio Asset to a track

	tree->Add(laserGun_Event);
	laserGun_Event->Add(laserGun_Charge_Track);
	laserGun_Charge_Track->assignAssetToTrack(bigWave_Asset.getAudioData()); // Assign an Audio Asset to a track
	laserGun_Event->Add(laserGun_Trigger_Track);
	laserGun_Event->Add(laserGun_Release_Track);

	tree->Add(footsteps_wood_Event);
	tree->Add(footsteps_wood_Track1);
	tree->Add(footsteps_wood_Track2);
	tree->Add(footsteps_wood_Track3);
	tree->Add(footsteps_wood_Track4);
	tree->Add(footsteps_wood_Track5);

	TreeStructure(tree);

	std::cout << "EventManager -> Getting audio data size: " << bigWave_FullSound_Track->getAudioData().size() << std::endl;
	std::cout << "EventManager -> Getting RealVoicePool size: " << realVoicePool->getRealVoicePoolSize().size() << std::endl;

	bigWave_FullSound_Track->play(*realVoicePool, *virtualVoicePool);// passing in this pointer might be wrong ask tomorrow
	
	laserGun_Charge_Track->play(*realVoicePool, *virtualVoicePool);

	laserGun_Trigger_Track->play(*realVoicePool, *virtualVoicePool);

	laserGun_Release_Track->play(*realVoicePool, *virtualVoicePool);

	footsteps_wood_Track1->play(*realVoicePool, *virtualVoicePool);
	//bigWave_FullSound_Track->stop(*realVoicePool);
}

void EventManager::TreeStructure(Component* component)
{
	std::cout << "EventManager -> Result: " << component->Operation() << std::endl;
}

void EventManager::TreeStructure(Component* component1, Component* component2)
{
	if (component1->IsComposite())
	{
		component1->Add(component2);

	}
	std::cout << "EventManager -> Result: " << component1->Operation() << std::endl;
}


