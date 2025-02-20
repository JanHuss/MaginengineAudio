// This Object Pool design pattern contains the handling of "RealVoice" 
// objects. There is a set amount of "RealVoices" within this pool and
// there cannot be any more when emptied.
// Instead, when the pool is emptied, direct over to a "VirtualVoice" 
// from the "VirtualVoicePool"

#pragma once

// Headers
#include "RealVoice.h"

// Libraries
#include <iostream>
#include <list>
#include <vector>

class RealVoicePool
{
private:
	std::vector<RealVoice*> realVoices;
	int maxRealVoices;
	static RealVoicePool* instance;
	bool allVoicesActive;
	int realVoicePoolIndex;

	// !!! Keep Private! is singleton !!!
	RealVoicePool();

public:
	static RealVoicePool* getInstance();
	RealVoice* getRealVoice();
	void returnRealVoice(RealVoice* object);
	std::vector<RealVoice*> getRealVoicePool();
	void checkIfVoiceActive();
	void setAllVoicesActive(bool aVActive);
	bool getAllVoicesActive();

};

