#include "../h/Cube.h"
#include "../h/FileManager.h"

Cube::Cube(const char* filepath, float x, float y, float z)
	: RenderableObject(filepath, x, y, z)
{

}
Cube::~Cube()
{

}

void Cube::Clean()
{

}

void Cube::Init()
{
	std::cout << "Cube Init" << std::endl;
}
void Cube::Update()
{
	std::cout << "Cube update" << std::endl;
	position = glm::translate(position, glm::vec3(-1.0f, 0, 0));
	SetPosition(position);
}

void Cube::RenDeltaTime()
{
	//float currentframe = glfwGetTime();
	//DeltaTime = currentframe - lastFrame;
	//lastFrame = currentframe;
}