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
    void addMapNode(int texture, QString path, int level, int x, int y);
    MapNode* getMapNode(int x, int y);
    static Map* map;
private:
    QVector<QVector<MapNode*>> m_map;
    QPair<MapNode*, StoryNode*> m_table;
    Map();
    ~Map();
};

#endif // MAP_H
