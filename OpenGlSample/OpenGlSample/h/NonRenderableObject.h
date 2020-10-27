#ifndef NONRENDERABLEOBJECT_H_
#define NONRENDERABLEOBJECT_H_

#include "Object.h"

class NonRenderableObject : public Object
{
private:
	

protected:
	

public:
	virtual ~NonRenderableObject();

	void SetProjection(glm::mat4 p);
	void SetView(glm::mat4 v);

	glm::mat4 GetProjection() const;
	glm::mat4 GetView() const;

	virtual void Clean() override;
	virtual void SetMVP(glm::mat4 m, glm::mat4 v, glm::mat4 p) override;
	virtual void SetPosition(glm::mat4 m) override;
	virtual glm::mat4 GetMVP() const override;

	
};

#endif // !NONRENDERABLEOBJECT_H_
