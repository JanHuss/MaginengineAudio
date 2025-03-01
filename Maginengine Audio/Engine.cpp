#include "Engine.h"

Engine::Engine()
{
	developmentState = STANDALONE;
	init();
}

Engine::~Engine()
{
	std::cout << "!!! *********************** !!!" << std::endl;
	std::cout << "!!! Engine -> Shutting down !!!" << std::endl;
	std::cout << "!!! *********************** !!!" << std::endl;
}

int Engine::init()
{
	//std::cout << "Engine -> init() called()" << std::endl;

	playbackDevice.init();

	// start playback device which will run callback function and wait for any audio data to be passed through
	if (ma_device_start(&playbackDevice.device) != MA_SUCCESS)
	{
		std::cerr << "Engine -> Failed to start playback device." << std::endl;
		ma_device_uninit(&playbackDevice.device);
		// this is already creating a red flag. all decoders should be uninitialised at once
		// making use of a resource manager or something. look into this later.
		//ma_decoder_uninit(&bigWave.decoder); 
		return -4;
	}
	else
		std::cout << "Engine -> Playback device started" << std::endl;

	eventManager.init();
}

void Engine::run(float deltaTime)
{
	switch (developmentState)
	{
	case Engine::STANDALONE:
		// This state only runs an endless while loop in order to test audio playback. It will contain a Dear IMGUI window.
		// Needs to be able to be closed when ui is implemented and via ESCAPE key
		while(true)
		{
			eventManager.update(deltaTime);
		}
		break;
	case Engine::ATTACHED:
		// This state is supposed to run the application without displaing any Audio Engine UI elements
		eventManager.update(deltaTime);
		break;
	case Engine::ATTACHEDDEBUG:
		// This state will launch a Dear IMGUI window to debug during runtime
		break;
	default:
		break;
	}
	//std::cout << "Engine -> run() called()" << std::endl;
	
}
