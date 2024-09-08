#ifndef MAPNODE_H
#define MAPNODE_H

struct MapNode
{
    enum kind{EMPTY, TREE, FLOWER, ROAD};
    enum height{LOW, MID, HIGH};
    MapNode();
    int x;
    int y;
    height level;
    kind texture;
};

#endif // MAPNODE_H
