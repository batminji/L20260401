#include "stdafx.h"

int SDL_main(int argc, char* argv[])
{
	bool bIsRunning = true;

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* Window = SDL_CreateWindow("L20260401", WINDOWX, WINDOWY, WINDOWW, WINDOWH, SDL_WINDOW_SHOWN);
	SDL_Renderer* Renderer = SDL_CreateRenderer(Window, -1, 0);
	SDL_Event Event;

	// Player
	int PlayerX = 0;
	int PlayerY = 0;
	int PlayerSize = 50;

	while (bIsRunning)
	{
		SDL_PollEvent(&Event);

		if (Event.type == SDL_KEYDOWN)
		{
			switch (Event.key.keysym.sym)
			{
			case SDLK_w:
				PlayerY--;
				break;
			case SDLK_s:
				PlayerY++;
				break;
			case SDLK_a:
				PlayerX--;
				break;
			case SDLK_d:
				PlayerX++;
				break;
			default:
				break;
			}
		}

		SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
		SDL_RenderClear(Renderer);

		// Draw Player
		SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255); // Red
		SDL_Rect Rect = { PlayerX * PlayerSize, PlayerY * PlayerSize, PlayerSize, PlayerSize };
		SDL_RenderFillRect(Renderer, &Rect);

		SDL_RenderPresent(Renderer);
	}
	
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	SDL_Quit();

	return 0;
}