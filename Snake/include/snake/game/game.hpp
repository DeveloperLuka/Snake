#include <snake/game/snake/snake.hpp>
#include <snake/game/apple/apple.hpp>

#include <memory>

class game
{
private:
	window* m_Window = nullptr;
	std::unique_ptr<entitySnake> m_Snake;
	std::unique_ptr<apple> m_Apple;

public:
	game(window* window);
	~game();
	
	void loop();

	// checks if the snake has eaten the apple
	bool checkFood();

	void checkKeybinds();
	
	bool checkOverlapping();
};