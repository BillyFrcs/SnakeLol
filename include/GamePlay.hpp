#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Game.hpp"
#include "State.hpp"

#include <array>
#include <memory>

class GamePlay : public Engine::State
{
private:
    std::shared_ptr<Context> mContext;
    sf::Sprite mGrass;
    sf::Sprite mFood;
    std::array<sf::Sprite, 4> mWalls;

    //Added snake

public:
    GamePlay(std::shared_ptr<Context> &mContext);
    ~GamePlay();

    virtual void Init() override;
    virtual void ProcessInput() override;
    virtual void Update(sf::Time deltaTime) override;
    virtual void Draw() override;

    //Method
    virtual void Pause() override;
    virtual void Start() override;
};