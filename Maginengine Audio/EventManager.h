// Initialises and manages the hierarchial structure of the engine
// The structure is making use of the Composite Design pattern.
// EventManager is considered the "Client" and handles the components.

#pragma once

// libraries
#include <iostream>

class EventManager
{
public:
	EventManager();
	~EventManager();

	void init();
};

