#include "../h/NonRenderableObject.h"

void NonRenderableObject::SetMVP(glm::mat4 m, glm::mat4 v, glm::mat4 p)
{
	MVP = m * v * p;
}

glm::mat4 NonRenderableObject::GetMVP()
{
	return MVP;
}

void NonRenderableObject::Clean()
{

}