#include <snake/game/apple/apple.hpp>

#include <random>

apple::apple(int gameRectangles)
{
	m_GameRectangles = gameRectangles;

	setRandomPosition();
}

apple::~apple()
{
	
}

apple::vector2 apple::getPosition()
{
	return m_Position;
}

void apple::setRandomPosition()
{
	srand(time(NULL));
	m_Position.x = rand() % m_GameRectangles;
	m_Position.y = rand() % m_GameRectangles;
}