#include "../h/Renderer.h"
#include "../h/RenderableObject.h"
#include "../h/FileManager.h"
#include "../h/IUpdater.h"

void Renderer::DrawWindow(const char* exename)
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(1024, 768, exename, NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);

	// We would expect width and height to be 1024 and 768
	int windowWidth = 1024;
	int windowHeight = 768;
	// But on MacOS X with a retina screen it'll be 1024*2 and 768*2, so we get the actual framebuffer size:
	glfwGetFramebufferSize(window, &windowWidth, &windowHeight);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	// Hide the mouse and enable unlimited mouvement
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Set the mouse at the center of the screen
	glfwPollEvents();
	glfwSetCursorPos(window, 1024 / 2, 768 / 2);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);
}
void Renderer::AddObject(RenderableObject& renderableobject)
{
	renderableObject.push_back(renderableobject);
}

void Renderer::Update(IUpdater* updateobject)
{

}

void Renderer::Clean()
{
	if (!renderableObject.empty())
	{
		for (std::vector<RenderableObject>::iterator cleaniter = renderableObject.begin();
			cleaniter != renderableObject.end();
			++cleaniter)
		{
			cleaniter->Clean();
		}
		std::vector<RenderableObject>().swap(renderableObject);
	}
	else
		return;
}

void Renderer::Render()
{
	if (renderableObject.empty())
		return;

	DrawWindow("20181210_week 7 report");

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	//MVP = object->GetMVP();
	GLuint programID = FileManager::Instance()->LoadShaders("vs.shader", "fs.shader");
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	GLuint TextureID = glGetUniformLocation(programID, "myTextureSampler");

	std::vector<RenderableObject>::iterator obiter;
	std::vector<glm::mat4> mvp(renderableObject.size());
	std::vector<GLuint> vertexbuffer(renderableObject.size());
	std::vector<GLuint> uvbuffer(renderableObject.size());
	std::vector<GLuint> normalbuffer(renderableObject.size());
	int setbuffer = 0;
	int renderbuffer = 0;
	for (obiter = renderableObject.begin(); obiter != renderableObject.end(); ++obiter)
	{
		glGenBuffers(1, &vertexbuffer[setbuffer]);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[setbuffer]);
		glBufferData(GL_ARRAY_BUFFER, obiter->GetVertex().size() * sizeof(glm::vec3), &(obiter->GetVertex())[0], GL_STATIC_DRAW);

		glGenBuffers(1, &uvbuffer[setbuffer]);
		glBindBuffer(GL_ARRAY_BUFFER, uvbuffer[setbuffer]);
		glBufferData(GL_ARRAY_BUFFER, obiter->GetUV().size() * sizeof(glm::vec2), &(obiter->GetUV())[0], GL_STATIC_DRAW);

		glGenBuffers(1, &normalbuffer[setbuffer]);
		glBindBuffer(GL_ARRAY_BUFFER, normalbuffer[setbuffer]);
		glBufferData(GL_ARRAY_BUFFER, obiter->GetNormal().size() * sizeof(glm::vec3), &(obiter->GetNormal())[0], GL_STATIC_DRAW);

		mvp[setbuffer] = obiter->GetMVP();
		setbuffer++;
	}		
	glm::mat4 rotate = glm::mat4(1.0f);
	float rotangle = 1.0f;		
	
	do {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(programID);
		renderbuffer = 0;
		rotate = glm::rotate(rotate, glm::radians(rotangle), glm::vec3(0.0f, 1.0f, 0.0f));

		for (obiter = renderableObject.begin(); obiter != renderableObject.end(); ++obiter)
		{
			obiter->SetP(mvp[renderbuffer], rotate);
			glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &(obiter->GetMVP())[0][0]);
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(TextureID, 0);

			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[renderbuffer]);
			glVertexAttribPointer(
				0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
				3,                  // size
				GL_FLOAT,           // type
				GL_FALSE,           // normalized?
				0,                  // stride
				(void*)0            // array buffer offset
			);
			glEnableVertexAttribArray(1);
			glBindBuffer(GL_ARRAY_BUFFER, uvbuffer[renderbuffer]);
			glVertexAttribPointer(
				1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
				2,                  // size
				GL_FLOAT,           // type
				GL_FALSE,           // normalized?
				0,                  // stride
				(void*)0            // array buffer offset
			);
			glEnableVertexAttribArray(2);
			glBindBuffer(GL_ARRAY_BUFFER, normalbuffer[renderbuffer]);
			glVertexAttribPointer(
				2,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
				3,                  // size
				GL_FLOAT,           // type
				GL_FALSE,           // normalized?
				0,                  // stride
				(void*)0            // array buffer offset

			);
			glDrawArrays(GL_TRIANGLES, 0, obiter->GetVertex().size());
			renderbuffer++;
			glDisableVertexAttribArray(0);
			glDisableVertexAttribArray(1);
			glDisableVertexAttribArray(2);
		}
		glfwSwapBuffers(window);
		glfwPollEvents();

	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

	//glDeleteBuffers(1, &vertexbuffer);
	//glDeleteBuffers(1, &uvbuffer);
	//glDeleteBuffers(1, &normalbuffer);
	//delete vertexbuffer;
	//delete& uvbuffer;
	//delete& normalbuffer;
	glDeleteProgram(programID);
}