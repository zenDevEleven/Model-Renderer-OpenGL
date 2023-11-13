#include "mpch.h"
#include "SDLRenderer.h"

SDL_Window* SDLRenderer::window;
SDL_WindowFlags SDLRenderer::windowFlags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);



void SDLRenderer::Init()
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
}

int SDLRenderer::CreateWindow()
{
	window = SDL_CreateWindow("EvenOut model renderer!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, windowFlags);

	if (window == nullptr)
	{
		std::cout << "Failed to create SDL Window" << std::endl;
		SDL_Quit();
		return -1;
	}

	std::cout << "SDL Window Initialized!" << std::endl;

	return 0;
}

void SDLRenderer::Destroy()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}
