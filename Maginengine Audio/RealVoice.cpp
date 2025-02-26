#include "RealVoice.h"


void RealVoice::assignDataToBuffer(std::vector<float>& audioData, bool loop)
{
    //std::clog << "Voice -> audio data size in voice: " << audioData.size() << std::endl;
    buffer = audioData;
    isLooping = loop;
    playHead.store(0);
    setIsActive(true);
    std::clog << "RealVoice -> Buffer size: " << buffer.size() << std::endl;
}

void RealVoice::clearBuffer()
{
    buffer.clear();
    playHead.store(0);
    setIsActive(false);
    std::clog << "RealVoice -> Buffer cleared" << std::endl;
    std::clog << "RealVoice -> buffer size: " << buffer.size() << std::endl;
}

void RealVoice::processAudio(float* outputBuffer, ma_uint32 frameCount)
{
    //std::clog << "Voice -> \"processAudio()\" being called" << std::endl;
    if (!getIsActive() || buffer.empty())
    {
        memset(outputBuffer, 0, frameCount * channels * sizeof(float));
        return;
    }

    // number of frames to hit the expected max/min fade
    const ma_uint32 fadeDuration = 256; 

    ma_uint32 i = 0;
    for (; i < frameCount; ++i)
    {
        size_t threadPlayhead = playHead.load();
        float sampleLeft = 0.0f;
        float sampleRight = 0.0f;
        
        if (threadPlayhead < buffer.size()-1)
        {
            if (channels == 1)
            {
                float sample = buffer[threadPlayhead++];
                playHead.store(threadPlayhead);
                sampleLeft = sample * (1.0f - pan);
                sampleRight = sample * pan;
                //std::clog << "RealVoice -> 1 Channel" << std::endl;
            }
            else if (channels == 2)
            {
                sampleLeft = buffer[threadPlayhead++];
                sampleRight = buffer[threadPlayhead++];
                playHead.store(threadPlayhead);
                
            }
            
        }
        else
        {
            // Loop
            if (isLooping)
            {
                threadPlayhead = 0;
                playHead.store(threadPlayhead);
            }
            // Stop
            else
            {
                //setIsActive(false);
                hasFadedIn = false;
                clearBuffer();
                std::cout << "Real Voice -> set Is active is false" << std::endl;
                break;
            }
        }

        // doesn't need to fade in again if is looping
        if (threadPlayhead > fadeDuration)
            hasFadedIn = true;

        // Calculate the fade in/out
        float fadeFactor = 1.0f;
        if (!hasFadedIn && threadPlayhead < fadeDuration)
            fadeFactor = (1.0f - cosf(3.14159265359 * threadPlayhead / fadeDuration)) * 0.5f;
        else if (!isLooping && buffer.size() - threadPlayhead < fadeDuration)
            fadeFactor = (1.0f - cosf(3.14159265359 * (buffer.size() - threadPlayhead) / fadeDuration)) * 0.5f;

        // pass fade, left and right samples to output buffer
        outputBuffer[i * 2] += sampleLeft * fadeFactor;
        outputBuffer[i * 2 + 1] += sampleRight * fadeFactor;
    }
}

void RealVoice::setIsActive(bool iActive)
{
    isActive = iActive;
}

bool RealVoice::getIsActive()
{
    return isActive;
}

void RealVoice::setPlayHead(size_t plHead)
{
    playHead = plHead;
}

size_t RealVoice::getPlayHead()
{
    return playHead;
}

std::vector<float> RealVoice::getBuffer()
{
    return buffer;
}

void RealVoice::captureData(VirtualVoice* virtualVoice)
{
    std::clog << "------------Start-----------------" << std::endl;
    std::clog << "RealVoice -> Capturing data test" << std::endl;
    clearBuffer();
    //std::clog << "RealVoice -> before data transfer buffer size: " << buffer.size() << std::endl;
    //buffer.resize(virtualVoice->getBuffer().size());
    //std::clog << "RealVoice -> virtual voice buffer size: " << virtualVoice->getBuffer().size() << std::endl;
    //buffer.resize(virtualVoice->getBuffer().size());
    this->buffer = virtualVoice->getBuffer();
    std::clog << "RealVoice -> after data transfer buffer size: " << buffer.size() << std::endl;
    //std::clog << "RealVoice -> play head before data transfer: " << playHead.load() << std::endl;
    playHead.store(virtualVoice->playHead);
    //std::clog << "RealVoice -> play head after data transfer: " << playHead.load() << std::endl;
    isLooping = virtualVoice->isLooping;
    //hasFadedIn = true;
    virtualVoice->clearBuffer();
    setIsActive(true);
   // virtualVoice->setIsActive(false);
    std::clog << "-----------End------------------" << std::endl;
}
