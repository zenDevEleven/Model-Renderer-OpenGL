#pragma once
#pragma once
#include <SDL.h>
#include "../Camera.h"

class KeyboardEvents {
public:
	static inline void ProcessKeyboard(Camera* camera, float deltaTime) {
		const Uint8* keyState = SDL_GetKeyboardState(NULL);

		if (keyState[SDL_SCANCODE_D]) {
			camera->UpdatePosition(AXIS::RIGHT, deltaTime);
		}
		else if (keyState[SDL_SCANCODE_A]) {
			camera->UpdatePosition(AXIS::LEFT, deltaTime);
		}
		else if (keyState[SDL_SCANCODE_W]) {
			camera->UpdatePosition(AXIS::FORWARD, deltaTime);
		}
		else if (keyState[SDL_SCANCODE_S]) {
			camera->UpdatePosition(AXIS::BACKWARDS, deltaTime);
		}
		else if (keyState[SDL_SCANCODE_E]) {
			camera->UpdatePosition(AXIS::DOWNWARDS, deltaTime);
		}
		else if (keyState[SDL_SCANCODE_Q]) {
			camera->UpdatePosition(AXIS::UPWARDS, deltaTime);
		}
	}

};
