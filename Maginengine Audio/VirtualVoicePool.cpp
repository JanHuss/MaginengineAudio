#include "VirtualVoicePool.h"

VirtualVoicePool::VirtualVoicePool()
{
	 virtualVoicesCurrent = 10;

    for(int i = 0; i < virtualVoicesCurrent; i++)
	    virtualVoices.push_back(new VirtualVoice);
}

VirtualVoicePool* VirtualVoicePool::getInstance()
{
    if (instance == 0)
		instance = new VirtualVoicePool;
	//std::cout << "RealVoicePool -> getInstance() called" << std::endl;
	return instance;
}

VirtualVoice* VirtualVoicePool::getVirtualVoice()
{
    for(int i = 0; i < virtualVoices.size(); i++)
	{
		//std::clog << "VirtualVoicePool -> getVirtualVoice() -> size " << virtualVoices.size()<< std::endl;
		if (!virtualVoices[i]->getIsActive())
		{
			virtualVoicePoolIndex = i;
			break;
		}
		else if (i+1 == virtualVoices.size() && virtualVoices[i]->getIsActive())
		{
			//realVoices[i]->setPlayHead(0);
			setAllVoicesActive(true);
			//std::clog << "VirtualVoicePool -> All \"Virtual Voices\" are active." << std::endl;
		}
		if (getAllVoicesActive())
		{
			virtualVoices.push_back(new VirtualVoice);
			//std::clog << "VirtualVoicePool -> No Virtual Voices available. creating new Virtual Voice" << std::endl;
		}
	}	
	if (!virtualVoices[virtualVoicePoolIndex]->getIsActive())
	{
		virtualVoices[virtualVoicePoolIndex]->setIsActive(true);
		std::clog << "VirtualVoicePool -> Setting a Virtual Voice to: Active" << std::endl;
		return virtualVoices[virtualVoicePoolIndex];
	}
	
	return nullptr;
}

std::vector<VirtualVoice*> VirtualVoicePool::getVirtualVoicePool()
{
	return virtualVoices;
}

void VirtualVoicePool::setAllVoicesActive(bool aVActive)
{
	allVoicesActive = aVActive;
}

bool VirtualVoicePool::getAllVoicesActive()
{
	for (auto voice : virtualVoices)
	{
		if (!voice->getIsActive())
			return false;
	}
	return true;
	//return allVoicesActive;
}