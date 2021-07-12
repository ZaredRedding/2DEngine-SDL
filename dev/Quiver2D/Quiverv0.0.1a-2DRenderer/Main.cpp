#include "Game.h"
#include <iostream>

int main(int argc, char** argv)
{
	std::cout << "What's good? Welcome to Quiver." << std::endl;
	
	Game instance;

	//Initialize Game Instance
	bool initSuccess = instance.Initialize();

	if (initSuccess)
	{
		instance.RunLoop();
	}

	instance.Shutdown();

	return EXIT_SUCCESS;
}
