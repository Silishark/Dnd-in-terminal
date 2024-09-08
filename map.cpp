#include "map.h"

Map::Map()
{

}

Map::~Map()
{

}

Map* Map::instance()
{
    static Map map;
    return &map;
}

void Map::init()
{
    QVector<MapNode*> row;
    for (int i = 0; i < 5; i++)
    {
        row.push_back(new MapNode());
    }
    map.push_back(row);
}
