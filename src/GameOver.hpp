#pragma once

#include <SFML/Graphics/Text.hpp>

#include <memory>

#include "Game.hpp"
#include "State.hpp"

class GameOver : public Engine::State
{
private:
    std::shared_ptr<Context> mContext;
    sf::Text mGameOverTitle, mGameRetryButton, mGameExitButton;

    bool retryButtonSelected, retryButtonPressed;
    bool exitButtonSelected, exitButtonPressed;

public:
    GameOver(std::shared_ptr<Context> &context);
    ~GameOver();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};