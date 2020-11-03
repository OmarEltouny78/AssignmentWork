#include <stdio.h>
#include<GL/glew.h>
#include<GLFW/glfw3.h>


using namespace std;
GLuint VAO, VBO;

void CreateShape()
{
	//Assign vertices
	GLfloat vertices[] = {
		-1.0f,-1.0f,0.1f,
		1.0f,-1.0f,0.0f,
		0.0f,1.0f,0.0
	};


	//VAO--> VBO-->DATA-->Pointer to Data
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
int main()
{
	printf("Welcome to shaders ;) ");

	//init glfw
	if (!glfwInit())
	{
		printf("glfw error");
		glfwTerminate();
		return 1;
	}
	//setup and create window
	GLFWwindow* mainWindow = glfwCreateWindow(800, 600, "Shader1", NULL, NULL);
	if (!mainWindow)
	{
		printf("Window error");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(mainWindow);

	if (glewInit() != GLEW_OK)
	{
		printf("glew error");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}


	//view
	glViewport(0, 0, 800, 600);
	//Opengl Loop 

	CreateShape();
	while (!glfwWindowShouldClose(mainWindow))
	{
		//handlle events
		glfwPollEvents();

		//clear bg 
		glClearColor(0.0, 0.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		//draw 
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
		//assign buffers
		glfwSwapBuffers(mainWindow);
	}
	return 0;
}