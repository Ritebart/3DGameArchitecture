#include "../h/Human.h"
#include "../h/FileManager.h"

Human::Human(const char* filepath)
{
	bool load = FileManager::Instance()->LoadOBJ(filepath, vertex, uv, normal);

	FileManager::Instance()->indexVBO(vertex, uv, normal,
		indices, indexed_vertices, indexed_uvs,
		indexed_normals);
}
Human::~Human()
{

}
