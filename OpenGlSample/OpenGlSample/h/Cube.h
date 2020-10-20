#ifndef CUBE_H_
#define CUBE_H_

#include "RenderableObject.h"
#include "IUpdater.h"

class Cube : public RenderableObject, public IUpdater
{
private:
	
public:
	Cube(const char* filepath);
	~Cube();

	virtual void Clean() final;
	virtual void Update() override;
};

#endif // !CUBE_H_
