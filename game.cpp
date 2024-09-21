#include "game.h"
#include "include/game/gamer.h"
#define Dt 0.1
Game* Game::game = Game::instance();

Game* Game::instance()
{
    Game* newGame = nullptr;
    if(Game::game == nullptr)
    {
        newGame = new Game();
        newGame->gamer = new Gamer();
        newGame->map = Map::instance();
        return newGame;
    }
    else
    {
        return Game::game;
    }

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

bool Game::isHit()
{
    if(map->getMapNode(gamer->m_x + gamer->m_velocity * Dt,gamer->m_y + gamer->m_velocity * Dt)->texture != MapNode::ROAD ||
        map->getMapNode(gamer->m_x + gamer->m_velocity * Dt,gamer->m_y + gamer->m_velocity * Dt)->texture != MapNode::BUILDING)
    {
        return false;
    }
    return true;
}

