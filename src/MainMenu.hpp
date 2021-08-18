#pragma once

#ifndef MAIN_MENU_HPP
	#define MAIN_MENU_HPP

	#include <SFML/Graphics/Text.hpp>

	#include <memory>

	#include "Game.hpp"
	#include "State.hpp"

class MainMenu : public Engine::State
{
private:
	std::shared_ptr<Context> mContext;
	sf::Text mGameTitle, mGamePlayButton, mGameExitButton;

	bool playButtonSelected = true, playButtonPressed = false;
	bool exitButtonSelected = false, exitButtonPressed = false;

public:
	MainMenu(std::shared_ptr<Context>& context);
	~MainMenu();

	void Init() override;
	void ProcessInput() override;
	void Update(sf::Time deltaTime) override;
	void Draw() override; //Same as zero
};

#endif // MAIN_MENU_HPP