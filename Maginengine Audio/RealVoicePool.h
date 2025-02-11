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

class RealVoicePool
{
private:
	std::list<RealVoice*> realVoices;
	int maxRealVoices;
	static RealVoicePool* instance;
	RealVoicePool();

public:
	static RealVoicePool* getInstance();
	RealVoice* getResource();
	void returnResource(RealVoice* object);
	std::list<RealVoice*> getRealVoicePoolSize();
};

