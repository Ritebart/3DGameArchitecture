#include "../h/Cube.h"
#include "../h/Human.h"
#include "../h/Camera.h"
#include "../h/FileManager.h"
#include "../h/IUpdater.h"
#include "../h/Renderer.h"

int main()
{
	glm::mat4 cameraprojection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	glm::mat4 cameraview = glm::lookAt(
		glm::vec3(5, 5, 5),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 10, 0)
	);

	glm::mat4 cubemove = glm::mat4(1.0f);
	cubemove = glm::translate(cubemove, glm::vec3(3.0f, 0.0f, 0.0f));
	glm::mat4 humanmove = glm::mat4(1.0f);
	humanmove = glm::translate(humanmove, glm::vec3(0.0f, -4.0f, 0.0f));

	Cube* cube = new Cube("cube.obj");
	Human* human = new Human("human.obj");

	Camera* maincamera = new Camera();
	maincamera->SetProjection(cameraprojection);
	maincamera->SetView(cameraview);

	cube->SetPosition(cubemove);
	human->SetPosition(humanmove);

	Renderer* renderer = new Renderer();
	renderer->AddObject(*cube);
	renderer->AddObject(*human);
	renderer->AddNonrenderObject("MainCamera", *maincamera);
	//renderer->AddUpdate(cube);
	//renderer->AddUpdate(human);
	//renderer->AddUpdate(maincamera);

	renderer->SetWindowSize(1600, 900);
	renderer->Render();

	renderer->Clean();

	delete cube;
	delete human;
	delete maincamera;
	delete renderer;

	return 0;
}

