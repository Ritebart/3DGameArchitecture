#ifndef NONRENDERABLEOBJECTMANAGE_H_
#define NONRENDERABLEOBJECTMANAGE_H_


#include <iostream>
#include <string>
#include <vector>
#include "NonRenderableObject.h"


class NonRenderableObjectManage : public NonRenderableObject
{
private:
	std::vector<NonRenderableObject*>* NROvecter;
public:
	NonRenderableObjectManage();
	~NonRenderableObjectManage();

	void NROadd(NonRenderableObject* nrenobj);
	void MakeCamera(std::string name,
		glm::mat4 projection, glm::mat4 view,
		float x = 0, float y = 0, float z = 0);
};


#endif