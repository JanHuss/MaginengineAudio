// A "Virtual Voice" is responsible of attaching itself to a Track being 
// played. The key difference of a "Virtual Voice" is that it does not 
// process any audio data the Track contains. It is solely responsible 
// for keeping track of the playhead position during playback.

#pragma once

// Headers
#include "miniaudio.h"
#include "VoiceBase.h"

// Libraries
#include <vector>
#include <iostream>
#include <algorithm>
#include <ostream>

class VirtualVoice : 
    public VoiceBase
{
public:
	void assignDataToBuffer(std::vector<float>& audioData) override;
    void clearBuffer() override;
    void processAudio(float* outputBuffer, ma_uint32 frameCount) override;
    
    // has to be removed. just used for testing what the buffer is looking like in callback
    std::vector<float> getBuffer() override;

private:
    std::vector<float> buffer;
    size_t playHead = 0;
    bool isPlaying = false;
};

