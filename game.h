#ifndef GAME_H
#define GAME_H

#include "gamer.h"
#include "include/map/map.h"

class Game
{
public:
    static Game* game;
    static Game* instance();

    void init();
    void start();
    bool isHit();
    Gamer* gamer;
    Map* map;
private:
    Game();
    ~Game() = default;
};

#endif // GAME_H
