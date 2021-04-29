#include "PauseGame.hpp"

#include <SFML/Window/Event.hpp>

PauseGame::PauseGame(std::shared_ptr<Context> &context) : mContext(context)
{
}

PauseGame::~PauseGame()
{
}

void PauseGame::Init()
{
     //Pause game title
     mPauseGameTitle.setFont(mContext->mAssets->getFont(MAIN_FONT));
     mPauseGameTitle.setString("Pause Game");
     mPauseGameTitle.setOrigin(mPauseGameTitle.getLocalBounds().width / 2, mPauseGameTitle.getLocalBounds().height / 2);
     mPauseGameTitle.setPosition(mContext->mWindow->getSize().x / 2, mContext->mWindow->getSize().y / 2);
     mPauseGameTitle.setFillColor(sf::Color::White);
}

void PauseGame::ProcessInput()
{
     sf::Event event;

     while (mContext->mWindow->pollEvent(event))
     {
          if (event.type == sf::Event::Closed)
          {
               mContext->mWindow->close();
          }

          else if (event.type == sf::Event::KeyPressed)
          {
               switch (event.key.code)
               {
                    //Keyboard control
               case sf::Keyboard::Escape:
               {
                    mContext->mStates->popCurrent();
                    break;
               }

               default:
                    break;
               }
          }
     }
}

void PauseGame::Update(sf::Time deltaTime)
{
}

void PauseGame::Draw()
{
     //Draw to the window
     mContext->mWindow->draw(mPauseGameTitle);

     mContext->mWindow->display();
}