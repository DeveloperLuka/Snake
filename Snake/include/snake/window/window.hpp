#include <functional>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class window
{
private:
	GLFWwindow* m_Window = nullptr;
	const char* m_WindowTitle = "Snake";
	const int m_WindowWidth = 640;
	const int m_WindowHeight = 480;
	const int m_GameRectangleAmount = 8;
	const int m_GameRectangleWidth = m_WindowWidth / m_GameRectangleAmount;
	const int m_GameRectangleHeight = m_WindowHeight / m_GameRectangleAmount;

	inline static int m_LastButtonClicked;
public:
	window();
	~window();

	bool initializeWindow();

	void destroyWindow();

	void render(const std::function<void()>& function);

	void drawRectangle(float xCoord, float yCoord, float width, float height);
	// The Game consists of 40 boxes in the width and 40 boxes in the height so this method will draw a rectangle based on a box we give 1-40 | 1-40 instead of having to give the width and height and
	// exact x and y coordinates to draw our rectangle
	void drawGameRectangle(int xPosition, int yPosition);

	GLFWwindow* getGLFWWindow();
	int getLastButtonClicked();
	
	int getGameRectangleAmount();

	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};