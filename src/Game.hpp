#pragma once

#ifndef GAME_HPP

	#include <SFML/Graphics/RenderWindow.hpp>

	#include <memory>

	#include "AssetsMan.hpp"
	#include "StateMan.hpp"

enum AssetsID
{
	E_Main_Font = 0,
	E_Score_Font = 0,
	E_Wall,
	E_Food,
	E_Background,
	E_Snake,
};

class Context
{
public:
	std::unique_ptr<Engine::AssetsMan> mAssets;
	std::unique_ptr<Engine::StateMan> mStates;
	std::unique_ptr<sf::RenderWindow> mWindow;

	Context()
	{
		mAssets = std::make_unique<Engine::AssetsMan>();
		mStates = std::make_unique<Engine::StateMan>();
		mWindow = std::make_unique<sf::RenderWindow>();
	}
};

class Game
{
private:
	std::shared_ptr<Context> mContext;
	const sf::Time _timePerFrame = sf::seconds(1.f / 60.f);

public:
	Game();
	~Game();

	void RunGame();
};

#endif