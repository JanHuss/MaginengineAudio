#include "VirtualVoice.h"

void VirtualVoice::assignDataToBuffer(std::vector<float>& audioData, bool loop)
{																			
	buffer = audioData;
	isLooping = loop;
	playHead = 0;
	setIsActive(true);
}

void VirtualVoice::clearBuffer()
{
	buffer.clear();
    playHead = 0;
    setIsActive(false);
    std::clog << "Virtual Voice -> Buffer cleared" << std::endl;
    std::clog << "Virtual Voice -> buffer size: " << buffer.size() << std::endl;
}

void VirtualVoice::processAudio(float* outputBuffer, ma_uint32 frameCount)
{
	// std::clog << "Virtual Voice -> playhead stuff" << std::endl;

	for (ma_uint32 i = 0; i < frameCount; ++i)
	{
		if (playHead < buffer.size())
		{
			playHead++;
			//std::clog << "Virtual Voice playhead: " << playHead << std::endl;
		}
		else
		{
			if (isLooping)
				playHead = 0;
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
	return std::vector<float>();
}

void VirtualVoice::setIsActive(bool iActive)
{
	isActive = iActive;
}

bool VirtualVoice::getIsActive()
{
	return isActive;
}

//void VirtualVoice::passTrackToVoice(Leaf* leaf)
//{
//}
