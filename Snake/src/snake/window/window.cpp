#include <iostream>

#include <snake/window/window.hpp>

window::window()
{
	initializeWindow();
}

window::~window()
{
	destroyWindow();
}

bool window::initializeWindow()
{
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW\n";
		return false;
	}
	
	m_Window = glfwCreateWindow(m_WindowWidth, m_WindowHeight, m_WindowTitle, nullptr, nullptr);

	if (!m_Window)
	{
		std::cout << "Failed to create Window\n";
		glfwTerminate();
		return false;
	}
	
	glfwMakeContextCurrent(m_Window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW\n";
		return false;
	}
	
	glfwSetKeyCallback(m_Window, keyCallback);

	return true;
}

void window::destroyWindow()
{
	glfwTerminate();
}

void window::render(const std::function<void()>& function)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	for (int i = 0; i < m_GameRectangleAmount; i++)
	{
		for (int j = 0; j < m_GameRectangleAmount; j++)
		{
			if(i % 2 && j % 2)
				glColor3f(0.5333333333333333, 0.2431372549019608, 0.1372549019607843);
			else if(i % 2 || j % 2)
				glColor3f(0.8862745098039216, 0.5294117647058824, 0.2627450980392157);
			else
				glColor3f(0.5333333333333333, 0.2431372549019608, 0.1372549019607843);
			drawGameRectangle(i, j);
		}
	}

	glColor3f(1, 1, 1);
	function();

	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

void window::drawRectangle(float xCoord, float yCoord, float width, float height)
{
	unsigned int buffer;

	float newY = yCoord * -2.0f / m_WindowHeight + 1.0f;
	float newX = xCoord * 2.0f / m_WindowWidth - 1.0f;
	
	float newWidth = width / m_WindowWidth;
	float newHeight = height / m_WindowHeight;
	
	

	//		0 | 1|
	//			 |
	//			 |
	//			 |
	//-1|0		 |		  1|0
	//-----------|-----------
	//			 |
	//			 |
	//			 |
	//			 |
	//		 0|-1|

	float positions[12] = {
		newX		   , newY,
		newX + newWidth, newY,
		newX + newWidth, newY - newHeight,

		newX + newWidth, newY - newHeight,
		newX		   , newY - newHeight,
		newX		   , newY
	};

	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void window::drawGameRectangle(int xPosition, int yPosition)
{
	float xCoord = (float)xPosition * (float)m_GameRectangleWidth;
	float yCoord = (float)yPosition * (float)m_GameRectangleHeight;
	
	drawRectangle(xCoord, yCoord, (float)m_GameRectangleWidth * 2, (float)m_GameRectangleHeight * 2);
}

GLFWwindow* window::getGLFWWindow()
{
	return m_Window;
}

int window::getLastButtonClicked()
{
	return m_LastButtonClicked;
}

int window::getGameRectangleAmount()
{
	return m_GameRectangleAmount;
}

void window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		m_LastButtonClicked = key;
	}
}