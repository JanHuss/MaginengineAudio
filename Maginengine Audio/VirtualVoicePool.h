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
	std::list<VirtualVoice*> virtualVoices;
	int virtualVoicesCurrent;
	static VirtualVoicePool* instance;
	VirtualVoicePool();

public:
	static VirtualVoicePool* getInstance();
	VirtualVoice* getVirtualVoice();
	void returnVirtualVoice(VirtualVoice* object);
	std::list<VirtualVoice*> getVirtualVoicePoolSize();
};

