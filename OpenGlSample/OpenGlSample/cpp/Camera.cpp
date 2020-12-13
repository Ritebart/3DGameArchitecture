#include "../h/Camera.h"

Camera::Camera()
{

}
Camera::Camera(
	std::string name, glm::mat4 projection, glm::mat4 view,
	float x, float y, float z) 
	: NonRenderableObject(
    name, projection, view,
	x, y, z)
{

}

Camera::~Camera()
{

}

void Camera::Init()
{
	//std::cout << "카메라 실행" << std::endl;
}
void Camera::Clean()
{

}

void Camera::Update()
{

}

void Camera::RenDeltaTime()
{
	//float currentframe = glfwGetTime();
	//DeltaTime = currentframe - lastFrame;
	//lastFrame = currentframe;
}