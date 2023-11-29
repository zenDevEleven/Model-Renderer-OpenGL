#pragma once

enum class AXIS {
	FORWARD,
	BACKWARDS,
	UPWARDS,
	DOWNWARDS,
	RIGHT,
	LEFT
};

class Camera
{
public:
	Camera();
	Camera(float FOV, float AspectRatio, float nearPlane, float farPlane, bool InfiniteMosueCursor);

	virtual ~Camera() = default;

	glm::vec3 GetCameraPosition();
	glm::mat4 GetCameraViewMatrix();
	glm::mat4 GetCameraProjectionMatrix();
	void UpdateMatrices();
	float GetCameraSpeed();
	void UpdatePosition(AXIS, float);
	void UpdatePosition(glm::vec3 newPosition);
	void UpdateRotation(float, float);
	void UpdateFOV(float);

private:
	glm::vec3 Position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 forwardAxis = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 upAxis = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::mat4 CameraViewMatrix = glm::mat4(1.0f);
	glm::mat4 projectionMatrix = glm::mat4(1.0f);

	float FOV = 0; 
	float aspectRadio = 1.7f;
	float nearPlane = 0.1f;
	float farPlane = 100.0f;
	float cameraSpeed = 3.0f;

	float pitch = 0.0f;
	float yaw = -90.0f;

};

