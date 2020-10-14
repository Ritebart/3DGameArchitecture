#ifndef RENDERABLEOBJECT_H_
#define RENDERABLEOBJECT_H_

#include "Object.h"

class RenderableObject : public Object
{
private:
	
protected:
	bool load;
	// obj ���� �ε��� ���� ����


public:
	~RenderableObject() {};
	//RenderableObject(const char* filepath);


	//void SetBuffer(const char* filepath); // obj ������ �ε����� �ش��ϴ� ������Ʈ���ٰ� �����Ű�� ����.
	virtual void SetMVP(glm::mat4 m, glm::mat4 v, glm::mat4 p) override; // ��ü���� ī�޶� ���� ��ǥ, ��ġ ��ǥ ���� ����.

	// mvp ���� �ݺ��� �ۿ��� �޾Ƽ� ���⿡ �ֱ� ���� �ȱ׷��� ����*�����̶� ���ϴ� �ͺ���
	// �� ������ ������
	virtual void SetP(glm::mat4 mvp, glm::mat4 p);

	virtual std::vector<glm::vec3> GetVertex();
	virtual std::vector<glm::vec2> GetUV();
	virtual std::vector<glm::vec3> GetNormal();
	virtual glm::mat4 GetMVP() override;

	virtual void Clean() override {};
};

#endif // !RENDERABLEOBJECT_H_
