// Maginengine Audio.cpp : This file contains the 'main' function. 
// Program execution begins and ends there.
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include "RealVoicePool.h"
#include "VirtualVoicePool.h"

#include <iostream>
#include "Engine.h"


RealVoicePool* RealVoicePool::instance = 0;
VirtualVoicePool* VirtualVoicePool::instance = 0;

int main()
{
    Engine engine;
    engine.run();

    return 0;
}