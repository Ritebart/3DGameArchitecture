#ifndef CAMERA_H_
#define CAMERA_H_

#include "NonRenderableObject.h"
#include "IUpdater.h"


class Camera : public NonRenderableObject, public IUpdater
{
private:

public:
	Camera();
	Camera(
		std::string name, glm::mat4 projection, glm::mat4 view,
		float x = 0, float y = 0, float z = 0);
	~Camera();

	virtual void Init() final;
	virtual void Clean() final;
	virtual void RenDeltaTime() override;
	virtual void Update() override;
};


#endif