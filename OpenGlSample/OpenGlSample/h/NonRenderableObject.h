#ifndef NONRENDERABLEOBJECT_H_
#define NONRENDERABLEOBJECT_H_

#include "Object.h"

class NonRenderableObject : public Object
{
private:
	~NonRenderableObject() {}

protected:

public:
	virtual void SetMVP(glm::mat4 m, glm::mat4 v, glm::mat4 p) override;
	virtual glm::mat4 GetMVP() override;

	virtual void Clean() override;
};

#endif // !NONRENDERABLEOBJECT_H_
