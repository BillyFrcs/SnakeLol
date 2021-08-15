#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <array>
#include <memory>

#include "Game.hpp"
#include "State.hpp"
#include "Snake.hpp"

class GamePlay : public Engine::State
{
private:
    std::shared_ptr<Context> mContext;
    sf::Sprite mGrass;
    sf::Sprite mFood;
    std::array<sf::Sprite, 4> mWalls;

    //Added snake
    Snake mSnake;

    //Add score
    sf::Text mScoreText;
    int mScore;

    sf::Vector2f mSnakeDirection;
    sf::Time mElapsedTime;

    bool isPaused;

public:
    GamePlay(std::shared_ptr<Context> mContext);
    ~GamePlay();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;

    //Method
    void Pause() override;
    void Start() override;
};