#include <SFML/Graphics/CircleShape.hpp>

#include "Game.hpp"
#include "MainMenu.hpp"

Game::Game() : mContext(std::make_shared<Context>())
{
     mContext->mWindow->create(sf::VideoMode(700, 400), "Snake Game", sf::Style::Close);
     //Add the first state to mState here
     mContext->mStates->Add(std::make_unique<MainMenu>(mContext));
}

Game::~Game()
{
}

//Display the game
void Game::Run()
{
     sf::CircleShape shape(100.f);
     shape.setFillColor(sf::Color::Magenta);

     sf::Clock clock;
     sf::Time timeSinceLastFrame = sf::Time::Zero;

     while (mContext->mWindow->isOpen())
     {
          timeSinceLastFrame += clock.restart();

          while (timeSinceLastFrame > TIME_PER_FRAME)
          {
               timeSinceLastFrame -= TIME_PER_FRAME;

               //Tasks
               mContext->mStates->processStateChange();
               mContext->mStates->getCurrent()->ProcessInput();
               mContext->mStates->getCurrent()->Update(TIME_PER_FRAME);
               mContext->mStates->getCurrent()->Draw();
          }
     }
}