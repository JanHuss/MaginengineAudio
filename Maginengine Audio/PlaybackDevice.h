#pragma once

// Headers
#include "miniaudio.h"
#include "RealVoice.h"
#include "VirtualVoice.h"
#include "RealVoicePool.h"

// Libraries
#include <iostream>
#include <vector>

class PlaybackDevice
{
public:
    PlaybackDevice();
    static void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);
    int init();
    //RealVoice* getRealVoice();
    RealVoicePool* getRealVoices();
    //VirtualVoice* getVirtualVoice();

    // the voice pointer needs to be set to pUserData on initialisation
    // then, the voice will be able to pass through the buffer
    // what I don't have is the voice pointer being assigned.
   //RealVoice* realVoice;
   //VirtualVoice* virtualVoice;
    std::vector<RealVoice*>* realVoices;
    //RealVoicePool* realVoicePool;

    // public varaibles
    ma_device device;
    ma_device_config deviceConfig;

    RealVoicePool* realVoicePool = RealVoicePool::getInstance();

private:
    int channels = 2;
    int sampleRate = 41000;
    //int readIndex; // audio playhead 
};
