#ifndef HUMAN_H_
#define HUMAN_H_

#include "RenderableObject.h"
#include "IUpdater.h"

class Human : public RenderableObject, public IUpdater
{
private:

public:
	Human(const char* filepath);
	~Human();

	virtual void Clean() final;
	virtual void RenDeltaTime() override;
	virtual void Update() override;
};

#endif // !HUMAN_H_
