#include <snake/game/snake/snake.hpp>

entitySnake::entitySnake(int gameRectangles)
{
	m_GameRectangles = gameRectangles;
}

void entitySnake::run()
{
	vector2 buffer(0, 0);
	// starting at 1 because 0 will be set below
	for (int i = 1; i < m_Body.size(); i++)
	{
		
		if (i == 1)
		{
			buffer = m_Body.at(i);
			m_Body.at(i) = m_Body.at(i - 1);
		}
		else
		{
			vector2 swap = m_Body.at(i);
			m_Body.at(i) = buffer;
			buffer = swap;
		}
	}

	switch (m_LookingDirection)
	{
		case direction::up:
		{
			m_Body.at(0).y -= 1;
			break;
		}
		case direction::right:
		{
			m_Body.at(0).x += 1;
			break;
		}
		case direction::down:
		{
			m_Body.at(0).y += 1;
			break;
		}
		case direction::left:
		{
			m_Body.at(0).x -= 1;
			break;
		}
	}

	if (checkCollision())
	{
		reset();
	}
}

void entitySnake::grow()
{
	// just add a new vector2 to the end of the body out of the screen, it will get added to the body in the next mainloop tick
	m_Body.push_back(vector2(-1, -1));
}

bool entitySnake::checkCollision()
{
	for (int i = 0; i < m_Body.size(); i++)
	{
		for (int j = 0; j < m_Body.size(); j++)
		{
			if (i == j)
				continue;
			
			if (m_Body.at(i).x != m_Body.at(j).x || m_Body.at(i).y != m_Body.at(j).y)
				continue;
			
			return true;
		}
	}
	
	if(m_Body.at(0).x < 0 || m_Body.at(0).y < 0 || m_Body.at(0).x > m_GameRectangles - 1 || m_Body.at(0).y > m_GameRectangles - 1)
		return true;
	
	return false;
}

void entitySnake::reset()
{
	m_Body = { vector2(5, 5), vector2(4, 5), vector2(3, 5) };
	m_LookingDirection = direction::right;
}

void entitySnake::setLookingDirection(entitySnake::direction lookingDirection)
{
	m_LookingDirection = lookingDirection;
}

entitySnake::direction entitySnake::getLookingDirection()
{
	return m_LookingDirection;
}

std::vector<entitySnake::vector2> entitySnake::getBody()
{
	return m_Body;
}