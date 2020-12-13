#include "../h/Human.h"
#include "../h/FileManager.h"

Human::Human(const char* filepath, float x, float y, float z)
	: RenderableObject(filepath, x, y, z)
{

}
Human::~Human()
{

}

void Human::Clean()
{

}

void Human::Update()
{

}

void Human::RenDeltaTime()
{
	//float currentframe = glfwGetTime();
	//DeltaTime = currentframe - lastFrame;
	//lastFrame = currentframe;
}