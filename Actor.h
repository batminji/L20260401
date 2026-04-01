#pragma once
class AActor
{
public:
	AActor(int InX = 0, int InY = 0, int InSize = 0, int InColorR = 255, int InColorG = 255, int InColorB = 255);
	virtual ~AActor();

	virtual void Input();
	virtual void Tick();
	virtual void Render();

protected:
	int X;
	int Y;
	int Size;
	int ColorR;
	int ColorG;
	int ColorB;
};

