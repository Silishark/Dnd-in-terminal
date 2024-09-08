#ifndef GAME_H
#define GAME_H

#include "gamer.h"

class Game
{
public:
    static Game* instance();
    void init();
    void start();
    Gamer* gamer;
private:
    Game();
    ~Game() = default;
};

extern Game* game;

#endif // GAME_H
