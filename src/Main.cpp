#include "Game.hpp"
#include "Platform/Platform.hpp"

int main(void)
{
#if defined(_DEBUG)
	std::cout << "Billy Snake Game" << std::endl;
#endif

	Game* SnakeGame = new Game();

	SnakeGame->RunGame();

	return EXIT_SUCCESS;
}