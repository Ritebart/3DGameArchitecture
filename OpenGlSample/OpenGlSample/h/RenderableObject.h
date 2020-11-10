#ifndef RENDERABLEOBJECT_H_
#define RENDERABLEOBJECT_H_

#include "Object.h"
#include "IUpdater.h"
#include "IInit.h"

class RenderableObject : public Object, public IUpdater, public IInit
{
private:
	
protected:
	bool load;
	// obj ���� �ε��� ���� ����


public:
	virtual ~RenderableObject();
	//RenderableObject(const char* filepath);
	RenderableObject();
	RenderableObject(const char* filepath, float x, float y, float z);

	//void SetBuffer(const char* filepath); // obj ������ �ε����� �ش��ϴ� ������Ʈ���ٰ� �����Ű�� ����.
	virtual void SetMVP(glm::mat4 m, glm::mat4 v, glm::mat4 p) override; // ��ü���� ī�޶� ���� ��ǥ, ��ġ ��ǥ ���� ����.
	virtual void SetPosition(glm::mat4 m) override;
	// mvp ���� �ݺ��� �ۿ��� �޾Ƽ� ���⿡ �ֱ� ���� �ȱ׷��� ����*�����̶� ���ϴ� �ͺ���
	// �� ������ ������
	virtual std::vector<glm::vec3> GetVertex() const;
	virtual std::vector<glm::vec2> GetUV() const;
	virtual std::vector<glm::vec3> GetNormal() const;
	virtual glm::mat4 GetMVP() const override;
	virtual glm::mat4 GetPosition() const;

	virtual void Init() override;
	virtual void RenDeltaTime() {}
	virtual void Update() { std::cout << "�������̺� ����" << std::endl; }
	virtual void Clean() override;
};

#endif // !RENDERABLEOBJECT_H_
