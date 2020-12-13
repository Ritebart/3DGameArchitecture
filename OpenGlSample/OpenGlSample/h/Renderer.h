#ifndef RENDERER_H_
#define RENDERER_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <Windows.h>
//#include <fbxsdk.h>

#include "IClean.h"
#include "IUpdater.h"
#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h" 
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"

//#include "../h/NonRenderableObject.h"

class RenderableObject;
class NonRenderableObject;

class Renderer : public IClean, public IUpdater
{
private:
	static Renderer* r_instance;
	Renderer();

	GLFWwindow* window;
	std::vector<RenderableObject> renderableObject;
	std::vector<glm::mat4> objectmodel;
	std::map<std::string, NonRenderableObject> *nonrenderableObject;


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
	
	//FbxManager* fbxmanager = nullptr;
	//FbxScene* fbxscene;
public:
//	float DeltaTime = 0.0f;
	static Renderer* Instance()
	{
		if (r_instance == NULL)
		{
			r_instance = new Renderer();
		}
		return r_instance;
	}
	void SetWindowSize(int width, int height);
	void Render(const char* gamename);
	// object들의 값을 받아와서 화면에 그림

	void AddObject(RenderableObject& renderableobject);
	void AddNonrenderObject(std::string name, NonRenderableObject& nonrenderableobject);

	void AddObjectModel(glm::mat4 model);

	void KeyboardInput(GLFWwindow* window);
	void MouseInput(GLFWwindow* window);

	virtual void Clean() override;	
	virtual void RenDeltaTime() override;
	virtual void Update() override;
	
};

#endif // !