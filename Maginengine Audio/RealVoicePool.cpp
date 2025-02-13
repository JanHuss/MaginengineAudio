#include "RealVoicePool.h"

RealVoicePool::RealVoicePool()
{
	maxRealVoices = 10;
	for(int i = 0; i < maxRealVoices; i++)
	realVoices.push_back(new RealVoice);
	setAllVoicesActive(false);
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
	//if (!realVoices.empty())
	//{
		//std::cout << "Creating new resource." << std::endl;
		//return new Resource;
		//std::cout << "RealVoicePool -> Reusing existing \"Real Voice\" from pool." << std::endl;
		//RealVoice* realVoice = realVoices.front();
		//realVoices.pop_front();
		//std::cout << "RealVoicePool -> \"Real Voice\" pool size: " << realVoices.size() << std::endl;

	for(int i = 0; i < realVoices.size(); i++)
	{
		//std::clog << "RealVoicePool -> realVoices.size(): " << realVoices.size()<< std::endl;
		if (!realVoices[i]->getIsActive())
			realVoicePoolIndex = i;
		else if (i+1 == realVoices.size() && realVoices[i]->getIsActive())
		{
			setAllVoicesActive(true);
			std::clog << "RealVoicePool -> All \"Real Voices\" are active." << std::endl;
		}
		
	}	
	if (!realVoices[realVoicePoolIndex]->getIsActive())
	{
		realVoices[realVoicePoolIndex]->setIsActive(true);
		std::clog << "RealVoicePool -> Setting a Real Voice to: Active" << std::endl;
		return realVoices[realVoicePoolIndex];
	}
	//else
	//{
	//	std::clog << "RealVoicePool -> All \"Real Voices\" are active." << std::endl;
	//	//setAllVoicesActive(true);
	//	return nullptr;
	//}
			
	//return nullptr;

		// iterate through list
		// if a voice is not active, set the voice to active, then return the voice


	//}
	//else
	//{
	//	std::cout << "RealVoicePool -> Max \"Real Voices\" used. Cannot add further \"Real Voices\"." << std::endl;
	//	// direct to Virtual Voice Pool
	//}
}

void RealVoicePool::returnRealVoice(RealVoice* object)
{
	object->clearBuffer();
	object->setIsActive(false);
	setAllVoicesActive(false);
	//realVoices.push_back(object);
}

std::vector<RealVoice*> RealVoicePool::getRealVoicePool()
{
	return realVoices;
}

void RealVoicePool::setAllVoicesActive(bool aVActive)
{
	allVoicesActive = aVActive;
}

bool RealVoicePool::getAllVoicesActive()
{
	return allVoicesActive;
}
