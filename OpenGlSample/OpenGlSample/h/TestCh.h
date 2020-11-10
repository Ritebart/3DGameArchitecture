#include <iostream>
#include "../h/RenderableObject.h"
#include "../h/IUpdater.h"

class TestCh : public RenderableObject
{
public:
	TestCh() {}

	virtual void Init() final { std::cout << "test�� ��ŸƮ ����" << std::endl; }
	virtual void Clean() final { std::cout << "test�� Ŭ�� ����" << std::endl; }
	virtual void RenDeltaTime() override {}
	virtual void Update() final { std::cout << "test�� ������Ʈ ����" << std::endl; }
};