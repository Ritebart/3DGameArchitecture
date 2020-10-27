#include "../h/NonRenderableObject.h"

NonRenderableObject::~NonRenderableObject()
{

}

void NonRenderableObject::SetProjection(glm::mat4 p)
{
	Projection = p;
}
void NonRenderableObject::SetView(glm::mat4 v)
{
	View = v;
}

glm::mat4 NonRenderableObject::GetProjection() const
{
	return Projection;
}
glm::mat4 NonRenderableObject::GetView() const
{
	return View;
}

void NonRenderableObject::SetMVP(glm::mat4 m, glm::mat4 v, glm::mat4 p)
{

	MVP = m * v * p;
}

void NonRenderableObject::SetPosition(glm::mat4 m)
{
	Model = m;
}

glm::mat4 NonRenderableObject::GetMVP() const
{
	return MVP;
}

void NonRenderableObject::Clean()
{

}