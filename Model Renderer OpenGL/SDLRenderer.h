#pragma once

class SDLRenderer {
	public:
		static void Init();
		static int CreateWindow();
		static void Destroy();

		static inline SDL_Window* GetWindow() { return window; }

	private:
		static SDL_WindowFlags windowFlags;
		static SDL_Window* window;

};