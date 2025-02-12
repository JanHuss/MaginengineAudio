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

