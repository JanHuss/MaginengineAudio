// The "Voice" class contains the functionality to pass through the audio
// data it has been assigned to a buffer. The audio callback within the 
// "PlaybackDevice" class will listen to all voices and take any audio
// data a Voice may contain

#pragma once

// Headers
#include "miniaudio.h"

// Libraries
#include <vector>
#include <iostream>
#include <algorithm>
#include <ostream>

class RealVoice
{
public:
    void assignDataToBuffer(std::vector<float>& audioData);
    void clearBuffer();
    void processAudio(float* outputBuffer, ma_uint32 frameCount);
    
    // has to be removed. just used for testing what the buffer is looking like in callback
    std::vector<float> getBuffer();

private:
    std::vector<float> buffer;
    size_t playHead = 0;
    bool isPlaying = false;
    int channels = 2;
    int pan = 0.5f;
};
