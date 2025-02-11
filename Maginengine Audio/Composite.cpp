#include "Composite.h"

void Composite::Add(Component* component)
{
	this->_children.push_back(component);
}

void Composite::Remove(Component* component)
{
	_children.remove(component);
	component->setParent(nullptr);
}

bool Composite::IsComposite() const
{
	return true;
}

std::string Composite::Operation() const
{
	std::string result;
	for (const Component *c : _children)
	{
		if (c == _children.back())
			result += c->Operation();
		else
			result += c->Operation() + " + ";
	}
	return "Event (" + result + ")";
}
