#pragma once

// libraries
#include <string>

class Component
{
protected:
	Component* parentComp;

public:
	virtual ~Component(){};
	void setParent(Component* parent){this->parentComp = parent;}
	Component* getParent() const {return this->parentComp;}

	virtual void Add(Component* component){}
	virtual void Remove(Component* component){}
	virtual bool isComposite() const {return false;}

	virtual std::string Operation() const = 0;
};