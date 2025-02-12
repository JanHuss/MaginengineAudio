// Leaf is designated for "Tracks" that can make use of the transport 
// controls.
// Currently, Tracks are Children only and can only hold one audio asset.

#pragma once

// Headers
#include "Component.h"
#include "RealVoice.h"
#include "RealVoicePool.h"

// Libraries
#include <string>
#include <vector>
#include <iostream>


class Leaf :
    public Component
{
public:
    std::string Operation() const override; 

    void assignAssetToTrack(std::vector<float> asset);
    void assignTrackToRealVoice(RealVoicePool& realVoicePool);
    void assignTrackToVirtualVoice(RealVoicePool& realVoicePool);
    void removeTrackFromRealVoice(RealVoicePool& realVoicePool);

    std::vector<float> getAudioData();

    // high-level interface
    void play(RealVoicePool& realVoicePool) override;
    void stop(RealVoicePool& realVoicePool) override;

    // low-level interface

    
private:
    std::vector<float> audioData;
    enum VOICETYPE {REAL, VIRTUAL};
    VOICETYPE voiceType;

};

