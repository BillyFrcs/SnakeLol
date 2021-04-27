#include "GamePlay.hpp"

#include <SFML/Window/Event.hpp>

GamePlay::GamePlay(std::shared_ptr<Context> &context) : mContext(context)
{
}

GamePlay::~GamePlay()
{
}

void GamePlay::Init()
{
     mContext->mAssets->addTexture(GRASS, "assets/textures/grass.png", true);
     mContext->mAssets->addTexture(FOOD, "assets/textures/food.png");
     mContext->mAssets->addTexture(WALL, "assets/textures/wall.png", true);
     mContext->mAssets->addTexture(SNAKE, "assets/textures/snake.png");

     mGrass.setTexture(mContext->mAssets->getTexture(GRASS));
     mGrass.setTextureRect(mContext->mWindow->getViewport(mContext->mWindow->getDefaultView()));

     for (auto &wall : mWalls)
     {
          wall.setTexture(mContext->mAssets->getTexture(WALL));
     }

     //x wall position
     mWalls[0].setTextureRect({0, 0, (int)mContext->mWindow->getSize().x, 16});
     mWalls[1].setTextureRect({0, 0, (int)mContext->mWindow->getSize().x, 16});
     mWalls[1].setPosition(0, mContext->mWindow->getSize().y - 16);

     //y wall position
     mWalls[2].setTextureRect({0, 0, 16, (int)mContext->mWindow->getSize().y});
     mWalls[3].setTextureRect({0, 0, 16, (int)mContext->mWindow->getSize().y});
     mWalls[3].setPosition(mContext->mWindow->getSize().x - 16, 0);

     mFood.setTexture(mContext->mAssets->getTexture(FOOD));
     mFood.setPosition(mContext->mWindow->getSize().x / 2, mContext->mWindow->getSize().y / 2);
}

void GamePlay::ProcessInput()
{
     sf::Event event;

     while (mContext->mWindow->pollEvent(event))
     {
          if (event.type == sf::Event::Closed)
          {
               mContext->mWindow->close();
          }
     }
}

void GamePlay::Update(sf::Time deltaTime)
{
}

void GamePlay::Draw()
{
     mContext->mWindow->clear();
     mContext->mWindow->draw(mGrass);

     for (auto &wall : mWalls)
     {
          mContext->mWindow->draw(wall);
     }

     mContext->mWindow->draw(mFood);
     mContext->mWindow->display();
}

void GamePlay::Pause()
{
}

void GamePlay::Start()
{
}