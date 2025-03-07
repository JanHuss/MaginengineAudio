#include "Leaf.h"
//#include "RealVoice.h"
//#include "VirtualVoice.h"


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

void Leaf::assignTrackToRealVoice()
{
    realVoice = realVoicePool->getRealVoice();
    if (realVoice)
    {
        setIsPlaying(true);
        std::cout << "Leaf -> assigning Track to \"Real Voice\"" << std::endl;
        realVoice->assignDataToBuffer(audioData, getLoop(), [this](){
           realVoice = nullptr; });
    }
}

void Leaf::assignTrackToVirtualVoice()
{
    virtualVoice = virtualVoicePool->getVirtualVoice();
    if (virtualVoice)
    {
        setIsPlaying(true);
        std::cout << "Leaf -> assigning Track to \"Virtual Voice\"" << std::endl;
        virtualVoice->assignDataToBuffer(audioData, getLoop(), [this](){
           realVoice = nullptr; });
        // give the virtual voice a reference of the track it is directing to
       
    }
}

void Leaf::removeTrackFromRealVoice()
{
   if(realVoice)
    {
        setIsPlaying(false);
        std::cout << "Leaf -> Removing \"Real Voice\" from Track" << std::endl;
        realVoice->clearBuffer();
        realVoice = nullptr;
    }
}

void Leaf::removeTrackFromVirtualVoice()
{
    if (virtualVoice)
    {
        setIsPlaying(false);
        std::cout << "Leaf -> Removing \"Virtual Voice\" from Track" << std::endl;
        virtualVoice->clearBuffer();
        virtualVoice = nullptr;
    }
}

std::vector<float> Leaf::getAudioData()
{
    //std::cout << "Leaf -> getting Audio Data" << std::endl;
    return audioData;
}

void Leaf::play()
{
    if (!realVoicePool->getAllVoicesActive())
    {
        voiceType = REAL;
        if(!realVoice)
            assignTrackToRealVoice();
        realVoice->rVTransportState = RVPLAY;
        std::cout << "Leaf-> is playing real voice" << std::endl;
    }
    else
    {
        voiceType = VIRTUAL;
        if(!realVoice)
            assignTrackToVirtualVoice();
        virtualVoice->vVTransportState = VVPLAY;
        std::cout << "Leaf -> No \"Real Voice\" Available. Assign asset to \"Virtual Voice\" " << std::endl;
    }
}

void Leaf::pause()
{
    std::clog << "Leaf -> Is pausing" << std::endl;
    switch (voiceType)
    {
    case REAL:
        // add enmum to pause state here
        realVoice->rVTransportState = RVPAUSE; 
        std::cout << "Leaf-> is pausing real voice" << std::endl;
        break;
    case VIRTUAL:
        // add enmum to pause state here
        virtualVoice->vVTransportState = VVPAUSE;
        std::cout << "Leaf-> is pausing virtual voice" << std::endl;
        break;
    }
}

void Leaf::stop()
{
    // remove track from Voice
    std::cout << "Leaf -> Is stopping" << std::endl;
    switch (voiceType)
    {
    case REAL:
        removeTrackFromRealVoice();
        break;
    case VIRTUAL:
        removeTrackFromVirtualVoice();
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

void Leaf::setIsPlaying(bool isPl)
{
    isPlaying = isPl;
}

bool Leaf::getIsPlaying()
{
    return isPlaying;
}
