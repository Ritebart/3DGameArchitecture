#include "../h/RenderableObjectManage.h"
#include "../h/Cube.h"
#include "../h/Human.h"

RenderableObjectManage::RenderableObjectManage()
{
	ROvecter = new std::vector<RenderableObject*>();
}

RenderableObjectManage::~RenderableObjectManage()
{
	//for (
	//	std::vector<RenderableObject*>::const_iterator it 
	//	= ROvecter->begin();
	//	it != ROvecter->end();
	//	++it
	//	)
	//{
	//	delete (*it);
	//}
	//ROvecter->clear();

	//delete ROvecter;
}

void RenderableObjectManage::ROadd(RenderableObject* renobj)
{
	ROvecter->push_back(renobj);
}

void RenderableObjectManage::MakeCube(const char* filepath, float x,
	float y,float z)
{
	Cube* cube = new Cube(filepath, x, y, z);
	ROadd(cube);

	delete cube;
}
void RenderableObjectManage::MakeHuman(const char* filepath, float x,
	float y, float z)
{
	Human* human = new Human(filepath, x, y, z);
	ROadd(human);

	delete human;
}