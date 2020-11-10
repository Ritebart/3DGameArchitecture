#include <iostream>
#include "../h/RenderableObject.h"
#include "../h/IUpdater.h"

class TestCh : public RenderableObject
{
public:
	TestCh() {}

	virtual void Init() final { std::cout << "test의 스타트 실행" << std::endl; }
	virtual void Clean() final { std::cout << "test의 클린 실행" << std::endl; }
	virtual void RenDeltaTime() override {}
	virtual void Update() final { std::cout << "test의 업데이트 실행" << std::endl; }
};