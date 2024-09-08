#include "game.h"

Game* game = Game::instance();

Game* Game::instance()
{
    static Game instance;
    return &instance;
}

Game::Game()
{

}

void Game::init()
{

}
