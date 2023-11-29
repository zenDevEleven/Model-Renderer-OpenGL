#pragma once
#include <SDL.h>
#include "Camera.h"


class MouseEvents {
public:
	static inline void ProcessMouseInput(SDL_Event ev, Camera* camera) {
		if (ev.type == SDL_MOUSEMOTION) {
			static int xpos, ypos;

			xpos += ev.motion.xrel;
			ypos += ev.motion.yrel;

			static bool firstMouse = true;
			if (firstMouse) {
				firstMouse = false;
				lastX = xpos;
				lastY = ypos;
			}

			float xoffset = xpos - lastX;
			float yoffset = lastY - ypos;
			lastX = xpos;
			lastY = ypos;

			float sensitivity = 0.05f;
			xoffset *= sensitivity;
			yoffset *= sensitivity;

			camera->UpdateRotation(xoffset, yoffset);
		}

		if (ev.type == SDL_MOUSEWHEEL)
		{
			camera->UpdateFOV(ev.wheel.y);
		}
	}
private:
	static float lastX;
	static float lastY;
};

float MouseEvents::lastX = 0.0f;
float MouseEvents::lastY = 0.0f;
