// This Object Pool design pattern contains the handling of "VirtualVoice" 
// objects. There is a set amount of "VirtualVoices" within this pool,
// however, more "Virtual Voice" objects can be added if the pool runs dry.

#pragma once

// Headers
#include "VirtualVoice.h"

// Libraries
#include <iostream>
#include <list>

class VirtualVoicePool
{
private:
	std::vector<VirtualVoice*> virtualVoices;
	int virtualVoicesCurrent;
	static VirtualVoicePool* instance;
	bool allVoicesActive;
	int virtualVoicePoolIndex;

	// !!! Keep Private! is singleton !!!
	VirtualVoicePool();

public:
	static VirtualVoicePool* getInstance();
	VirtualVoice* getVirtualVoice();
	void returnVirtualVoice(VirtualVoice* object);
	std::vector<VirtualVoice*> getVirtualVoicePool();
	void setAllVoicesActive(bool aVActive);
	bool getAllVoicesActive();
};

