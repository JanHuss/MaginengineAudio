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


	// loading audio files (for now chuck in resource manager)
	bigWave_Asset.loadFile("BigWave.wav");
	// assign asset to track. might be good to assign it on creation of the track. 
	bigWave_FullSound_Track->assignAssetToTrack(bigWave_Asset.getAudioData());
	std::cout << "Getting audio data size: " << bigWave_FullSound_Track->getAudioData().size() << std::endl;
	

	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// REMEMBER TO ASK ABOUT THIS!!!!!
	// Why is the "realVoice" only allowing me to pass through a pointer?
	std::cout << "Getting RealVoicePool size: " << realVoicePool->getRealVoicePoolSize().size() << std::endl;
	realVoice = realVoicePool->getResource();
	bigWave_FullSound_Track->play(*realVoice);// passing in this pointer might be wrong ask tomorrow
	//realVoiceTwo = realVoicePool->getResource();
	//laserGun_Charge_Track->play(*realVoiceTwo);
	//realVoiceThree = realVoicePool->getResource();
	//laserGun_Trigger_Track->play(*realVoiceThree);
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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


