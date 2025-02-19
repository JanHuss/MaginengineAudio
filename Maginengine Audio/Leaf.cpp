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
    RealVoice* realVoice = realVoicePool.getRealVoice();
    if (realVoice)
    {
        std::cout << "Leaf -> assigning Track to \"Real Voice\"" << std::endl;
        realVoice->assignDataToBuffer(audioData, getLoop());
    }
}

void Leaf::assignTrackToVirtualVoice(VirtualVoicePool& virtualVoicePool)
{
    VirtualVoice* virtualVoice = virtualVoicePool.getVirtualVoice();
    if (virtualVoice)
    {
        std::cout << "Leaf -> assigning Track to \"Virtual Voice\"" << std::endl;
        virtualVoice->assignDataToBuffer(audioData, getLoop());
        // pass through "this" as a pointer into virtualVoice
    }
}

void Leaf::removeTrackFromRealVoice(RealVoicePool& realVoicePool)
{
    std::cout << "Leaf -> Removing \"Real Voice\" from Track" << std::endl;
    RealVoice* realVoice = realVoicePool.getRealVoice();
    realVoice->clearBuffer();
}

void Leaf::removeTrackFromVirtualVoice(VirtualVoicePool& virtualVoicePool)
{
    std::cout << "Leaf -> Removing \"Virtual Voice\" from Track" << std::endl;
    VirtualVoice* virtualVoice = virtualVoicePool.getVirtualVoice();
    virtualVoice->clearBuffer();
}

std::vector<float> Leaf::getAudioData()
{
    //std::cout << "Leaf -> getting Audio Data" << std::endl;
    return audioData;
}

void Leaf::play(RealVoicePool& realVoicePool, VirtualVoicePool& virtualVoicePool)
{
    if (!realVoicePool.getAllVoicesActive())
    {
        voiceType = REAL;
        assignTrackToRealVoice(realVoicePool);
        std::cout << "Leaf-> is playing real voice" << std::endl;
    }
    else
    {
        voiceType = VIRTUAL;
        assignTrackToVirtualVoice(virtualVoicePool);
        std::cout << "Leaf -> No \"Real Voice\" Available. Assign asset to \"Virtual Voice\" " << std::endl;
    }
}

void Leaf::stop(RealVoicePool& realVoicePool, VirtualVoicePool& virtualVoicePool)
{
    // remove track from Voice
    std::cout << "is stopping" << std::endl;
    switch (voiceType)
    {
    case REAL:
        removeTrackFromRealVoice(realVoicePool);
        break;
    case VIRTUAL:
        removeTrackFromVirtualVoice(virtualVoicePool);
        break;
    default:
        break;
    }

    
}

void Leaf::setVolume(float vol)
{
    volume = vol;
    adjustVolume();
}

void Leaf::adjustVolume()
{
    for (auto& sample : audioData)
        sample *= volume;
}

void Leaf::setCurrentVoice(VoiceBase* voice)
{
    currentVoice = voice;
}

VoiceBase* Leaf::getCurrentVoice()
{
    return currentVoice;
}

void Leaf::onVoiceSwitched(VoiceBase* newVoice)
{
  setCurrentVoice(newVoice);
}
