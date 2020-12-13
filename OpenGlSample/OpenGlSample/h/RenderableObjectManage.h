#ifndef RENDERABLEOBJECTMANAGE_H_
#define RENDERABLEOBJECTMANAGE_H_

#include <iostream>
#include <vector>
#include "RenderableObject.h"


#pragma region ������Ʈ ���� �� ���� 2020 12 02*
/*
 ������Ʈ ����
 ������Ʈ�� ������ ����
 �������� RenderableObject�� ��ӹ޴� Cube�� Human��
 ����? ������ ������ ������.
 �Ƹ� main�̳� ������ ���� �ƴϸ� �� ���� ����� ��
 �ڵ� ���κκ��� ������ RenderableObjectManage�� ����
 �߰��ϰų� ������ �� �ְ� �ϴ� �뵵�� ��.

 RenderableObject �ڽ� Ŭ��������
 init, update, clean�� MakeAbleObjectFucCall Ŭ������
 ������. 

 ������ �������� �ű��.
 - �� Ŭ������ RenderableObject ���ø� ��� ��
   NonRenderableObject�� �Ȱ��� ���� �� ��������.
   3���� ���� �ý��� ����κ��̶� ���� �ϴ� ���� ������

   �ƴϸ� ������ ���ø�ȭ ���Ѿ� ������ �������� �ű��
   ���� �������� ����.
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