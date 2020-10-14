#include "../h/Cube.h"
#include "../h/Human.h"
#include "../h/FileManager.h"
#include "../h/Renderer.h"

int main()
{
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	glm::mat4 View = glm::lookAt(
		glm::vec3(-5, 3, 5),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
	);
	glm::mat4 cubemove = glm::mat4(1.0f);
	cubemove = glm::translate(cubemove, glm::vec3(3.0f, 0.0f, 0.0f));
	glm::mat4 humanmove = glm::mat4(1.0f);
	humanmove = glm::translate(humanmove, glm::vec3(0.0f, -4.0f, 0.0f));

	Cube* cube = new Cube("cube.obj");
	Human* human = new Human("human.obj");

	//cube->SetBuffer("cube.obj");
	cube->SetMVP(Projection, View, cubemove);
	//human->SetBuffer("human.obj");
	human->SetMVP(Projection, View, humanmove);

	Renderer* renderer = new Renderer();

	std::vector<RenderableObject> renderobject;
	renderobject.push_back(*cube);
	renderobject.push_back(*human);

	renderer->Render(renderobject);
}
