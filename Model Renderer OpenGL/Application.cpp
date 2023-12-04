#include "mpch.h"
#include "Application.h"
#include "SDLRenderer.h"
#include "OpenGLRenderer.h"
#include "ShaderRenderer.h"
#include "Events/MouseEvents.h"
#include "Events/KeyboardEvents.h"

void Application::StartAndRun()
{
	SDLRenderer::Init();									// Create SDL Video
	if (SDLRenderer::CreateWindow() == -1) return;		    // Create SDL Window

	OpenGLRenderer::Init();									// Create OpenGL context based on the window

	glEnable(GL_DEPTH_TEST);

	ShaderRenderer::CreateVertexShader();					// Create a vertex shader
	ShaderRenderer::CreateFragmentShader();					// Create a fragment shader
	ShaderRenderer::CreateProgram();						// Links the vertex and fragment shaders to the program

	Model jorge("Assets/Objs/LivroAzul/livroazul.obj", true);
	Model jorge2("Assets/Objs/Street/Street.obj", false);

	jorge.Translate(glm::vec3(0.0f, 10.0f, 0.0f));

	m_Models.push_back(jorge);
	m_Models.push_back(jorge2);

	m_Camera = new Camera(90.0f, (1280.0f / 720.0f), 0.1f, 100.0f, true);

	Run();
}

void Application::Run()
{
	while (!m_Quit)
	{
		float now = SDL_GetTicks();
		float deltaTime = (now - m_LastFrame) / 1000.0f;
		m_LastFrame = now;

		m_Camera->UpdateMatrices();

		while (SDL_PollEvent(&m_Event) != 0)
		{
			if (m_Event.type == SDL_QUIT)
				m_Quit = true;

			MouseEvents::ProcessMouseInput(m_Event, m_Camera);
		}

		KeyboardEvents::ProcessKeyboard(m_Camera, deltaTime);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		ShaderRenderer::Bind();

		for (Model model : m_Models)
		{
			model.Draw();
		}
		

		SDL_GL_SwapWindow(SDLRenderer::GetWindow());
	}

	OpenGLRenderer::Destroy();
	SDLRenderer::Destroy();
}
