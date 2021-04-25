#include "Game.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

Game::Game() : mContext(std::make_shared<Context>())
{
     mContext->mWindow->create(sf::VideoMode(200, 200), "Snake Game", sf::Style::Close);
     //Add the first state to mState here
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
               //mContext->mStates->processStateChange();
               //mContext->mStates->getCurrent();
               //mContext->mStates->getCurrent()->Update(TIME_PER_FRAME);
               //mContext->mStates->getCurrent()->Draw();

               sf::Event event;
               while (mContext->mWindow->pollEvent(event))
               {
                    if (event.type == sf::Event::Closed)
                         mContext->mWindow->close();
               }

               mContext->mWindow->clear();
               mContext->mWindow->draw(shape);
               mContext->mWindow->display();
          }
     }
}