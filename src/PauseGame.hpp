#pragma once

#ifndef PAUSE_GAME_HPP

	#include <SFML/Graphics/Text.hpp>

	#include <memory>

	#include "Game.hpp"
	#include "State.hpp"

class PauseGame : public Engine::State
{
private:
	std::shared_ptr<Context> mContext;
	sf::Text mPauseGameTitle;

public:
	PauseGame(std::shared_ptr<Context>& context);
	~PauseGame();

	void Init() override;
	void ProcessInput() override;
	void Update(sf::Time deltaTime) override;
	void Draw() override;
};

#endif