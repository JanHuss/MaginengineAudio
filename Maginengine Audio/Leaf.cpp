#include "Leaf.h"

std::string Leaf::Operation() const
{
    return "Track";
}

void Leaf::assignAssetToTrack(std::vector<float> asset)
{
    std::cout << "Leaf -> assigning Asset to Track" << std::endl;

    audioData = asset;
}

std::vector<float> Leaf::getAudioData()
{
    std::cout << "Leaf -> getting Audio Data" << std::endl;
    return audioData;
}

void Leaf::play() const
{
    // assign track to Voice
    std::cout << "is playing" << std::endl;
}

void Leaf::stop() const
{
    // remove track from Voice
}
