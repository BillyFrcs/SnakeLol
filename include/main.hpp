#pragma once

#include "Game.hpp"

void RunGame()
{
     Game *game = new Game();

     game->Run();
}