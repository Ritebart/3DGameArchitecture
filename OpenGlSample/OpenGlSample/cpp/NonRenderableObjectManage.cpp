#include "../h/NonRenderableObjectManage.h"
#include "../h/Camera.h"

NonRenderableObjectManage::NonRenderableObjectManage()
{
	NROvecter = new std::vector< NonRenderableObject*>();
}
NonRenderableObjectManage::~NonRenderableObjectManage()
{
	//for (
	//	std::vector<NonRenderableObject*>::const_iterator it
	//	= NROvecter->begin();
	//	it != NROvecter->end();
	//	++it
	//	)
	//{
	//	delete (*it);
	//}
	//NROvecter->clear();

	//delete NROvecter;
}

void NonRenderableObjectManage::NROadd(NonRenderableObject* nrenobj)
{
	NROvecter->push_back(nrenobj);
}

void NonRenderableObjectManage::MakeCamera(std::string name,
	glm::mat4 projection, glm::mat4 view,
	float x, float y, float z)
{
	Camera* camera = new Camera(name, projection, view
		, x, y, z);
	NROadd(camera);

	delete camera;
}