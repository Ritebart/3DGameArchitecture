#include "../h/RenderableObject.h"

//RenderableObject::RenderableObject(const char* filepath)
//{
//	bool load = FileManager::Instance()->LoadOBJ(filepath, vertex, uv, normal);
//
//	FileManager::Instance()->indexVBO(vertex, uv, normal,
//		indices, indexed_vertices, indexed_uvs,
//		indexed_normals);
//}


void RenderableObject::SetMVP(glm::mat4 m, glm::mat4 v, glm::mat4 p)
{
	MVP = m * v * p;
}
void RenderableObject::SetP(glm::mat4 mvp, glm::mat4 p)
{
	MVP = mvp * p;
}


glm::mat4 RenderableObject::GetMVP()
{
	return MVP;
}

std::vector<glm::vec3> RenderableObject::GetVertex()
{
	return vertex;
}
std::vector<glm::vec2> RenderableObject::GetUV()
{
	return uv;
}
std::vector<glm::vec3> RenderableObject::GetNormal()
{
	return normal;
}