#include <SFML/Window/Event.hpp>

#include <cstdlib>
#include <ctime>

#include "GameOver.hpp"
#include "GamePlay.hpp"
#include "PauseGame.hpp"

GamePlay::GamePlay(std::shared_ptr<Context> context) : mContext(context), mSnakeDirection(16.f, 0.f), mElapsedTime(sf::Time::Zero), isPaused(false)
{
     mScore = 0;
     std::srand(time(nullptr));
}

GamePlay::~GamePlay()
{
}

void GamePlay::Init()
{
     //Load assets texture
     mContext->mAssets->addTexture(AssetsID::E_Background, "assets/textures/background/background_green.png", true);
     mContext->mAssets->addTexture(AssetsID::E_Food, "assets/textures/food/food.png");
     mContext->mAssets->addTexture(AssetsID::E_Wall, "assets/textures/wall/wall.png", true);
     mContext->mAssets->addTexture(AssetsID::E_Snake, "assets/textures/snake/snake.png");

     //Background grass
     mGrass.setTexture(mContext->mAssets->getTexture(AssetsID::E_Background));
     mGrass.setTextureRect(mContext->mWindow->getViewport(mContext->mWindow->getDefaultView()));

     //Wall
     for (auto &wall : mWalls)
     {
          wall.setTexture(mContext->mAssets->getTexture(AssetsID::E_Wall));
     }

     //x wall position
     mWalls[0].setTextureRect({0, 0, (int)mContext->mWindow->getSize().x, 16});
     mWalls[1].setTextureRect({0, 0, (int)mContext->mWindow->getSize().x, 16});
     mWalls[1].setPosition(0, mContext->mWindow->getSize().y - 16);

     //y wall position
     mWalls[2].setTextureRect({0, 0, 16, (int)mContext->mWindow->getSize().y});
     mWalls[3].setTextureRect({0, 0, 16, (int)mContext->mWindow->getSize().y});
     mWalls[3].setPosition(mContext->mWindow->getSize().x - 16, 0);

     //Food
     mFood.setTexture(mContext->mAssets->getTexture(E_Food));
     mFood.setPosition(mContext->mWindow->getSize().x / 2, mContext->mWindow->getSize().y / 2);

     //Snake
     mSnake.Init(mContext->mAssets->getTexture(E_Snake));

     //Score
     mContext->mAssets->addFont(E_Score_Font, "assets/fonts/Roboto-Bold.ttf");
     mScoreText.setFont(mContext->mAssets->getFont(E_Score_Font));
     //mScoreText.setString(("   Score Game") + (mScore));
     mScoreText.setCharacterSize(16);
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

          else if (event.type == sf::Event::KeyPressed)
          {
               sf::Vector2f newDirection = mSnakeDirection;

               switch (event.key.code)
               {
               case sf::Keyboard::Up:
                    newDirection = {0.f, -16.f};
                    break;

               case sf::Keyboard::Down:
                    newDirection = {0.f, 16.f};
                    break;

               case sf::Keyboard::Left:
                    newDirection = {-16.f, 0.f};
                    break;

               case sf::Keyboard::Right:
                    newDirection = {16.f, 0.f};
                    break;

               case sf::Keyboard::W:
                    newDirection = {0.f, -16.f};
                    break;

               case sf::Keyboard::A:
                    newDirection = {-16.f, 0.f};
                    break;

               case sf::Keyboard::S:
                    newDirection = {0.f, 16.f};
                    break;

               case sf::Keyboard::D:
                    newDirection = {16.f, 0.f};
                    break;

               //Pause game
               case sf::Keyboard::Escape:
                    mContext->mStates->Add(std::make_unique<PauseGame>(mContext));
                    break;

               default:
                    break;
               }

               if (std::abs(mSnakeDirection.x) != std::abs(newDirection.y) || std::abs(mSnakeDirection.y) != std::abs(newDirection.y))
               {
                    (mSnakeDirection = newDirection);
               }
          }
     }
}

void GamePlay::Update(sf::Time deltaTime)
{
     bool isFlag = true;

     if (!isPaused)
     {
          (mElapsedTime += deltaTime);

          if (mElapsedTime.asSeconds() > 0.1)
          {
               for (auto &wall : mWalls)
               {
                    //Go to GameOver states
                    if (mSnake.isOn(wall))
                    {
                         mContext->mStates->Add(std::make_unique<GameOver>(mContext), true);
                         break;
                    }
               }

               if (mSnake.isOn(mFood))
               {
                    mSnake.Grow(mSnakeDirection);

                    int x = 0, y = 0;

                    x = std::clamp<size_t>(rand() % mContext->mWindow->getSize().x, 16, mContext->mWindow->getSize().x - 4 * 16);
                    y = std::clamp<size_t>(rand() % mContext->mWindow->getSize().y, 16, mContext->mWindow->getSize().y - 4 * 16);

                    mFood.setPosition(x, y);

                    //Increase and show the score
                    mScore++;

                    mScoreText.setString("   Score Snake: " + std::to_string(mScore));
               }

               else
               {
                    mSnake.Move(mSnakeDirection);
               }

               if (mSnake.isSelfIntersecting(isFlag))
               {
                    mContext->mStates->Add(std::make_unique<GameOver>(mContext), true);
               }

               (mElapsedTime = sf::Time::Zero);
          }
     }
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
     mContext->mWindow->draw(mSnake);
     mContext->mWindow->draw(mScoreText);

     mContext->mWindow->display();
}

void GamePlay::Pause()
{
     isPaused = true;
}

void GamePlay::Start()
{
     isPaused = false;
}