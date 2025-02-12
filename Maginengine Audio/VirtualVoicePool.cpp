#include "VirtualVoicePool.h"

VirtualVoicePool::VirtualVoicePool()
{
	 virtualVoicesCurrent = 2;

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
		std::cout << "VirtualVoicePool -> Reusing existing \"Virtual Voice\" from pool." << std::endl;
		VirtualVoice* virtualVoice = virtualVoices.front();
		virtualVoices.pop_front();
		std::cout << "VirtualVoicePool -> \"Virtual Voice\" pool size: " << virtualVoices.size() << std::endl;
		return virtualVoice;
	}
	else
	{
		std::cout << "VirtualVoicePool -> VoicePool is empty. Creating new \"Virtual Voice\" object." << std::endl;
		virtualVoices.push_back(new VirtualVoice);
		std::cout << "VirtualVoicePool -> New \"Virtual Voice\" added to pool. Current Pool size: " << virtualVoices.size() << std::endl;
		VirtualVoice* virtualVoice = virtualVoices.front();
		virtualVoices.pop_front();
		std::cout << "VirtualVoicePool -> New \"Virtual Voice\" assigned. Current Pool size: " << virtualVoices.size() << std::endl;
		return virtualVoice;
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
