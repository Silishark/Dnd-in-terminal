#ifndef MAPNODE_H
#define MAPNODE_H
#include <QString>

struct MapNode
{
    enum kind{EMPTY, TREE, FLOWER, ROAD, BUILDING};
    enum height{LOW, MID, HIGH};
    MapNode();
    int x;
    int y;
    height level;
    kind texture;
    QString path;
};

#endif // MAPNODE_H
