#pragma once

#include "Game.hpp"

namespace SnakeGame
{
     void RunSnakeGame()
     {
          Game *game = new Game();

          game->runGame();
     }
}
