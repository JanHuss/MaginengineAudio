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
    if (!virtualVoices.empty())
	{
		//std::cout << "Creating new resource." << std::endl;
		//return new Resource;
		std::cout << "VirtualVoicePool -> Reusing existing Voice from pool." << std::endl;
		VirtualVoice* realVoice = virtualVoices.front();
		virtualVoices.pop_front();
		std::cout << "VirtualVoicePool -> Resources size: " << virtualVoices.size() << std::endl;
		return realVoice;
	}
	else
	{
		std::cout << "VirtualVoicePool -> VoicePool is empty. Creating new \"Virtual Voice\" object." << std::endl;
		virtualVoices.push_back(new VirtualVoice);
	}
}

void VirtualVoicePool::returnVirtualVoice(VirtualVoice* object)
{
	object->clearBuffer();
	virtualVoices.push_back(object);
}

std::list<VirtualVoice*> VirtualVoicePool::getVirtualVoicePoolSize()
{
    return virtualVoices;
}
