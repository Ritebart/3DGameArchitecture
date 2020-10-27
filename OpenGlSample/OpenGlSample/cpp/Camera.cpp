#include "../h/Camera.h"

Camera::Camera()
{

}

Camera::~Camera()
{

}

void Camera::Clean()
{

}

void Camera::Update()
{

}

void Camera::RenDeltaTime()
{
	float currentframe = glfwGetTime();
	DeltaTime = currentframe - lastFrame;
	lastFrame = currentframe;
}