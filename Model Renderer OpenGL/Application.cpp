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

<<<<<<< HEAD
	Model livro("Assets/Objs/LivroAzul/livroazul.obj", true);
	Model rua("Assets/Objs/Street/Street.obj", false);

<<<<<<< HEAD

	livro.Translate(glm::vec3(0.0f, 0.02f, -5.0f));
	livro.SetScale(glm::vec3(0.3f, 0.3f, 0.3f));
	livro.SetRotation(glm::vec3(0.0f, 1.0f, 0.0f), -65.0f);

	m_Models.push_back(livro);
	m_Models.push_back(rua);
=======
	jorge.Translate(glm::vec3(0.0f, 10.0f, 0.0f));
=======
	Model jorge("Assets/Objs/Backpack/backpack.obj", true);
	Model jorge3("Assets/Objs/Street/Street.obj", false);
>>>>>>> parent of cfae0fc (g)

	jorge3.SetScale(glm::vec3(0.2f, 0.2f, 0.2f));

	m_Models.push_back(jorge);
<<<<<<< HEAD
	m_Models.push_back(jorge2);
>>>>>>> parent of 3c0828c (s)
=======
	m_Models.push_back(jorge3);
>>>>>>> parent of cfae0fc (g)

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

<<<<<<< HEAD

=======
>>>>>>> parent of cfae0fc (g)
		while (SDL_PollEvent(&m_Event) != 0)
		{
			if (m_Event.type == SDL_QUIT)
				m_Quit = true;

			MouseEvents::ProcessMouseInput(m_Event, m_Camera);
		}
		m_Camera->UpdateMatrices();


		KeyboardEvents::ProcessKeyboard(m_Camera, deltaTime);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		ShaderRenderer::Bind();

		for (Model model : m_Models)
		{
			model.Draw();
		}
<<<<<<< HEAD
	
=======
		
		m_Camera->UpdateMatrices();
>>>>>>> parent of cfae0fc (g)

		SDL_GL_SwapWindow(SDLRenderer::GetWindow());
	}

	OpenGLRenderer::Destroy();
	SDLRenderer::Destroy();
}
