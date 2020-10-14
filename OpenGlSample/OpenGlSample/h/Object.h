#ifndef OBJECT_H_
#define OBJECT_H_

//#include <iostream>
//#include <vector>
//
//#include "IClean.h"
//#include "../include/GL/glew.h"
//#include "../include/GLFW/glfw3.h" 
//#include "../glm/glm.hpp"
//#include "../glm/gtc/matrix_transform.hpp"
//
//class Object : IClean
//{
//private:
//	std::vector<glm::vec3> vertex;
//	std::vector<glm::vec2> uv;
//	std::vector<glm::vec3> normal;
//	std::vector<unsigned short> indices;
//	std::vector<glm::vec3> indexed_vertices;
//	std::vector<glm::vec2> indexed_uvs;
//	std::vector<glm::vec3> indexed_normals;
//	glm::mat4 MVP;
//
//	bool load;
//	// obj 파일 로딩을 위한 변수
//public:
//
//	Object(const char* filepath);
//	virtual ~Object() {};
//
//	//void SetBuffer(const char* filepath); // obj 파일을 로딩시켜 해당하는 오브젝트에다가 연결시키기 위함.
//	void SetMVP(glm::mat4 m, glm::mat4 v, glm::mat4 p); // 객체마다 카메라 시점 좌표, 위치 좌표 설정 가능.
//
//	// mvp 값을 반복문 밖에서 받아서 여기에 넣기 위함 안그러면 곱셈*곱셈이라 원하던 것보다
//	// 더 빠르게 움직임
//	void SetP(glm::mat4 mvp, glm::mat4 p);
//
//	std::vector<glm::vec3> GetVertex();
//	std::vector<glm::vec2> GetUV();
//	std::vector<glm::vec3> GetNormal();
//	glm::mat4 GetMVP();
//
//	virtual void Clean() override {};
//	// render에서 object의 값을 사용하기 위한 get 함수들.
//};

#include <iostream>
#include <vector>

#include "IClean.h"
#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h" 
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"

class Object : public IClean
{
protected:
	std::vector<glm::vec3> vertex;
	std::vector<glm::vec2> uv;
	std::vector<glm::vec3> normal;
	std::vector<unsigned short> indices;
	std::vector<glm::vec3> indexed_vertices;
	std::vector<glm::vec2> indexed_uvs;
	std::vector<glm::vec3> indexed_normals;
	glm::mat4 MVP;

	virtual void SetMVP(glm::mat4 m, glm::mat4 v, glm::mat4 p) {}
	virtual glm::mat4 GetMVP() { return MVP; }
public:

	virtual ~Object() {};

	virtual void Clean() {};
};


#endif // !OBJECT_H_
