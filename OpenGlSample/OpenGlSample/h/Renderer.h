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
class IUpdater;

class Renderer : IClean
{
private:
	GLFWwindow* window;
	std::vector<RenderableObject> renderableObject;

public:
	void Render();
	// object들의 값을 받아와서 화면에 그림

	void DrawWindow(const char* exename);

	void Update(IUpdater* updateobject);
	void AddObject(RenderableObject& renderableobject);

	virtual void Clean() override;
};

#endif // !