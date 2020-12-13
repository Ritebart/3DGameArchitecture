#include "Renderer.h"
#include "RenderableObjectManage.h"
#include "NonRenderableObjectManage.h"
#include "Cube.h"
#include "Camera.h"
#include "Human.h"

int main()
{
	glm::mat4 cameraprojection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	glm::mat4 cameraview = glm::lookAt(
		glm::vec3(5, 5, 5),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 10, 0)
	);

	Cube* cube = new Cube("cube.obj", 3.0f, 0.0f, 0.0f);
	Cube* cube2 = new Cube("cube.obj", 6.0f, 0.0f, 0.0f);
	Cube* cube3 = new Cube("cube.obj", 10.0f, 0.0f, 0.0f);
	Human* human = new Human("human.obj", 0.0f, -4.0f, 0.0f);
	Human* human2 = new Human("human.obj", 2.0f, -4.0f, 0.0f);
	Camera* maincamera = new Camera("MainCamera", cameraprojection,
		cameraview);

	Renderer::Instance()->SetWindowSize(1600, 1200);
	Renderer::Instance()->Render("20181210 final report");

	delete cube;
	delete cube2;
	delete cube3;
	delete human;
	delete human2;
	delete maincamera;

	return 0;
}