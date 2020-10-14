#ifndef RENDERER_H_
#define RENDERER_H

#include <iostream>
#include <vector>

#include "IClean.h"
#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h" 
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"

class RenderableObject;

class Renderer : IClean
{
private:
	GLFWwindow* window;
	
public:
	void Render(std::vector<RenderableObject> &renderableObject);
	// object���� ���� �޾ƿͼ� ȭ�鿡 �׸�

	void DrawWindow(const char* exename);

	virtual void Clean() override {};
	// �����츸 �׷���
};

#endif // !