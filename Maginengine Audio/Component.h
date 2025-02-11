#pragma once

// libraries
#include <string>
#include <vector>

class Component
{
protected:
	Component* _parent;
	// not sure this is the right thing to do. delete if causing issues
	std::vector<float> audioData;

public:
	virtual ~Component(){};
	void setParent(Component* parent){this->_parent = parent;}
	Component* getParent() const {return this->_parent;}

	// composite pattern structure
	virtual void Add(Component* component){}
	virtual void Remove(Component* component){}
	virtual bool IsComposite() const {return false;}

	// transport controls
	virtual void assignAssetToTrack(std::vector<float> asset){}
	virtual std::vector<float> getAudioData(){return audioData;}
	virtual void play() const = 0;
	virtual void stop() const = 0;

	virtual std::string Operation() const = 0;
};