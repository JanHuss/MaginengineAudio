#include "EventManager.h"

EventManager::EventManager() /*: playbackDevice(realVoicePool)*/
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

	//ma_decoder_uninit(&trapDoor.decoder);
	ma_device_uninit(&playbackDevice.device);
}

void EventManager::init()
{
	std::cout << "EventManager -> initialising \"eventManager\" object" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;

	// initialising the Engine's hierarchy. Making use of the 
	// composite pattern
	tree->Add(bigWave_Event);

	bigWave_Event->Add(bigWave_FullSound_Track); // add a Track to an Event
	bigWave_Asset.loadFile("assets/audio/BigWave.wav"); // Load an Audio File
	laserGun_Charge_Track->setVolume(0.5f);
	bigWave_FullSound_Track->assignAssetToTrack(bigWave_Asset.getAudioData()); // Assign an Audio Asset to a track
	bigWave_FullSound_Track->setLoop(false);

	tree->Add(laserGun_Event);

	laserGun_Event->Add(laserGun_Charge_Track);
	trapDoor_Asset.loadFile("assets/audio/TrapDoor.wav");
	laserGun_Charge_Track->setVolume(0.5f);
	laserGun_Charge_Track->assignAssetToTrack(trapDoor_Asset.getAudioData()); // Assign an Audio Asset to a track
	laserGun_Charge_Track->setLoop(false);

	laserGun_Event->Add(laserGun_Trigger_Track);
	laserGun_Trigger_Track->assignAssetToTrack(bigWave_Asset.getAudioData());
	laserGun_Event->Add(laserGun_Release_Track);

	tree->Add(footsteps_wood_Event);
	footsteps_wood_Event->Add(footsteps_wood_Track1);
	footsteps_wood_Event->Add(footsteps_wood_Track2);
	footsteps_wood_Event->Add(footsteps_wood_Track3);
	footsteps_wood_Event->Add(footsteps_wood_Track4);
	footsteps_wood_Event->Add(footsteps_wood_Track5);

	tree->Add(smilyDay_Event);
	smilyDay_Event->Add(smilyDay_Track);
	smilyDay_Asset.loadFile("assets/audio/SmileyDayToYa.wav");
	smilyDay_Track->assignAssetToTrack(smilyDay_Asset.getAudioData());
	smilyDay_Track->setLoop(true);

	TreeStructure(tree);

	//std::cout << "EventManager -> Getting audio data size: " << bigWave_FullSound_Track->getAudioData().size() << std::endl;
	//std::cout << "EventManager -> Getting RealVoicePool size: " << realVoicePool->getRealVoicePool().size() << std::endl;	

	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "---------------------playing------------------------" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;

	// Test runs
	smilyDay_Track->play(*realVoicePool, *virtualVoicePool);
	//std::this_thread::sleep_for(std::chrono::seconds(3));
	bigWave_FullSound_Track->play(*realVoicePool, *virtualVoicePool);// passing in this pointer might be wrong ask tomorrow
	laserGun_Charge_Track->play(*realVoicePool, *virtualVoicePool);
	//std::this_thread::sleep_for(std::chrono::seconds(3));
	laserGun_Trigger_Track->play(*realVoicePool, *virtualVoicePool);
	laserGun_Release_Track->play(*realVoicePool, *virtualVoicePool);
	//std::this_thread::sleep_for(std::chrono::seconds(5));
	footsteps_wood_Track1->play(*realVoicePool, *virtualVoicePool);
	//std::this_thread::sleep_for(std::chrono::seconds(5));
	//bigWave_FullSound_Track->stop(*realVoicePool);
	std::this_thread::sleep_for(std::chrono::seconds(120));
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


