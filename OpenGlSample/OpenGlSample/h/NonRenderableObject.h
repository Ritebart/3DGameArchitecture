#ifndef NONRENDERABLEOBJECT_H_
#define NONRENDERABLEOBJECT_H_

#include "Object.h"

class NonRenderableObject : public Object
{
private:
	

protected:

public:
	virtual ~NonRenderableObject();
	virtual void SetMVP(glm::mat4 m, glm::mat4 v, glm::mat4 p) override;
	virtual glm::mat4 GetMVP() override;

	virtual void Clean() override;
};

#endif // !NONRENDERABLEOBJECT_H_
