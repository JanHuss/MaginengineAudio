#include "PlaybackDevice.h"

PlaybackDevice::PlaybackDevice()
{
}

void PlaybackDevice::data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
	PlaybackDevice* playbackDevice = static_cast<PlaybackDevice*>(pDevice->pUserData);
    if (!playbackDevice)
    {
        memset(pOutput, 0, frameCount * sizeof(float) * pDevice->playback.channels);
        return;
    }
    
    float* outputbuffer = static_cast<float*>(pOutput);
    memset(outputbuffer, 0, frameCount * sizeof(float) * pDevice->playback.channels);
    // create a voice pointer to get a voice within the playback device class
    std::vector<RealVoice*> realVoices = playbackDevice->realVoicePool->getRealVoicePool();
    
    for (auto voice : realVoices)
    {
       if (voice && voice->getIsActive())
           voice->processAudio(outputbuffer, frameCount);       
    }
    std::vector<VirtualVoice*> virtualVoices = playbackDevice->virtualVoicePool->getVirtualVoicePool();
    
    for (auto voice : virtualVoices)
    {
       if (voice && voice->getIsActive())
           voice->processAudio(outputbuffer, frameCount);       
    }
}

int PlaybackDevice::init()
{
	deviceConfig = ma_device_config_init(ma_device_type_playback);
    deviceConfig.playback.format   = ma_format_f32;   // Set to ma_format_unknown to use the device's native format.
    deviceConfig.playback.channels = channels;               // Set to 0 to use the device's native channel count.
    deviceConfig.sampleRate        = sampleRate;           // Set to 0 to use the device's native sample rate.
    deviceConfig.dataCallback      = PlaybackDevice::data_callback;   // This function will be called when miniaudio needs more data.
    deviceConfig.pUserData         = this;   // Can be accessed from the device object (device.pUserData).
    
    if (ma_device_init(NULL, &deviceConfig, &device) != MA_SUCCESS)
    {
        std::cerr << "Playback Device -> Failed to open playback device!" << std::endl;
        return -3;  // Failed to initialize the device.
    }
    else
    {
        std::clog << "Playback Device -> Playback device initialised" << std::endl;
    }
    
    return true;
}

RealVoicePool* PlaybackDevice::getRealVoices()
{
    return realVoicePool;
}