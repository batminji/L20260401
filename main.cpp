#include "stdafx.h"
#include "Engine.h"

int SDL_main(int argc, char* argv[])
{
	GEngine;
	
	GEngine->Run();

	delete GEngine;

	return 0;
}