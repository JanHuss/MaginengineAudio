#include "Asset.h"

Asset::Asset()
{
    decoderConfig = ma_decoder_config_init(ma_format_f32, channels, sampleRate);
}

Asset::~Asset()
{
    ma_decoder_uninit(&decoder);
}

int Asset::loadFile(std::string filePath)
{
    if (isLoaded)
    {
        std::cerr << "File: \"" << filePath << "\" already loaded."   << std::endl;
    }
    else
    {
        // initialise the filepath to the decoder using the decoder configurations. this loads the file to the decoder
        if (ma_decoder_init_file(filePath.c_str(), &decoderConfig, &decoder) != MA_SUCCESS)
        {
            std::cerr << "Failed to load file!" << filePath << std::endl;
            return -2; 
        }
        else
        {
            std::clog << "Loaded file: " << filePath << std::endl;
            isLoaded = true;
        }

        //get the length of the file
        if (ma_decoder_get_length_in_pcm_frames(&decoder, &totalFrames) != MA_SUCCESS)
        {
            std::cerr << "Failed to get total frame count of file: " << filePath << std::endl;
            return false;
        }
        //std::clog << "TotalFrames of asset called within asset class for file \"" << filePath << "\": " << totalFrames << std::endl;
        // set the channels and samplerate of the file(which is loaded in the decoder) to the channel and samplerate variables
        channels = decoder.outputChannels;
        sampleRate = decoder.outputSampleRate;
        
        // set the size of the audioData array based on the file length and channels
        audioData.resize(totalFrames * channels);
        setAudioData(audioData);
        //std::clog << "Audio data in asset class: "  << getAudioData().size() << std::endl;

        // The way I understand this is that you need to resize the vector "audioData" so that
        // "ma_decoder_read_pcm_frames" knows how many samples there are in "totalFrames" as
        // "totalFrames" has 2 samples per frame.
        if (ma_decoder_read_pcm_frames(&decoder, audioData.data(), totalFrames, &totalFrames) != MA_SUCCESS)
        {
            std::cerr << "Did not read PCM frames into buffer for file: " << filePath << std::endl;
            return -2;
        }

        currentFileLoadedOnDevice(filePath); // this just contains a bunch of strings to confirm the audio data's data
    }
    
    return true;
}

void Asset::currentFileLoadedOnDevice(std::string filePath)
{
    // Check to ensure all data within asset is correct
  //std::cout << "- Audio data check within audioAsset.load() ----------------------" << std::endl;
  //std::cout << "File loaded: " << filePath << std::endl;
  //std::cout << "Total frames in audioAsset.load(): " << totalFrames << std::endl;
  //std::cout << "Channels in audioAsset.load(): " << channels << std::endl;
  //std::cout << "Sample rate in audioAsset.load(): " << sampleRate << std::endl;
  //std::cout << "Audio data size in audioAsset.load(): " << audioData.size() << std::endl;
  //std::cout << "-------------------------------------------------------------------\n" << std::endl;
}

void Asset::unload(std::string filePath)
{
    if (isLoaded)
    {
        audioData.clear();
        totalFrames = 0;
        channels = 0;
        sampleRate = 0;
        isLoaded = false;
        std::clog << "Unloaded audio file: " << filePath << std::endl;
    }
}

void Asset::setAudioData(std::vector<float> aD)
{
    audioData = aD;
}

std::vector<float> Asset::getAudioData()
{
    return audioData;
}

ma_uint64 Asset::getTotalFrameCount()
{
    return totalFrames;
}



