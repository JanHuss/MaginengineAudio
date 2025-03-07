// A "Virtual Voice" is responsible of attaching itself to a Track being 
// played. The key difference of a "Virtual Voice" is that it does not 
// process any audio data the Track contains. It is solely responsible 
// for keeping track of the playhead position during playback.

#pragma once

// Headers
#include "miniaudio.h"
#include "VoiceBase.h"
//#include "Component.h"

// Libraries
#include <vector>
#include <iostream>
#include <algorithm>
#include <ostream>
#include <atomic>


enum VVTRANSPORTSTATE {VVPLAY, VVPAUSE};

class VirtualVoice : 
    public VoiceBase
{
public:
	void assignDataToBuffer(std::vector<float>& audioData, bool loop, std::function<void()> fCallback) override;
    void clearBuffer() override;
    void processAudio(float* outputBuffer, ma_uint32 frameCount) override;
    // has to be removed. just used for testing what the buffer is looking like in callback
    std::vector<float> getBuffer() override;

    void setIsActive(bool iActive);
    bool getIsActive();
    void captureData() override;
   // void passTrackToVoice(Leaf* leaf) override;

    bool isLooping = false;
    std::atomic<size_t> playHead = 0;

    // has to stay public for the Leaf class to access it
    VVTRANSPORTSTATE vVTransportState = VVTRANSPORTSTATE::VVPLAY;

private:
    //Component& trackReference;
    std::vector<float> buffer;
    bool isActive = false;
    int channels = 2;
    std::function<void()> finishedCallback;
};

