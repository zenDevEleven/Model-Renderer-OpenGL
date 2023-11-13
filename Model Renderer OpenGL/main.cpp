#include "mpch.h"

#include "SDLRenderer.h"
#include "OpenGLRenderer.h"


int main(int agrc, char** agrv) {
	SDLRenderer::Init();
	SDLRenderer::CreateWindow();

	OpenGLRenderer::Init();

	while (true) {

	}

	OpenGLRenderer::Destroy();
	SDLRenderer::Destroy();
	return 0;
}