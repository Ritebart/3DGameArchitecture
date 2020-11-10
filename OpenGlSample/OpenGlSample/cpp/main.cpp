#include "../h/Cube.h"
#include "../h/Human.h"
#include "../h/Camera.h"
#include "../h/FileManager.h"
#include "../h/IUpdater.h"
#include "../h/Renderer.h"
#include "../h/TestCh.h"

int main()
{
	glm::mat4 cameraprojection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	glm::mat4 cameraview = glm::lookAt(
		glm::vec3(5, 5, 5),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 10, 0)
	);

	Cube* cube = new Cube("cube.obj", 3.0f, 0.0f, 0.0f);
	Human* human = new Human("human.obj", 0.0f, -4.0f, 0.0f);
	TestCh* test = new TestCh();

	Camera* maincamera = new Camera();
	maincamera->SetProjection(cameraprojection);
	maincamera->SetView(cameraview);

	Renderer::Instance()->AddNonrenderObject("MainCamera", *maincamera);

	Renderer::Instance()->SetWindowSize(1600, 1200);
	Renderer::Instance()->Render();

	delete cube;
	delete human;
	delete maincamera;

	return 0;
}

