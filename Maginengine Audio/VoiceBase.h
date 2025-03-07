// This is the Voice base class. This class is used to derive "Virtual" and
// "Real" Voices, each containing functionality for playback by updating 
// the Playback device's output buffer.

#pragma once

// Headers
#include "miniaudio.h"
//#include "Component.h"

// Libraries
#include <vector>
#include <iostream>
#include <algorithm>
#include <ostream>
#include <functional>

class VoiceBase
{
public:
	virtual void assignDataToBuffer(std::vector<float>& audioData, bool loop, std::function<void()> fCallback) = 0;
    virtual void clearBuffer() = 0;
    virtual void processAudio(float* outputBuffer, ma_uint32 frameCount) = 0;
    
    // has to be removed. just used for testing what the buffer is looking like in callback
    virtual std::vector<float> getBuffer() = 0;
    
    virtual void captureData() {};
    /*virtual void setTrackReference(Component& track) = 0;
    virtual Component& getTrackReference() = 0;*/
    //virtual void passTrackToVoice(Leaf* leaf) = 0;
};

