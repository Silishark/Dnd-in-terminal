#include "map.h"

Map* Map::map = Map::instance();

Map::Map()
{
    init();
}

Map::~Map()
{

}

Map* Map::instance()
{
    if(map != nullptr)
    {
        return map;
    }
    static Map _map;
    return &_map;
}

void Map::init()
{
    for (int i = 0; i < 96; i++)
    {
        m_map.push_back(QVector<MapNode*>());
    }
    for (int i = 0; i < 96; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            m_map[i].push_back(new MapNode());
        }
    }
}

MapNode* Map::getMapNode(int x, int y)
{
    return m_map[x][y];
}

void Map::addMapNode(int texture, QString path, int level, int x, int y)
{
    switch (texture)
    {
    case 0:
        m_map[x][y]->texture = MapNode::EMPTY;
        break;
    case 1:
        m_map[x][y]->texture = MapNode::TREE;
        break;
    case 2:
        m_map[x][y]->texture = MapNode::FLOWER;
        break;
    case 3:
        m_map[x][y]->texture = MapNode::ROAD;
        break;
    case 4:
        m_map[x][y]->texture = MapNode::BUILDING;
        break;
    default:
        m_map[x][y]->texture = MapNode::EMPTY;
        break;
    }
    switch (level)
    {
    case 0:
        m_map[x][y]->level = MapNode::LOW;
    case 1:
        m_map[x][y]->level = MapNode::MID;
    case 2:
        m_map[x][y]->level = MapNode::HIGH;
    default:
        break;
    }
    m_map[x][y]->path = path;
    m_map[x][y]->x = x;
    m_map[x][y]->y = y;
}
