#pragma once

// libraries
#include <string>

class Component
{
protected:
	Component* _parent;

public:
	virtual ~Component(){};
	void setParent(Component* parent){this->_parent = parent;}
	Component* getParent() const {return this->_parent;}

	virtual void Add(Component* component){}
	virtual void Remove(Component* component){}
	virtual bool IsComposite() const {return false;}

	virtual std::string Operation() const = 0;
};