// The "Voice" class contains the functionality to pass through the audio
// data it has been assigned to a buffer. The audio callback within the 
// "PlaybackDevice" class will listen to all voices and take any audio
// data a Voice may contain

#pragma once

// Headers
#include "miniaudio.h"
#include "VoiceBase.h"

// Libraries
#include <vector>
#include <iostream>
#include <algorithm>
#include <ostream>

class RealVoice : 
    public VoiceBase
{
public:
    void assignDataToBuffer(std::vector<float>& audioData) override;
    void clearBuffer() override;
    void processAudio(float* outputBuffer, ma_uint32 frameCount) override;
    void setIsActive(bool iActive);
    bool getIsActive();
    // has to be removed. just used for testing what the buffer is looking like in callback
    std::vector<float> getBuffer() override;

private:
    std::vector<float> buffer;
    size_t playHead = 0;
    bool isActive = false;
    int channels = 2;
    int pan = 0.5f;
};
