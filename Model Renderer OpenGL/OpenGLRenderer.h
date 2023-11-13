#pragma once


class OpenGLRenderer
{
public:
	static int Init();
	static void Destroy();
private:
	static SDL_GLContext context;
};

