#pragma once
#include "Buffer.h"
#include "Model.h"
#include "Camera.h"


class Application
{
public:
	Application() {}

	void StartAndRun();
	void Run();
private:
	Buffer* m_Buffer;
	Camera* m_Camera;
	float m_LastFrame = 0;
	bool m_Quit = false;
	SDL_Event m_Event;

	std::vector<Model> m_Models;
};

