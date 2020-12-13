#include "../h/NonRenderableObject.h"
#include "../h/MakeableObjectFucCall.h"
#include "../h/FileManager.h"
#include "../h/Renderer.h"

NonRenderableObject::NonRenderableObject()
{
	//MakeableObjectFucCall::Instance()->AddUpdateObject(this);
	//MakeableObjectFucCall::Instance()->AddCleanObject(this);
	//MakeableObjectFucCall::Instance()->AddInitObject(this);
}
NonRenderableObject::NonRenderableObject(
	std::string name, glm::mat4 projection, glm::mat4 view, 
	float x, float y, float z)
{
	MakeableObjectFucCall::Instance()->AddUpdateObject(this);
	MakeableObjectFucCall::Instance()->AddCleanObject(this);
	MakeableObjectFucCall::Instance()->AddInitObject(this);
		FileManager::Instance()->indexVBO(vertex, uv, normal,
			indices, indexed_vertices, indexed_uvs,
			indexed_normals);

		glm::mat4 move = glm::mat4(1.0f);
		move = glm::translate(move, glm::vec3(x, y, z));

		SetPosition(move);
		SetProjection(projection);
		SetView(view);
		Renderer::Instance()->AddNonrenderObject(name, *this);
}

NonRenderableObject::~NonRenderableObject()
{

}


void NonRenderableObject::Init()
{

}
void NonRenderableObject::Update()
{

}
void NonRenderableObject::RenDeltaTime()
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