#pragma once
#include "Actor.h"
class APlayer : public AActor
{
public:
	APlayer(int InX = 0, int InY = 0, int InSize = 50, int InColorR = 255, int InColorG = 0, int InColorB = 0);
	virtual ~APlayer();

	virtual void Tick() override;
};

