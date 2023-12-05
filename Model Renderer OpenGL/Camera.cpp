#include "mpch.h"
#include "Camera.h"
#include "ShaderRenderer.h"

Camera::Camera(float _FOV = 0.0f, float _aspectRadio = 0.0f, float _nearPlane = 0.0f, float _farPlane = 0.0f, bool InfiniteMouseCursor = false) {
	MaxFOV = _FOV;
	FOV = MaxFOV;
	aspectRadio = _aspectRadio;
	nearPlane = _nearPlane;
	farPlane = _farPlane;

	projectionMatrix = glm::perspective(glm::radians(FOV), aspectRadio, nearPlane, farPlane);
	CameraViewMatrix = glm::lookAt(Position, Position + forwardAxis, upAxis);

	if (InfiniteMouseCursor) {
		SDL_ShowCursor(SDL_FALSE);
		SDL_CaptureMouse(SDL_TRUE);
		SDL_SetRelativeMouseMode(SDL_TRUE);
	}

	viewTrans = glGetUniformLocation(ShaderRenderer::GetShaderProgram(), "view");
	projectionTrans = glGetUniformLocation(ShaderRenderer::GetShaderProgram(), "projection");

	UpdateRotation(0.0f, 0.0f);
}

glm::vec3 Camera::GetCameraPosition()
{
	return Position;
}

glm::mat4 Camera::GetCameraViewMatrix()
{
	return CameraViewMatrix;
}

glm::mat4 Camera::GetCameraProjectionMatrix()
{
	return projectionMatrix;
}

void Camera::UpdateMatrices()
{

	glUniformMatrix4fv(viewTrans, 1, GL_FALSE, glm::value_ptr(CameraViewMatrix));
	glUniformMatrix4fv(projectionTrans, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
}

float Camera::GetCameraSpeed()
{
	return cameraSpeed;
}

void Camera::UpdatePosition(AXIS axis, float deltaTime) {
	glm::vec3 rightAxis = glm::normalize(glm::cross(forwardAxis, upAxis));

	switch (axis)
	{
	case AXIS::FORWARD:
		Position += glm::normalize(glm::vec3(forwardAxis.x, 0.0f, forwardAxis.z)) * (cameraSpeed * deltaTime);
		break;
	case AXIS::BACKWARDS:
		Position -= glm::normalize(glm::vec3(forwardAxis.x, 0.0f, forwardAxis.z)) * (cameraSpeed * deltaTime);
		break;
	case AXIS::RIGHT:
		Position += glm::normalize(glm::vec3(rightAxis.x, 0.0f, rightAxis.z)) * (cameraSpeed * deltaTime);
		break;
	case AXIS::LEFT:
		Position -= glm::normalize(glm::vec3(rightAxis.x, 0.0f, rightAxis.z)) * (cameraSpeed * deltaTime);
		break;
	default:
		break;
	}

	CameraViewMatrix = glm::lookAt(Position, Position + forwardAxis, upAxis);

}

void Camera::UpdatePosition(glm::vec3 newPos) {

	Position = newPos;
	CameraViewMatrix = glm::lookAt(Position, Position + forwardAxis, upAxis);
}

void Camera::UpdateRotation(float xOffset, float yOffset) {

	pitch += yOffset;
	yaw += xOffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 front;

	front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
	front.y = sin(glm::radians(pitch));
	front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));

	glm::vec3 rightAxis = glm::normalize(glm::cross(forwardAxis, WorldupAxis));
	upAxis = glm::normalize(glm::cross(rightAxis, forwardAxis));

	forwardAxis = glm::normalize(front);
	CameraViewMatrix = glm::lookAt(Position, Position + forwardAxis, upAxis);


}


void Camera::UpdateFOV(float newFov) {

	if (FOV >= 1.0f && FOV <= MaxFOV)
		FOV -= newFov;
	if (FOV <= 1.0f)
		FOV = 1.0f;
	if (FOV >= MaxFOV)
		FOV = MaxFOV;

	projectionMatrix = glm::perspective(glm::radians(FOV), aspectRadio, nearPlane, farPlane);
}



Camera::Camera() {

}