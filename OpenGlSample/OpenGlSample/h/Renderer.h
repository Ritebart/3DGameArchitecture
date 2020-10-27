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
	// RenderableObject 타입 벡터는 전방선언으로 선언에 문제가 없음
	//std::vector<NonRenderableObject> *nonrenderableObject;
	std::map<std::string, NonRenderableObject> nonrenderableObject;
	// NonRenderableObject 타입은 전방선언만으론 c2036 에러 발생
	// 통상적이라면 RenderableObject 벡터도 포인터 선언으로 하는 것이 아마 맞지만
	// 정상적으로 실행되기에 무언가가 이상하지만 
	// NonRenderableObject만 포인터 벡터로 선언하면 해결되기에 일단 보류.

	//std::vector<IUpdater> *allupdate;
	//추상 클래스의 인스턴스가 되게 제작되어서 실행이 안됨
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
	// 마우스의 움직임에 따라 저장되는 값.

	float fov = 45.0f;
	// 줌 인, 줌 아웃을 위한 값 작아지면 줌인 커지면 줌아웃

	bool checkmousecursor = true;
public:
	float DeltaTime = 0.0f;
	void SetWindowSize(int width, int height);
	void Render();
	// object들의 값을 받아와서 화면에 그림

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