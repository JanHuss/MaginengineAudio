// The "Voice" class contains the functionality to pass through the audio
// data it has been assigned to a buffer. The audio callback within the 
// "PlaybackDevice" class will listen to all voices and take any audio
// data a Voice may contain

#pragma once

// Headers
#include "miniaudio.h"
#include "VoiceBase.h"
#include "VirtualVoice.h"
//#include "Component.h"

// Libraries
#include <vector>
#include <iostream>
#include <algorithm>
#include <ostream>
#include <atomic>
#include <mutex>
#include <functional>

enum RVTRANSPORTSTATE {RVPLAY, RVPAUSE};

class RealVoice : 
    public VoiceBase
{
public:
    void assignDataToBuffer(std::vector<float>& audioData, bool loop, std::function<void()> fCallback) override;
    void clearBuffer() override;
    void processAudio(float* outputBuffer, ma_uint32 frameCount) override;
    void setIsActive(bool iActive);
    bool getIsActive();
    void setPlayHead(size_t plHead);
    size_t getPlayHead();
    // has to be removed. just used for testing what the buffer is looking like in callback
    std::vector<float> getBuffer() override;
    void captureData(VirtualVoice* vVoice);
    //std::mutex dataTransferMutex;
    void fadeIn(ma_uint32 elaspedFrames, ma_uint32 elapsedFadeDuration);
    void fadeOut(int elaspedFrames, int elapsedFadeDuration);
    
    RVTRANSPORTSTATE rVTransportState = RVTRANSPORTSTATE::RVPLAY;

private:
    std::vector<float> buffer;
    std::atomic<size_t> playHead {0};
    size_t pausedPlayhead;
    size_t pausedStartPlayhead;
    bool isActive = false;
    int channels = 2;
    int pan = 0.5f;
    bool isLooping = false;
    bool hasFadedIn = false;
    bool unPaused = true;
    bool pausedStartSet = false;
    std::function<void()> finishedCallback;
    

};
