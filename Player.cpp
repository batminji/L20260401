#include "stdafx.h"
#include "Player.h"
#include "Engine.h"

APlayer::APlayer(int InX, int InY, int InSize, int InColorR, int InColorG, int InColorB)
{
	X = InX;
	Y = InY;
	ColorR = InColorR;
	ColorG = InColorG;
	ColorB = InColorB;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	__super::Tick();

	SDL_Event Event = GEngine->GetEvent();

	if (Event.type == SDL_KEYDOWN)
	{
		SDL_Keycode KeyCode = Event.key.keysym.sym;
		if (KeyCode == SDLK_w)
		{
			Y--;
		}
		if (KeyCode == SDLK_s)
		{
			Y++;
		}
		if (KeyCode == SDLK_a)
		{
			X--;
		}
		if (KeyCode == SDLK_d)
		{
			X++;
		}
	}
}
