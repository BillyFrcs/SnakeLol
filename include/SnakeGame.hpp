#pragma once

#include "Game.hpp"

namespace RunSnakeGame
{
     void runSnakeGame()
     {
          Game *game = new Game();

          game->runGame();
     }
}
