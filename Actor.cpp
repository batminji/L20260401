#include "stdafx.h"
#include "Actor.h"
#include "Engine.h"

AActor::AActor(int InX, int InY, int InSize, int InColorR, int InColorG, int InColorB)
	:X(InX), Y(InY), Size(InSize), ColorR(InColorR), ColorG(InColorG), ColorB(InColorB)
{
}

AActor::~AActor()
{
}

void AActor::Tick()
{
	
}

void AActor::Render()
{
	GEngine->Render(X, Y, ColorR, ColorG, ColorB, 50);
}
