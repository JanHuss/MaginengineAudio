#include "RealVoice.h"

void RealVoice::assignDataToBuffer(std::vector<float>& audioData)
{
    //std::clog << "Voice -> audio data size in voice: " << audioData.size() << std::endl;
    buffer = audioData;
    playHead = 0;
    setIsActive(true);
    if (!buffer.empty())
        std::clog << "RealVoice -> Buffer not empty. Audio data assigned to Buffer" << std::endl;
    std::clog << "RealVoice -> Buffer size: " << buffer.size() << std::endl;
}

void RealVoice::clearBuffer()
{
    buffer.clear();
    playHead = 0;
    setIsActive(false);
    std::clog << "RealVoice -> Buffer cleared" << std::endl;
    std::clog << "RealVoice -> buffer size: " << buffer.size() << std::endl;
}

void RealVoice::processAudio(float* outputBuffer, ma_uint32 frameCount)
{
    //std::clog << "Voice -> \"processAudio()\" being called" << std::endl;
    if (!getIsActive() || buffer.empty())
    {
        memset(outputBuffer, 0, frameCount * sizeof(float)/* * channels*/);
        return;
    }

    for (ma_uint32 i = 0; i < frameCount; ++i)
    {
        //float sample = 0.0f;
        float sampleLeft = 0.0f;
        float sampleRight = 0.0f;
        
        if (playHead < buffer.size())
        {
            // sample = buffer[playHead++];
            if (channels == 1)
            {
                float sample = buffer[playHead];
                sampleLeft = sample * (1.0f - pan);
                sampleRight = sample * pan;
            }
            else if (channels == 2)
            {
                sampleLeft = buffer[playHead++];
                sampleRight = buffer[playHead++];
            }
        }
        else
        {
            // add looping here

            // add stop here
            setIsActive(false);
            break;
        }

        
        outputBuffer[i * 2] = sampleLeft;
        outputBuffer[i * 2 + 1] = sampleRight;
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

std::vector<float> RealVoice::getBuffer()
{
    return buffer;
}
