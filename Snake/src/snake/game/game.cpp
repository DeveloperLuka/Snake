#include <Windows.h>

#include <snake/window/window.hpp>
#include <snake/game/game.hpp>

#include <gl/GL.h>

game::game(window* window)
{
	this->m_Window = window;
	m_Snake = std::make_unique<entitySnake>(m_Window->getGameRectangleAmount());
	m_Apple = std::make_unique<apple>(m_Window->getGameRectangleAmount());
	loop();
}

game::~game()
{
	
}

void game::loop()
{
	while (!glfwWindowShouldClose(m_Window->getGLFWWindow()))
	{
		if (glfwGetTime() > 0.6)
		{
			m_Snake->run();
			glfwSetTime(0);
		}

		m_Window->render([&]()
		{
			glColor3f(1, 0, 0);
			m_Window->drawGameRectangle(m_Apple->getPosition().x, m_Apple->getPosition().y);
			
			glColor3f(1, 1, 1);
			for (int i = 0; i < m_Snake->getBody().size(); i++)
			{
				m_Window->drawGameRectangle(m_Snake->getBody()[i].x, m_Snake->getBody()[i].y);
			}
		});
		checkKeybinds();

		checkFood();

		checkOverlapping();

		Sleep(50);
	}
}

bool game::checkFood()
{
	if (m_Snake->getBody()[0].x == m_Apple->getPosition().x && m_Snake->getBody()[0].y == m_Apple->getPosition().y)
	{
		m_Snake->grow();
		m_Apple->setRandomPosition();
		return true;
	}
	return false;
}

bool game::checkOverlapping()
{
	for(auto body : m_Snake->getBody())
	{
		if (body.x == m_Apple->getPosition().x && body.y == m_Apple->getPosition().y)
		{
			m_Apple->setRandomPosition();
			return true;
		}
	}

	return false;
}

void game::checkKeybinds()
{
	switch (m_Window->getLastButtonClicked())
	{
		case GLFW_KEY_UP:
		{
			if (m_Snake->getLookingDirection() != entitySnake::direction::up)
			{
				m_Snake->setLookingDirection(entitySnake::direction::up);
				m_Snake->run();
				glfwSetTime(0);
			}
			
			break;
		}
		case GLFW_KEY_RIGHT:
		{
			if (m_Snake->getLookingDirection() != entitySnake::direction::right)
			{
				m_Snake->setLookingDirection(entitySnake::direction::right);
				m_Snake->run();
				glfwSetTime(0);
			}
			break;
		}
		case GLFW_KEY_DOWN:
		{
			if (m_Snake->getLookingDirection() != entitySnake::direction::down)
			{
				m_Snake->setLookingDirection(entitySnake::direction::down);
				m_Snake->run();
				glfwSetTime(0);
			}
			break;
		}
		case GLFW_KEY_LEFT:
		{
			if (m_Snake->getLookingDirection() != entitySnake::direction::left)
			{
				m_Snake->setLookingDirection(entitySnake::direction::left);
				m_Snake->run();
				glfwSetTime(0);
			}
			break;
		}
		



		case GLFW_KEY_W:
		{
			if (m_Snake->getLookingDirection() != entitySnake::direction::up)
			{
				m_Snake->setLookingDirection(entitySnake::direction::up);
				m_Snake->run();
				glfwSetTime(0);
			}
			break;
		}
		case GLFW_KEY_D:
		{
			if (m_Snake->getLookingDirection() != entitySnake::direction::right)
			{
				m_Snake->setLookingDirection(entitySnake::direction::right);
				m_Snake->run();
				glfwSetTime(0);
			}
			break;
		}
		case GLFW_KEY_S:
		{
			if (m_Snake->getLookingDirection() != entitySnake::direction::down)
			{
				m_Snake->setLookingDirection(entitySnake::direction::down);
				m_Snake->run();
				glfwSetTime(0);
			}
			break;
		}
		case GLFW_KEY_A:
		{
			if (m_Snake->getLookingDirection() != entitySnake::direction::left)
			{
				m_Snake->setLookingDirection(entitySnake::direction::left);
				m_Snake->run();
				glfwSetTime(0);
			}
			break;
		}
	}
}