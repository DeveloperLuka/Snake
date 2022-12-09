class apple
{
public:
	apple(int gameRectangles);
	~apple();
	
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

	vector2 getPosition();
	void setRandomPosition();

private:
	vector2 m_Position{0, 0};
	int m_GameRectangles = 0;
};