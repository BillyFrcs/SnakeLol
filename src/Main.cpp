#include "Game.hpp"
#include "Platform/Platform.hpp"

int main(void)
{
#if defined(_DEBUG)
	std::cout << "Billy Games | Snake" << std::endl;
#endif

	Game* SnakeGame = new Game();

	SnakeGame->RunGame();

	return EXIT_SUCCESS;
}