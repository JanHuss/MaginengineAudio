// An asset is capable of loading an audio file using the "miniaud.io" 
// "ma_decoder" type. This class will receive an overhaul, making use
// of a "ResourceManager" class.

#pragma once

// Headers
#include "miniaudio.h"

// Libraries
#include <string>
#include <iostream>
#include <vector>

class Asset
{
public:
    Asset();
    ~Asset();
    
    static void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);
    int initDevice();
    int loadFile(const std::string filePath);
    void currentFileLoadedOnDevice(std::string filePath);
    void unload(std::string filepath);

    // setter
    void setAudioData(std::vector<float> aD);
    

    // getter
    std::vector<float> getAudioData();
    ma_uint64 getTotalFrameCount();

    // public variables
    ma_decoder decoder;
    ma_decoder_config decoderConfig;
    ma_audio_buffer_config bufferConfig;
    
private:
    int channels;
    int sampleRate;
    float volume;
    bool isLoaded = false;
    ma_uint64 totalFrames;

    std::vector<float> audioData ={};    
    
};
