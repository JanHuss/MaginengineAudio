// Leaf is designated for "Tracks" that can make use of the transport 
// controls.
// Currently, Tracks are Children only and can only hold one audio asset.

#pragma once

// Headers
#include "Component.h"
#include "RealVoicePool.h"
#include "VirtualVoicePool.h"
#include "IObserver.h"

// Libraries
#include <string>
#include <vector>
#include <iostream>

class EventManager;

class Leaf :
    public Component,    
        public IObserver
{
public:
    std::string Operation() const override; 

    void assignAssetToTrack(std::vector<float> asset);

    void assignTrackToRealVoice(RealVoicePool& realVoicePool);
    void assignTrackToVirtualVoice(VirtualVoicePool& VirtualVoicePool);

    void removeTrackFromRealVoice(RealVoicePool& realVoicePool);
    void removeTrackFromVirtualVoice(VirtualVoicePool& virtualVoicePool);

    std::vector<float> getAudioData();

    // high-level interface
    void play(RealVoicePool& realVoicePool, VirtualVoicePool& virtualVoicePool) override;
    void stop(RealVoicePool& realVoicePool, VirtualVoicePool& virtualVoicePool) override;

    void setVolume(float vol) override;

    // low-level interface
    void adjustVolume() override;

    void setCurrentVoice(VoiceBase* voice);
    VoiceBase* getCurrentVoice();

    void onVoiceSwitched(VoiceBase* newVoice) override;
    
private:
    std::vector<float> audioData;
    enum VOICETYPE {REAL, VIRTUAL};
    VOICETYPE voiceType;
    float volume;
    bool isLooping;
    VoiceBase* currentVoice = nullptr;

};

