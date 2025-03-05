// Base class interface for Composite Design Pattern
// This pattern is responsible for the Engine hierarchy

#pragma once

// Headers
//#include "RealVoice.h"
#include "RealVoicePool.h"
#include "VirtualVoicePool.h"

// libraries
#include <string>
#include <vector>

class Component
{
protected:
	Component* _parent;
	// not sure this is the right thing to do. delete if causing issues
	std::vector<float> audioData;
	bool isLooping = false;

	// Object Pool Setup
	RealVoicePool* realVoicePool = RealVoicePool::getInstance();
	VirtualVoicePool* virtualVoicePool = VirtualVoicePool::getInstance();

public:
	virtual ~Component(){};
	void setParent(Component* parent){this->_parent = parent;}
	Component* getParent() const {return this->_parent;}

	// composite pattern structure
	virtual void Add(Component* component){}
	virtual void Remove(Component* component){}
	virtual bool IsComposite() const {return false;}

	// voice setup
	virtual void assignAssetToTrack(std::vector<float> asset){}

	virtual void assignTrackToRealVoice(){}
	virtual void assignTrackToVirtualVoice(){}

	virtual void removeTrackFromRealVoice(){}
	virtual void removeTrackFromVirtualVoice(){}

	virtual std::vector<float> getAudioData(){return audioData;}

	// transport controls
	virtual void play() = 0;
	virtual void stop() = 0;

	virtual std::string Operation() const = 0;

	virtual void setVolume(float vol) = 0;

	virtual void setLoop(bool loop){isLooping = loop;}
	virtual bool getLoop(){return isLooping;}

	virtual void adjustVolume() = 0;
};