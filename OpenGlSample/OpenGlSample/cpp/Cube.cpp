#include "../h/Cube.h"
#include "../h/FileManager.h"

Cube::Cube(const char* filepath)
{
	bool load = FileManager::Instance()->LoadOBJ(filepath, vertex, uv, normal);

	FileManager::Instance()->indexVBO(vertex, uv, normal,
		indices, indexed_vertices, indexed_uvs,
		indexed_normals);
}
Cube::~Cube()
{

}

void Cube::Clean()
{

}

void Cube::Update()
{

}

void Cube::RenDeltaTime()
{
	float currentframe = glfwGetTime();
	DeltaTime = currentframe - lastFrame;
	lastFrame = currentframe;
}