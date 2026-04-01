#include "stdafx.h"
#include "Engine.h"
#include "World.h"

UEngine::UEngine()
{
	Init();
}

UEngine::~UEngine()
{
	Term();
}

void UEngine::Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	Window = SDL_CreateWindow("L20260401", WINDOWX, WINDOWY, WINDOWW, WINDOWH, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(Window, -1, 0);
	State = SDL_GetKeyboardState(NULL);

	bIsRunning = true;
	World = new UWorld();
}

void UEngine::Term()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	SDL_Quit();

	if (World)
	{
		delete World;
	}
	World = nullptr;
}

void UEngine::Run()
{
	while (bIsRunning)
	{
		SDL_PollEvent(&Event);

		Input();
		Tick();
		Render();
	}
}

void UEngine::Render(int InX, int InY, int InColorR, int InColorG, int InColorB, int Size)
{
	SDL_SetRenderDrawColor(Renderer, InColorR, InColorG, InColorB, 255);
	SDL_Rect Rect = { InX * Size, InY * Size, Size, Size };
	SDL_RenderFillRect(Renderer, &Rect);
}

void UEngine::Input()
{
	
	//World->Input();
}

void UEngine::Tick()
{
	if (Event.type == SDL_KEYDOWN)
	{
		SDL_Keycode KeyCode = Event.key.keysym.sym;
		if (KeyCode == SDL_QUIT)
		{
			bIsRunning = false;
		}
		if (KeyCode == SDLK_ESCAPE)
		{
			bIsRunning = false;
		}
	}
	World->Tick();
}

void UEngine::Render()
{
	SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
	SDL_RenderClear(Renderer);

	World->Render();

	SDL_RenderPresent(Renderer);
}
