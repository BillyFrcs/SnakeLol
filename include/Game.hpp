#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

#include "AssetsMan.hpp"
#include "StateMan.hpp"

enum AssetsID
{
    MAIN_FONT = 0,
    SCORE_FONT = 0,
    GRASS,
    FOOD,
    WALL,
    SNAKE,
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
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

public:
    Game();
    ~Game();

    void runGame();
};