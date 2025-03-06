// Maginengine Audio.cpp : This file contains the 'main' function. 

// Headers
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include "Engine.h"
#include "RealVoicePool.h"
#include "VirtualVoicePool.h"

// Libraries
#include <iostream>
#include <chrono>


RealVoicePool* RealVoicePool::instance = 0;
VirtualVoicePool* VirtualVoicePool::instance = 0;

int main()
{
    // calculating delta time
    float deltaTime;
	std::chrono::steady_clock::time_point lastUpdate;
	auto now = std::chrono::steady_clock::now();
	deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - lastUpdate).count() / 1000000.0f;
	lastUpdate = now;

    Engine engine;
    engine.run(deltaTime);

    return 0;
}