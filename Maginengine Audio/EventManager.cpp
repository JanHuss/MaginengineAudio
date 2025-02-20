#include "EventManager.h"

EventManager::EventManager() /*: playbackDevice(realVoicePool)*/
{
}

EventManager::~EventManager()
{
	delete tree;
	delete bigWave_Event;
	delete bigWave;
	delete laserGun_Event;
	delete trapDoor;
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

	bigWave_Event->Add(bigWave); // add a Track to an Event
	bigWave_Asset.loadFile("assets/audio/BigWave.wav"); // Load an Audio File
	trapDoor->setVolume(0.5f);
	bigWave->assignAssetToTrack(bigWave_Asset.getAudioData()); // Assign an Audio Asset to a track
	bigWave->setLoop(false);

	tree->Add(laserGun_Event);

	laserGun_Event->Add(trapDoor);
	trapDoor_Asset.loadFile("assets/audio/TrapDoor.wav");
	trapDoor->setVolume(0.5f);
	trapDoor->assignAssetToTrack(trapDoor_Asset.getAudioData()); // Assign an Audio Asset to a track
	trapDoor->setLoop(false);

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
	smilyDay_Track->setLoop(false);

	TreeStructure(tree);

	//std::cout << "EventManager -> Getting audio data size: " << bigWave_FullSound_Track->getAudioData().size() << std::endl;
	//std::cout << "EventManager -> Getting RealVoicePool size: " << realVoicePool->getRealVoicePool().size() << std::endl;	

	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "---------------------Playing Track------------------" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	// Test runs
	smilyDay_Track->play(*realVoicePool, *virtualVoicePool);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "---------------------Test 01------------------------" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;

	trapDoor->play(*realVoicePool, *virtualVoicePool);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	smilyDay_Track->stop(*realVoicePool, *virtualVoicePool);
	bigWave->play(*realVoicePool, *virtualVoicePool);
	smilyDay_Track->play(*realVoicePool, *virtualVoicePool);
	smilyDay_Track->setLoop(false);
	trapDoor->play(*realVoicePool, *virtualVoicePool);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	bigWave->play(*realVoicePool, *virtualVoicePool);
	smilyDay_Track->play(*realVoicePool, *virtualVoicePool);
	smilyDay_Track->setLoop(true);

	//std::this_thread::sleep_for(std::chrono::seconds(10));
	//std::cout << "----------------------------------------------------" << std::endl;
	//std::cout << "---------------------Test 02------------------------" << std::endl;
	//std::cout << "----------------------------------------------------" << std::endl;
	//trapDoor->play(*realVoicePool, *virtualVoicePool);
	//std::this_thread::sleep_for(std::chrono::seconds(1));

	bigWave->play(*realVoicePool, *virtualVoicePool);
	//bigWave_FullSound_Track->play(*realVoicePool, *virtualVoicePool);// passing in this pointer might be wrong ask tomorrow
	//std::this_thread::sleep_for(std::chrono::seconds(5));
	//smilyDay_Track->play(*realVoicePool, *virtualVoicePool);
	//laserGun_Trigger_Track->play(*realVoicePool, *virtualVoicePool);
	//
	//bigWave_FullSound_Track->play(*realVoicePool, *virtualVoicePool);// passing in this pointer might be wrong ask tomorrow
	//laserGun_Charge_Track->play(*realVoicePool, *virtualVoicePool);
	//std::this_thread::sleep_for(std::chrono::seconds(1));
	//laserGun_Trigger_Track->play(*realVoicePool, *virtualVoicePool);
	
	//// maxing out the voice pool to see if the virtual voices kick in
	//bigWave_FullSound_Track->play(*realVoicePool, *virtualVoicePool);
	//laserGun_Charge_Track->play(*realVoicePool, *virtualVoicePool);
	//bigWave_FullSound_Track->play(*realVoicePool, *virtualVoicePool);
	//laserGun_Charge_Track->play(*realVoicePool, *virtualVoicePool);
	//bigWave_FullSound_Track->play(*realVoicePool, *virtualVoicePool);
	//laserGun_Charge_Track->play(*realVoicePool, *virtualVoicePool);
	//bigWave_FullSound_Track->play(*realVoicePool, *virtualVoicePool);
	//laserGun_Charge_Track->play(*realVoicePool, *virtualVoicePool);
	//bigWave_FullSound_Track->play(*realVoicePool, *virtualVoicePool);
	//laserGun_Charge_Track->play(*realVoicePool, *virtualVoicePool);
	//bigWave_FullSound_Track->play(*realVoicePool, *virtualVoicePool);
	//laserGun_Charge_Track->play(*realVoicePool, *virtualVoicePool);
	//bigWave_FullSound_Track->play(*realVoicePool, *virtualVoicePool);
	//laserGun_Charge_Track->play(*realVoicePool, *virtualVoicePool);
	//bigWave_FullSound_Track->play(*realVoicePool, *virtualVoicePool);
	//laserGun_Charge_Track->play(*realVoicePool, *virtualVoicePool);
	//bigWave_FullSound_Track->play(*realVoicePool, *virtualVoicePool);
	//laserGun_Charge_Track->play(*realVoicePool, *virtualVoicePool);

	//std::this_thread::sleep_for(std::chrono::seconds(120));
}

void EventManager::update(float dt)
{
	checkIfRealVoiceAvailable();
	//std::clog << "Update -> delta time test" << std::endl;
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

void EventManager::checkIfRealVoiceAvailable()
{
	
	// Virtual to Real Voice switch algorithm
	if (!realVoicePool->getAllVoicesActive())
	{
		for (auto& virtualVoice : virtualVoicePool->getVirtualVoicePool())
		{
			if (realVoicePool->getAllVoicesActive())
				break;
			if (virtualVoice && virtualVoice->getIsActive())
			{
				//std::clog << "EventManager -> Virtual Voice buffer size: " << virtualVoice->getBuffer().size() << std::endl;
				// - Find inactive real voice and call capture on the the virtual voice 
				//   in the virtual voice pool
				for (auto& realVoice : realVoicePool->getRealVoicePool())
				{
					realVoicePool->checkIfVoiceActive();
					if (realVoicePool->getAllVoicesActive())
						break;
					if (realVoice && !realVoice->getIsActive())
					{
						//std::clog << "EventManager -> Voice Switch algorithm -> Found Active Real Voice" << std::endl;
						//std::clog << "EventManager -> Virtual Voice buffer size: " << virtualVoice->getBuffer().size() << std::endl;
						realVoice->captureData(virtualVoice);
						realVoicePool->checkIfVoiceActive();
						//realVoicePool->setAllVoicesActive(true);
						//realVoicePool->getRealVoice();
						//virtualVoice->setIsActive(false);
						//break;
					}
					// check for real voices in real voice pool
				}
				// - Set the real voice to active


				//realVoicePool->getRealVoice()->transferDataFrom(voice);
				//virtualVoice->setIsActive(false);
				//notifyVoiceSwitch(realVoicePool->getRealVoice());
				std::clog << "EventManager -> PROMOTED a Virtual Voice to Real Voice" << std::endl;
			}
		}
	}
}

