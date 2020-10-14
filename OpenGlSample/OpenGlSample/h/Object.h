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
//	// obj ���� �ε��� ���� ����
//public:
//
//	Object(const char* filepath);
//	virtual ~Object() {};
//
//	//void SetBuffer(const char* filepath); // obj ������ �ε����� �ش��ϴ� ������Ʈ���ٰ� �����Ű�� ����.
//	void SetMVP(glm::mat4 m, glm::mat4 v, glm::mat4 p); // ��ü���� ī�޶� ���� ��ǥ, ��ġ ��ǥ ���� ����.
//
//	// mvp ���� �ݺ��� �ۿ��� �޾Ƽ� ���⿡ �ֱ� ���� �ȱ׷��� ����*�����̶� ���ϴ� �ͺ���
//	// �� ������ ������
//	void SetP(glm::mat4 mvp, glm::mat4 p);
//
//	std::vector<glm::vec3> GetVertex();
//	std::vector<glm::vec2> GetUV();
//	std::vector<glm::vec3> GetNormal();
//	glm::mat4 GetMVP();
//
//	virtual void Clean() override {};
//	// render���� object�� ���� ����ϱ� ���� get �Լ���.
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
