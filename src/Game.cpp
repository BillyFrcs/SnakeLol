#include "Game.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

#include "MainMenu.hpp"

Game::Game() : mContext(std::make_shared<Context>())
{
     mContext->mWindow->create(sf::VideoMode(600, 400), "Snake 2D", sf::Style::Close);
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
     shape.setFillColor(sf::Color::Blue);

     sf::Clock clock;
     sf::Time timeSinceLastFrame = sf::Time::Zero;

     while (mContext->mWindow->isOpen())
     {
          timeSinceLastFrame += clock.restart();

          while (timeSinceLastFrame > TIME_PER_FRAME)
          {
               (timeSinceLastFrame -= TIME_PER_FRAME);

               //Tasks
               mContext->mStates->processStateChange();
               mContext->mStates->getCurrent()->ProcessInput();
               mContext->mStates->getCurrent()->Update(TIME_PER_FRAME);
               mContext->mStates->getCurrent()->Draw();
          }
     }
}