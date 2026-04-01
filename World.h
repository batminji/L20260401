#pragma once
class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void Input();
	void Tick();
	void Render();

protected:
	std::vector<AActor*> Actors;
};

