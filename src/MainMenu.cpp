#include "MainMenu.hpp"

#include <SFML/Window/Event.hpp>

MainMenu::MainMenu(std::shared_ptr<Context> &context) : mContext(context), playButtonSelected(), playButtonPressed(), exitButtonSelected(), exitButtonPressed()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Init()
{
     mContext->mAssets->addFont(MAIN_FONT, "assets/fonts/MaldiniBold.ttf");

     //Game title
     mGameTitle.setFont(mContext->mAssets->getFont(MAIN_FONT));
     mGameTitle.setString("Snake 2D");
     mGameTitle.setOrigin(mGameTitle.getLocalBounds().width / 2, mGameTitle.getLocalBounds().height / 2);
     mGameTitle.setPosition(mContext->mWindow->getSize().x / 2, mContext->mWindow->getSize().y / 2 - 150.f);

     //Play game button
     mGamePlayButton.setFont(mContext->mAssets->getFont(MAIN_FONT));
     mGamePlayButton.setString("Play");
     mGamePlayButton.setOrigin(mGameTitle.getLocalBounds().width / 2, mGameTitle.getLocalBounds().height / 2);
     mGamePlayButton.setPosition(mContext->mWindow->getSize().x / 2, mContext->mWindow->getSize().y / 2 - 30.f);
     mGamePlayButton.setCharacterSize(20);

     //Exit game button
     mGameExitButton.setFont(mContext->mAssets->getFont(MAIN_FONT));
     mGameExitButton.setString("Exit");
     mGameExitButton.setOrigin(mGameTitle.getLocalBounds().width / 2, mGameTitle.getLocalBounds().height / 2);
     mGameExitButton.setPosition(mContext->mWindow->getSize().x / 2, mContext->mWindow->getSize().y / 2 + 20.f);
     mGamePlayButton.setCharacterSize(20);
}

void MainMenu::ProcessInput()
{
     sf::Event event;

     while (mContext->mWindow->pollEvent(event))
     {
          if (event.type == sf::Event::Closed)
          {
               mContext->mWindow->close();
          }

          if (event.type == sf::Event::KeyPressed)
          {
               switch (event.key.code)
               {
                    //Keyboard control
               case sf::Keyboard::Up:
               {
                    if (!playButtonSelected)
                    {
                         playButtonSelected = true;
                         exitButtonSelected = false;
                    }
                    break;
               }

               case sf::Keyboard::Down:
               {
                    if (!exitButtonSelected)
                    {
                         playButtonSelected = false;
                         exitButtonSelected = true;
                    }
                    break;
               }

               case sf::Keyboard::Return:
               {
                    playButtonPressed = false;
                    exitButtonPressed = false;

                    if (playButtonSelected)
                    {
                         playButtonPressed = true;
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

void MainMenu::Update(sf::Time deltaTime)
{
     if (playButtonSelected)
     {
          mGamePlayButton.setFillColor(sf::Color::Magenta);
          mGameExitButton.setFillColor(sf::Color::White);
     }

     else
     {
          mGameExitButton.setFillColor(sf::Color::Magenta);
          mGamePlayButton.setFillColor(sf::Color::White);
     }

     if (playButtonPressed)
     {
          //Play state
     }

     if (exitButtonPressed)
     {
          mContext->mWindow->close();
     }
}

void MainMenu::Draw()
{
     mContext->mWindow->clear(sf::Color::Blue);

     //Draw to the window
     mContext->mWindow->draw(mGameTitle);
     mContext->mWindow->draw(mGamePlayButton);
     mContext->mWindow->draw(mGameExitButton);

     mContext->mWindow->display();
}