#ifndef MAP_H
#define MAP_H

#include <QVector>
#include "include/map/mapnode.h"
#include "include/story/storynode.h"

class Map
{
public:
    static Map* instance();
    void init();
private:
    void rand();
private:
    QVector<QVector<MapNode*>> map;
    QPair<MapNode*, StoryNode*> table;
    Map();
    ~Map();
};

#endif // MAP_H
