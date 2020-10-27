#ifndef RENDERER_H_
#define RENDERER_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "IClean.h"
#include "IUpdater.h"
#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h" 
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"

class RenderableObject;
class NonRenderableObject;

class Renderer : public IClean, public IUpdater
{
private:
	GLFWwindow* window;
	std::vector<RenderableObject> renderableObject;
	// RenderableObject Ÿ�� ���ʹ� ���漱������ ���� ������ ����
	//std::vector<NonRenderableObject> *nonrenderableObject;
	std::map<std::string, NonRenderableObject> nonrenderableObject;
	// NonRenderableObject Ÿ���� ���漱������ c2036 ���� �߻�
	// ������̶�� RenderableObject ���͵� ������ �������� �ϴ� ���� �Ƹ� ������
	// ���������� ����Ǳ⿡ ���𰡰� �̻������� 
	// NonRenderableObject�� ������ ���ͷ� �����ϸ� �ذ�Ǳ⿡ �ϴ� ����.

	//std::vector<IUpdater> *allupdate;
	//�߻� Ŭ������ �ν��Ͻ��� �ǰ� ���۵Ǿ ������ �ȵ�
	void SettingCamera();
    void DrawWindow(const char* exename);
	glm::vec3 cameraPos = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::mat4 SettingCameraZoom;
	glm::mat4 SettingCameraMove;

	int windowWidth = 900;
	int windowHeight = 700;

	double xpos = 0;
	double ypos = 0;

	float lastmousex = 0.0f;
	float lastmousey = 0.0f;
	float yaw = 0.0f;
	float pitch = 0.0f;
	// ���콺�� �����ӿ� ���� ����Ǵ� ��.

	float fov = 45.0f;
	// �� ��, �� �ƿ��� ���� �� �۾����� ���� Ŀ���� �ܾƿ�

	bool checkmousecursor = true;
public:
	float DeltaTime = 0.0f;
	void SetWindowSize(int width, int height);
	void Render();
	// object���� ���� �޾ƿͼ� ȭ�鿡 �׸�

	void AddObject(RenderableObject& renderableobject);
	void AddNonrenderObject(std::string name, NonRenderableObject& nonrenderableobject);

	void KeyboardInput(GLFWwindow* window);
	void MouseInput(GLFWwindow* window);

	//void AddUpdate(IUpdater* update);

	virtual void Clean() override;	
	virtual void RenDeltaTime() override;
	virtual void Update() override;
	
};

#endif // !