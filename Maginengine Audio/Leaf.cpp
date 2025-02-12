#include "Leaf.h"

std::string Leaf::Operation() const
{
    return "Track";
}

void Leaf::assignAssetToTrack(std::vector<float> asset)
{
    audioData = asset;
    std::cout << "Leaf -> assigning Asset to Track" << std::endl;
    std::cout << "Leaf -> audio data's current size: " << getAudioData().size() << std::endl;
}

void Leaf::assignTrackToRealVoice(RealVoicePool& realVoicePool)
{
        std::cout << "Leaf -> assigning Track to \"Real Voice\"" << std::endl;
        RealVoice* realVoice = realVoicePool.getRealVoice();
        realVoice->assignDataToBuffer(audioData);
}

void Leaf::assignTrackToVirtualVoice(RealVoicePool& realVoicePool)
{
    std::cout << "Leaf -> assigning Track to \"Virtual Voice\"" << std::endl;
}

void Leaf::removeTrackFromRealVoice(RealVoicePool& realVoicePool)
{
    std::cout << "Leaf -> Removing \"Real Voice\" from Track" << std::endl;
    RealVoice* realVoice = realVoicePool.getRealVoice();
    realVoice->clearBuffer();
}

std::vector<float> Leaf::getAudioData()
{
    //std::cout << "Leaf -> getting Audio Data" << std::endl;
    return audioData;
}

void Leaf::play(RealVoicePool& realVoicePool)
{
    if (realVoicePool.getRealVoicePoolSize().size() != 0)
    {
        voiceType = REAL;
        assignTrackToRealVoice(realVoicePool);
        std::cout << "is playing" << std::endl;
    }
    else
    {
        voiceType = VIRTUAL;
        assignTrackToVirtualVoice(realVoicePool);
        //std::cout << "Leaf -> No \"Real Voice\" Available. Assign asset to \"Virtual Voice\" " << std::endl;
    }
}

void Leaf::stop(RealVoicePool& realVoicePool)
{
    // remove track from Voice
    std::cout << "is stopping" << std::endl;
    switch (voiceType)
    {
    case REAL:
        removeTrackFromRealVoice(realVoicePool);
        break;
    case VIRTUAL:
        // removeTrackFromVirtualVoice(virtualVoicePool);
        break;
    default:
        break;
    }

    
}
