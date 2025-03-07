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
	checkIfVoiceActive();
	if (!realVoices[realVoicePoolIndex]->getIsActive())
	{
		realVoices[realVoicePoolIndex]->setIsActive(true);
		std::clog << "RealVoicePool -> Setting a Real Voice to: Active" << std::endl;
		return realVoices[realVoicePoolIndex];
	}
	return nullptr;
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

void RealVoicePool::checkIfVoiceActive()
{
	for(int i = 0; i < realVoices.size(); i++)
	{
		//std::clog << "RealVoicePool -> getRealVoice() -> realVoices.size(): " << realVoices.size()<< std::endl;
		if (!realVoices[i]->getIsActive())
		{
			realVoicePoolIndex = i;
			break;
		}
		else if (i+1 == realVoices.size() && realVoices[i]->getIsActive())
		{
			//realVoices[i]->setPlayHead(0);
			setAllVoicesActive(true);
			std::clog << "RealVoicePool -> All \"Real Voices\" are active." << std::endl;
		}
	}	
}

void RealVoicePool::setAllVoicesActive(bool aVActive)
{
	allVoicesActive = aVActive;
}

bool RealVoicePool::getAllVoicesActive()
{
	for (auto voice : realVoices)
	{
		if (!voice->getIsActive())
			return false;
	}
	return true;
	//return allVoicesActive;
}
