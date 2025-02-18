// The Playback device is responsible for grabbing audio data within 
// all active "RealVoice" buffers.

#pragma once

// Headers
#include "miniaudio.h"
#include "RealVoice.h"
#include "VirtualVoice.h"
#include "RealVoicePool.h"
#include "VirtualVoicePool.h"

// Libraries
#include <iostream>
#include <vector>

class PlaybackDevice
{
public:
    PlaybackDevice();
    static void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);
    int init();
    RealVoicePool* getRealVoices();

    std::vector<RealVoice*>* realVoices;
    ma_device device;
    ma_device_config deviceConfig;
    RealVoicePool* realVoicePool = RealVoicePool::getInstance();
    VirtualVoicePool* virtualVoicePool = VirtualVoicePool::getInstance();

private:
    int channels = 2;
    int sampleRate = 44100;
};
