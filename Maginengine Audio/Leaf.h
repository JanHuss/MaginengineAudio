// Leaf is designated for "Tracks" that can make use of the transport 
// controls.
// Currently, Tracks are Children only and can only hold one audio asset.

#pragma once

// Headers
#include "Component.h"
#include "RealVoice.h"

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
    void assignTrackToRealVoice(RealVoice& realVoice);
    std::vector<float> getAudioData();

    // high-level interface
    void play(RealVoice& voice) override;
    void stop() const override;

    // low-level interface

private:
        std::vector<float> audioData;
};

