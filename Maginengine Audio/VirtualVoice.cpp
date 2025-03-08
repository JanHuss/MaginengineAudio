#include "VirtualVoice.h"

void VirtualVoice::assignDataToBuffer(std::vector<float>& audioData, bool loop, std::function<void()> fCallback)
{																			
	buffer = audioData;
	isLooping = loop;
	playHead.store(0);
	setIsActive(true);
	finishedCallback = fCallback;
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
	switch (vVTransportState)
	{
	case VVPLAY:
	{
		
		for (ma_uint32 i = 0; i < frameCount; ++i)
		{
			float threadPlayhead = playHead.load();
			if (threadPlayhead < buffer.size())
			{
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
					finishedCallback();
					break;
				}
			}
		

		}
		break;
	}
	case VVPAUSE:
	{
		break;
	}
	default:
		break;
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
