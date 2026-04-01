#pragma once
class UWorld;

class UEngine
{
protected:
	UEngine();
public:
	virtual ~UEngine();

	inline static UEngine* GetInstance()
	{
		static UEngine* Instance = new UEngine();
		return Instance;
	}

	void Init();
	void Term();
	void Run();

	void Render(int InX, int InY, int InColorR, int InColorG, int InColorB, int Size);
	inline const SDL_Event& GetEvent()
	{
		return Event;
	}

	inline const Uint8* GetState()
	{
		return State;
	}

protected:
	bool bIsRunning;

	void Input();
	void Tick();
	void Render();

	UWorld* World;
	SDL_Window* Window;
	SDL_Renderer* Renderer;
	SDL_Event Event;
	const Uint8* State;
};

#define GEngine		UEngine::GetInstance()