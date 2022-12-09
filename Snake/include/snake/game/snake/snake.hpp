#include <vector>

class entitySnake
{
public:
	entitySnake(int gameRectangles);

	struct vector2
	{
		vector2(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
		int x;
		int y;
	};

	enum direction
	{
		up,
		down,
		left,
		right
	};

	// Method that will run in the game Loop
	void run();

	void grow();

	bool checkCollision();

	void reset();

	void setLookingDirection(direction lookingDirection);
	direction getLookingDirection();
	
	std::vector<vector2> getBody();
private:
	direction m_LookingDirection = direction::right;
	
	// m_Body[0] = Head Position, m_Body[1] = the second part of the body and so on.
	std::vector<vector2> m_Body = { vector2(1, 1), vector2(1, 2), vector2(1, 3) };
	int m_GameRectangles = 0;
};