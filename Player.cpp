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
		const Uint8* State = GEngine->GetState();

		if (State[SDL_SCANCODE_UP])
		{
			Y--;
		}
		if (State[SDL_SCANCODE_DOWN])
		{
			Y++;
		}
		if (State[SDL_SCANCODE_LEFT])
		{
			X--;
		}
		if (State[SDL_SCANCODE_RIGHT])
		{
			X++;
		}
	}
}
