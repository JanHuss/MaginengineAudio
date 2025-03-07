#include "EventManager.h"

EventManager::EventManager() /*: playbackDevice(realVoicePool)*/
{
}

EventManager::~EventManager()
{
	delete tree;
	delete bigWave_Event;
	delete bigWave;
	delete trapDoor_Event;
	delete trapDoor;
	delete smilyDay_Event;
	delete smilyDay_Track;

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
	//trapDoor->setVolume(0.5f);
	bigWave->assignAssetToTrack(bigWave_Asset.getAudioData()); 
	bigWave->setLoop(false);

	tree->Add(trapDoor_Event);
	trapDoor_Event->Add(trapDoor);
	trapDoor_Asset.loadFile("assets/audio/TrapDoor.wav");
	trapDoor->setVolume(0.5f);
	trapDoor->assignAssetToTrack(trapDoor_Asset.getAudioData()); 
	trapDoor->setLoop(false);

	tree->Add(smilyDay_Event);
	smilyDay_Event->Add(smilyDay_Track);
	smilyDay_Asset.loadFile("assets/audio/SmileyDayToYa.wav");
	smilyDay_Track->assignAssetToTrack(smilyDay_Asset.getAudioData());
	smilyDay_Track->setLoop(true);

	tree->Add(janVoice_Event);
	janVoice_Event->Add(janVoice_Track);
	janVoice_Asset.loadFile("assets/audio/voiceJan.wav");
	janVoice_Track->assignAssetToTrack(janVoice_Asset.getAudioData());
	janVoice_Track->setLoop(false);

	tree->Add(thisIsMyVoice_Event);
	thisIsMyVoice_Event->Add(thisIsMyVoice_Track);
	thisIsMyVoice_Asset.loadFile("assets/audio/thisIsMyVoice.wav");
	thisIsMyVoice_Track->assignAssetToTrack(thisIsMyVoice_Asset.getAudioData());
	thisIsMyVoice_Track->setLoop(false);


	TreeStructure(tree);

	//std::cout << "EventManager -> Getting audio data size: " << bigWave_FullSound_Track->getAudioData().size() << std::endl;
	//std::cout << "EventManager -> Getting RealVoicePool size: " << realVoicePool->getRealVoicePool().size() << std::endl;	

	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "---------------------Playing Song-------------------" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	// Test runs
	smilyDay_Track->play();
	std::this_thread::sleep_for(std::chrono::seconds(3));
	//std::cout << "----------------------------------------------------" << std::endl;
	//std::cout << "---------------------Test 01------------------------" << std::endl;
	//std::cout << "--------------trap door - big wave------------------" << std::endl;
	//
	//trapDoor->play(*realVoicePool, *virtualVoicePool);
	//bigWave->play(*realVoicePool, *virtualVoicePool);
	//std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "---------------------Test 02------------------------" << std::endl;
	std::cout << "big wave - trap door - this is my voice - jan voice-" << std::endl;
	smilyDay_Track->setVolume(0.5f);
	//smilyDay_Track->pause();
	//std::this_thread::sleep_for(std::chrono::seconds(1));
	//bigWave->play(*realVoicePool, *virtualVoicePool);
	//trapDoor->play();
	std::this_thread::sleep_for(std::chrono::seconds(3));
	//trapDoor->play();
	smilyDay_Track->setVolume(2.0f);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	smilyDay_Track->setPanning(0.2, 0.8);
	//trapDoor->play();
	std::this_thread::sleep_for(std::chrono::seconds(3));
	smilyDay_Track->setPanning(0.8, 0.2);
	//trapDoor->play();
	std::this_thread::sleep_for(std::chrono::seconds(3));
	smilyDay_Track->setPanning(0.5, 0.5);
	//trapDoor->play();
	std::this_thread::sleep_for(std::chrono::seconds(3));
	smilyDay_Track->setPitch(2.0f);
	//smilyDay_Track->play();
	//std::this_thread::sleep_for(std::chrono::seconds(10));
	//smilyDay_Track->pause();
	//std::this_thread::sleep_for(std::chrono::seconds(3));
	//smilyDay_Track->play();
	//thisIsMyVoice_Track->play();
	//std::this_thread::sleep_for(std::chrono::seconds(3));
	//janVoice_Track->play();

	//std::this_thread::sleep_for(std::chrono::seconds(1));
	//std::this_thread::sleep_for(std::chrono::seconds(1));
	//smilyDay_Track->play(*realVoicePool, *virtualVoicePool);
	//smilyDay_Track->setLoop(false);
	//trapDoor->play(*realVoicePool, *virtualVoicePool);
	//std::this_thread::sleep_for(std::chrono::seconds(1));
	//bigWave->play(*realVoicePool, *virtualVoicePool);
	//smilyDay_Track->play(*realVoicePool, *virtualVoicePool);
	//smilyDay_Track->setLoop(true);
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
						std::clog << "EventManager -> PROMOTED a Virtual Voice to Real Voice" << std::endl;
						break;
					}
					
					// check for real voices in real voice pool
				}
				// - Set the real voice to active


				//realVoicePool->getRealVoice()->transferDataFrom(voice);
				//virtualVoice->setIsActive(false);
				//notifyVoiceSwitch(realVoicePool->getRealVoice());
			}
		}
	}
}

