#include "RealVoicePool.h"

RealVoicePool::RealVoicePool()
{
	maxRealVoices = 2;
	for(int i = 0; i < maxRealVoices; i++)
	realVoices.push_back(new RealVoice);
}

RealVoicePool* RealVoicePool::getInstance()
{
	if (instance == 0)
		instance = new RealVoicePool;
	//std::cout << "RealVoicePool -> getInstance() called" << std::endl;
	return instance;
}

RealVoice* RealVoicePool::getRealVoice()
{
	if (!realVoices.empty())
	{
		//std::cout << "Creating new resource." << std::endl;
		//return new Resource;
		std::cout << "VirtualVoicePool -> Reusing existing Voice from pool." << std::endl;
		RealVoice* realVoice = realVoices.front();
		realVoices.pop_front();
		std::cout << "VirtualVoicePool -> Resources size: " << realVoices.size() << std::endl;
		return realVoice;
	}
	else
	{
		std::cout << "VirtualVoicePool -> Max Voices used. Cannot add further Voices." << std::endl;
		// direct to Virtual Voice Pool
	}
}

void RealVoicePool::returnRealVoice(RealVoice* object)
{
	object->clearBuffer();
	realVoices.push_back(object);
}

std::list<RealVoice*> RealVoicePool::getRealVoicePoolSize()
{
	return realVoices;
}
