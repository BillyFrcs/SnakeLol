#include <SFML/Graphics/CircleShape.hpp>

#include "Game.hpp"
#include "MainMenu.hpp"

#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 500

Game::Game() :
	mContext(std::make_shared<Context>())
{
	//Render the snake game
	mContext->mWindow->create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Snake Game", sf::Style::Close);

	util::Platform platform;

	platform.setIcon(mContext->mWindow->getSystemHandle());

	// Go to main menu state
	mContext->mStates->Add(std::make_unique<MainMenu>(mContext));
}

Game::~Game()
{
}

//Display and run the game
void Game::RunGame()
{
	sf::Clock clock;

	sf::Time timeSinceLastFrame = sf::Time::Zero;

	while (mContext->mWindow->isOpen())
	{
		timeSinceLastFrame += clock.restart();

		while (timeSinceLastFrame > _timePerFrame)
		{
			(timeSinceLastFrame -= _timePerFrame);

			mContext->mStates->processStateChange();
			mContext->mStates->getCurrent()->ProcessInput();
			mContext->mStates->getCurrent()->Update(_timePerFrame);
			mContext->mStates->getCurrent()->Draw();
		}
	}
}