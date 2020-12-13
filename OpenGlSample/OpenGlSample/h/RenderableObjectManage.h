#ifndef RENDERABLEOBJECTMANAGE_H_
#define RENDERABLEOBJECTMANAGE_H_

#include <iostream>
#include <vector>
#include "RenderableObject.h"


#pragma region 컴포지트 패턴 내 생각 2020 12 02*
/*
 컴포지트 패턴
 컴포지트의 역할을 가짐
 리프들인 RenderableObject를 상속받는 Cube나 Human을
 관리? 실행의 역할을 가진다.
 아마 main이나 엔진의 시작 아니면 이 것을 사용할 때
 코드 내부부분은 가리고 RenderableObjectManage를 통해
 추가하거나 움직일 수 있게 하는 용도인 듯.

 RenderableObject 자식 클래스들의
 init, update, clean은 MakeAbleObjectFucCall 클래스가
 관리함. 

 역할을 이쪽으로 옮긴다.
 - 이 클래스는 RenderableObject 관련만 사용 됨
   NonRenderableObject는 똑같은 것을 또 만들어야함.
   3가지 것은 시스템 연산부분이라 따로 하는 것이 나을듯

   아니면 어차피 템플릿화 시켜야 함으로 이쪽으로 옮기는
   것이 나을수도 있음.
 */
#pragma endregion



class RenderableObjectManage : public RenderableObject
{
private:
	std::vector<RenderableObject*> *ROvecter;
public:
	RenderableObjectManage();
	~RenderableObjectManage();

	void ROadd(RenderableObject* renobj);
	void MakeCube(const char* filepath, 
		float x = 0, 
		float y = 0,
		float z = 0);
	void MakeHuman(const char* filepath,
		float x = 0,
		float y = 0,
		float z = 0);
};

#endif