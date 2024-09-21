#ifndef GAME_H
#define GAME_H

#include "gamer.h"
#include "include/map/map.h"

//Singleton Pattern
class Game
{
public:
    static Game* game;
    static Game* instance();

    void init();
    void start();
    bool isHit();
    //control the user's character
    Gamer* gamer;
    //read the map data
    Map* map;
private:
    Game();
    ~Game() = default;
};

#endif // GAME_H
