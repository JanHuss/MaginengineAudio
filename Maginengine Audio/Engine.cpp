#include "Engine.h"

Engine::Engine()
{
	init();
}

Engine::~Engine()
{
	std::cout << "!!! *********************** !!!" << std::endl;
	std::cout << "!!! Engine -> Shutting down !!!" << std::endl;
	std::cout << "!!! *********************** !!!" << std::endl;
}

void Engine::init()
{
	//std::cout << "Engine -> init() called()" << std::endl;
}

void Engine::run()
{
	//std::cout << "Engine -> run() called()" << std::endl;
}
