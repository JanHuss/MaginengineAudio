#include "Leaf.h"

std::string Leaf::Operation() const
{
    return "Track";
}

void Leaf::assignAssetToTrack(std::vector<float> asset)
{
    std::cout << "Leaf -> assigning Asset to Track" << std::endl;
    std::cout << "Leaf -> audio data's current size: " << getAudioData().size() << std::endl;
    audioData = asset;
}

void Leaf::assignTrackToRealVoice(RealVoice& realVoice)
{
    std::cout << "Leaf -> calling assignTrackToRealVoice function" << std::endl;
    realVoice.assignDataToBuffer(audioData);
}

std::vector<float> Leaf::getAudioData()
{
    //std::cout << "Leaf -> getting Audio Data" << std::endl;
    return audioData;
}

void Leaf::play(RealVoice& voice)
{
    // assign track to Voice
    assignTrackToRealVoice(voice);
    std::cout << "is playing" << std::endl;
}

void Leaf::stop() const
{
    // remove track from Voice
}
