#include "VirtualVoice.h"

void VirtualVoice::assignDataToBuffer(std::vector<float>& audioData, bool loop)
{																			
	buffer = audioData;
	isLooping = loop;
	playHead.store(0);
	setIsActive(true);
}

void VirtualVoice::clearBuffer()
{
	buffer.clear();
    playHead.store(0);
    setIsActive(false);
    std::clog << "Virtual Voice -> Buffer cleared" << std::endl;
    std::clog << "Virtual Voice -> buffer size: " << buffer.size() << std::endl;
}

void VirtualVoice::processAudio(float* outputBuffer, ma_uint32 frameCount)
{
	// std::clog << "Virtual Voice -> process audio" << std::endl;
	// std::clog << "Virtual Voice -> buffer size: " << buffer.size() << std::endl;

	for (ma_uint32 i = 0; i < frameCount; ++i)
	{
		size_t threadPlayhead = playHead.load();
		if (threadPlayhead < buffer.size())
		{
			//if (channels == 1)
            //{
            //    threadPlayhead++;
            //    playHead.store(threadPlayhead);
            //}
            //else if (channels == 2)
            //{
            //    threadPlayhead++;
            //    threadPlayhead++;
            //    playHead.store(threadPlayhead);
            //    
            //}
			threadPlayhead++;
			//std::clog << "Virtual Voice playhead: " << playHead << std::endl;
			playHead.store(threadPlayhead);
		}
		else
		{
			if (isLooping)
			{
				threadPlayhead = 0;
				playHead.store(threadPlayhead);
			}
			else
			{
				setIsActive(false);
				std::clog << "Virtual Voice -> set Is active is false" << std::endl;
                break;
			}
		}
		
	}
}


std::vector<float> VirtualVoice::getBuffer()
{
	return buffer;
}

void VirtualVoice::setIsActive(bool iActive)
{
	isActive = iActive;
}

bool VirtualVoice::getIsActive()
{
	return isActive;
}

void VirtualVoice::captureData()
{
	std::clog << "VirtualVoice -> Empty Function" << std::endl;
}
