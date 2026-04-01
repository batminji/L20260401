#include "stdafx.h"
#include "World.h"
#include "Actor.h"
#include "Player.h"

UWorld::UWorld()
{
	AActor* NewActor = new APlayer;
	Actors.push_back(NewActor);
}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}
	Actors.clear();
}

void UWorld::Input()
{
	for (auto Actor : Actors)
	{
		Actor->Input();
	}
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}