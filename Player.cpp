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

		if (State[SDL_SCANCODE_UP] || State[SDL_SCANCODE_W])
		{
			Y--;
		}
		if (State[SDL_SCANCODE_DOWN] || State[SDL_SCANCODE_S])
		{
			Y++;
		}
		if (State[SDL_SCANCODE_LEFT] || State[SDL_SCANCODE_A])
		{
			X--;
		}
		if (State[SDL_SCANCODE_RIGHT] || State[SDL_SCANCODE_D])
		{
			X++;
		}
	}
}
