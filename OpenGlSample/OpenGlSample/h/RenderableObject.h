#ifndef RENDERABLEOBJECT_H_
#define RENDERABLEOBJECT_H_

#include "Object.h"

class RenderableObject : public Object
{
private:
	
protected:
	bool load;
	// obj 파일 로딩을 위한 변수


public:
	~RenderableObject() {};
	//RenderableObject(const char* filepath);


	//void SetBuffer(const char* filepath); // obj 파일을 로딩시켜 해당하는 오브젝트에다가 연결시키기 위함.
	virtual void SetMVP(glm::mat4 m, glm::mat4 v, glm::mat4 p) override; // 객체마다 카메라 시점 좌표, 위치 좌표 설정 가능.

	// mvp 값을 반복문 밖에서 받아서 여기에 넣기 위함 안그러면 곱셈*곱셈이라 원하던 것보다
	// 더 빠르게 움직임
	virtual void SetP(glm::mat4 mvp, glm::mat4 p);

	virtual std::vector<glm::vec3> GetVertex();
	virtual std::vector<glm::vec2> GetUV();
	virtual std::vector<glm::vec3> GetNormal();
	virtual glm::mat4 GetMVP() override;

	virtual void Clean() override {};
};

#endif // !RENDERABLEOBJECT_H_
