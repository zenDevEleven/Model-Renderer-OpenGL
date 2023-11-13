#include "mpch.h"
#include "SDLRenderer.h"
#include "OpenGLRenderer.h"


SDL_GLContext OpenGLRenderer::context;


int OpenGLRenderer::Init()
{
	context = SDL_GL_CreateContext(SDLRenderer::GetWindow());

	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		SDL_Quit();
		return -2;
	}

	std::cout << "GLAD Initialized!" << std::endl;
}

void OpenGLRenderer::Destroy()
{
	SDL_GL_DeleteContext(context);
}
