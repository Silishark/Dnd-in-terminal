#include "game.h"
#include "include/game/gamer.h"

Game* Game::game = Game::instance();

Game* Game::instance()
{
    Game* newGame = nullptr;
    if(Game::game == nullptr)
    {
        newGame = new Game();
        newGame->gamer = new Gamer();
    }
    return newGame;
}

Game::Game()
{

}

void Game::init()
{

}

void Game::start()
{

}

void Game::test()
{
    qDebug() << "Game test";
}


