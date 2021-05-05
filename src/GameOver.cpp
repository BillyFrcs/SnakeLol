#include "GameOver.hpp"
#include "GamePlay.hpp"

#include <SFML/Window/Event.hpp>

GameOver::GameOver(std::shared_ptr<Context> &context) : mContext(context), retryButtonSelected(true), retryButtonPressed(false), exitButtonSelected(false), exitButtonPressed(false)
{
}

GameOver::~GameOver()
{
}

void GameOver::Init()
{
     mContext->mAssets->addFont(MAIN_FONT, "assets/fonts/MaldiniBold.ttf");

     //Game over 
     mGameOverTitle.setFont(mContext->mAssets->getFont(MAIN_FONT));
     mGameOverTitle.setString("Game Over");
     mGameOverTitle.setOrigin(mGameOverTitle.getLocalBounds().width / 2, mGameOverTitle.getLocalBounds().height / 2);
     mGameOverTitle.setPosition(mContext->mWindow->getSize().x / 2, mContext->mWindow->getSize().y / 2 - 150.f);

     //Retry game
     mGameRetryButton.setFont(mContext->mAssets->getFont(MAIN_FONT));
     mGameRetryButton.setString("Retry");
     mGameRetryButton.setOrigin(mGameOverTitle.getLocalBounds().width / 2, mGameOverTitle.getLocalBounds().height / 2);
     mGameRetryButton.setPosition(mContext->mWindow->getSize().x / 2, mContext->mWindow->getSize().y / 2 - 30.f);
     mGameRetryButton.setCharacterSize(40);

     //Exit game
     mGameExitButton.setFont(mContext->mAssets->getFont(MAIN_FONT));
     mGameExitButton.setString("Exit");
     mGameExitButton.setOrigin(mGameOverTitle.getLocalBounds().width / 2, mGameOverTitle.getLocalBounds().height / 2);
     mGameExitButton.setPosition(mContext->mWindow->getSize().x / 2, mContext->mWindow->getSize().y / 2 + 20.f);
     mGameExitButton.setCharacterSize(40);
}

void GameOver::ProcessInput()
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
               case sf::Keyboard::Up:
               {
                    if (!retryButtonSelected)
                    {
                         retryButtonSelected = true;
                         exitButtonSelected = false;
                    }
                    break;
               }

               case sf::Keyboard::Down:
               {
                    if (!exitButtonSelected)
                    {
                         retryButtonSelected = false;
                         exitButtonSelected = true;
                    }
                    break;
               }

               case sf::Keyboard::Return:
               {
                    retryButtonPressed = false;
                    exitButtonPressed = false;

                    if (retryButtonSelected)
                    {
                         retryButtonPressed = true;
                    }
                    else
                    {
                         exitButtonPressed = true;
                    }
                    break;
               }

               default:
                    break;
               }
          }
     }
}

void GameOver::Update(sf::Time deltaTime)
{
     if (retryButtonSelected)
     {
          mGameRetryButton.setFillColor(sf::Color::Black);
          mGameExitButton.setFillColor(sf::Color::White);
     }

     else
     {
          mGameExitButton.setFillColor(sf::Color::Black);
          mGameRetryButton.setFillColor(sf::Color::White);
     }

     if (retryButtonPressed)
     {
          //Play state
          mContext->mStates->Add(std::make_unique<GamePlay>(mContext), true);
     }

     else if (exitButtonPressed)
     {
          mContext->mWindow->close();
     }
}

void GameOver::Draw()
{
     mContext->mWindow->clear(sf::Color::Yellow);

     //Draw to the window
     mContext->mWindow->draw(mGameOverTitle);
     mContext->mWindow->draw(mGameRetryButton);
     mContext->mWindow->draw(mGameExitButton);

     mContext->mWindow->display();
}