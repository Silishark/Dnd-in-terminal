#ifndef GAME_H
#define GAME_H

#include "gamer.h"

class Game
{
public:
    static Game* game;
    static Game* instance();

    void init();
    void start();

    void test();
    Gamer* gamer;
private:
    Game();
    ~Game() = default;
};

#endif // GAME_H
