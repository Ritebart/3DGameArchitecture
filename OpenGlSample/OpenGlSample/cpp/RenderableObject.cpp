#include "../h/RenderableObject.h"

RenderableObject::~RenderableObject()
{

}

void RenderableObject::SetMVP(glm::mat4 m, glm::mat4 v, glm::mat4 p)
{
	MVP = m * v * p;
}
void RenderableObject::SetPosition(glm::mat4 m)
{
	Model = m;
}

glm::mat4 RenderableObject::GetMVP() const
{
	return MVP;
}

std::vector<glm::vec3> RenderableObject::GetVertex() const
{
	return vertex;
}
std::vector<glm::vec2> RenderableObject::GetUV() const
{
	return uv;
}
std::vector<glm::vec3> RenderableObject::GetNormal() const
{
	return normal;
}

glm::mat4 RenderableObject::GetPosition() const
{
	return Model;
}

void RenderableObject::Clean()
{

}